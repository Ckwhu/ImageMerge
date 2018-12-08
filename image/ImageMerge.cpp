#include"ImageMerge.h"

using namespace std;

ImageMerge::ImageMerge()
{
}

ImageMerge::~ImageMerge()
{
}
//̽��������
vector<vector<Point2f>> ImageMerge::detectKeyPoint(Mat image1, Mat image2) {
	Ptr<Feature2D> f2d = xfeatures2d::SURF::create();

	//��ȡ������
	vector<KeyPoint> keypoints_1, keypoints_2;
	f2d->detect(image1, keypoints_1);
	f2d->detect(image2, keypoints_2);

	//������������Ϊ�±ߵ�������ƥ����׼�� 
	Mat descriptors_1, descriptors_2;
	f2d->compute(image1, keypoints_1, descriptors_1);
	f2d->compute(image2, keypoints_2, descriptors_2);

	FlannBasedMatcher matcher;
	vector<vector<DMatch>> knnMatches;
	vector<vector<DMatch> > matchePoints;
	vector<DMatch> GoodMatchePoints;
	vector<Mat> train_desc(1, descriptors_1);

	matcher.add(train_desc);
	matcher.train();
	matcher.knnMatch(descriptors_2, matchePoints, 2);

	cout << "total match points: " << matchePoints.size() << endl;

	// Lowe's algorithm,��ȡ����ƥ���
	for (int i = 0; i < matchePoints.size(); i++)
	{
		if (matchePoints[i][0].distance < 0.7 * matchePoints[i][1].distance)
		{
			GoodMatchePoints.push_back(matchePoints[i][0]);
		}
	}

	Mat first_match;
	drawMatches(image2, keypoints_2, image1, keypoints_1, GoodMatchePoints, first_match);
	this->FeatureMatchImage = first_match;

	//namedWindow("ƥ�䴰��", 0);
	//cvResizeWindow("ƥ�䴰��", 500, 500); //����һ��500*500��С�Ĵ���
	//imshow("ƥ�䴰��", first_match);

	vector<vector<Point2f>> imagePoints;
	vector<Point2f> imagePoints1, imagePoints2;

	for (int i = 0; i < GoodMatchePoints.size(); i++)
	{
		imagePoints2.push_back(keypoints_2[GoodMatchePoints[i].queryIdx].pt);
		imagePoints1.push_back(keypoints_1[GoodMatchePoints[i].trainIdx].pt);
	}
	imagePoints.push_back(imagePoints1);
	imagePoints.push_back(imagePoints2);
	waitKey();
	return imagePoints;
}

void ImageMerge::CalcCorners(const Mat& H, const Mat& src)
{
	double v2[] = { 0, 0, 1 };//���Ͻ�
	double v1[3];//�任�������ֵ
	Mat V2 = Mat(3, 1, CV_64FC1, v2);  //������
	Mat V1 = Mat(3, 1, CV_64FC1, v1);  //������

	V1 = H * V2;
	//���Ͻ�(0,0,1)
	cout << "V2: " << V2 << endl;
	cout << "V1: " << V1 << endl;
	corners.left_top.x = v1[0] / v1[2];
	corners.left_top.y = v1[1] / v1[2];

	//���½�(0,src.rows,1)
	v2[0] = 0;
	v2[1] = src.rows;
	v2[2] = 1;
	V2 = Mat(3, 1, CV_64FC1, v2);  //������
	V1 = Mat(3, 1, CV_64FC1, v1);  //������
	V1 = H * V2;
	corners.left_bottom.x = v1[0] / v1[2];
	corners.left_bottom.y = v1[1] / v1[2];

	//���Ͻ�(src.cols,0,1)
	v2[0] = src.cols;
	v2[1] = 0;
	v2[2] = 1;
	V2 = Mat(3, 1, CV_64FC1, v2);  //������
	V1 = Mat(3, 1, CV_64FC1, v1);  //������
	V1 = H * V2;
	corners.right_top.x = v1[0] / v1[2];
	corners.right_top.y = v1[1] / v1[2];

	//���½�(src.cols,src.rows,1)
	v2[0] = src.cols;
	v2[1] = src.rows;
	v2[2] = 1;
	V2 = Mat(3, 1, CV_64FC1, v2);  //������
	V1 = Mat(3, 1, CV_64FC1, v1);  //������
	V1 = H * V2;
	corners.right_bottom.x = v1[0] / v1[2];
	corners.right_bottom.y = v1[1] / v1[2];

}

//ͼ����׼
void ImageMerge::registrat(Mat image1, vector<Point2f> imagePoints1, Mat image2, vector<Point2f> imagePoints2) {
	//��ȡͼ��1��ͼ��2��ͶӰӳ����� �ߴ�Ϊ3*3  
	Mat homo = findHomography(imagePoints1, imagePoints2, CV_RANSAC);
	cout << "�任����Ϊ��\n" << homo << endl << endl; //���ӳ�����

	//������׼ͼ���ĸ���������
	CalcCorners(homo, image1);
	cout << "left_top:" << corners.left_top << endl;
	cout << "left_bottom:" << corners.left_bottom << endl;
	cout << "right_top:" << corners.right_top << endl;
	cout << "right_bottom:" << corners.right_bottom << endl;

	//ͼ����׼  
	Mat imageTransform1, imageTransform2;
	warpPerspective(image1, imageTransform1, homo, Size(MAX(corners.right_top.x, corners.right_bottom.x), image2.rows));
	//imshow("ֱ�Ӿ���͸�Ӿ���任", imageTransform1);
	//imwrite("trans1.jpg", imageTransform1);

	//����ƴ�Ӻ��ͼ,����ǰ����ͼ�Ĵ�С
	int dst_width = imageTransform1.cols;  //ȡ���ҵ�ĳ���Ϊƴ��ͼ�ĳ���
	int dst_height = image2.rows;

	Mat dst(dst_height, dst_width, CV_8UC3);
	dst.setTo(0);

	imageTransform1.copyTo(dst(Rect(0, 0, imageTransform1.cols, imageTransform1.rows)));
	image2.copyTo(dst(Rect(0, 0, image2.cols, image2.rows)));

	//imshow("b_dst", dst);

	OptimizeSeam(image2, imageTransform1, dst);

	//imshow("dst", dst);
	this->mergedImage = dst;
	//imwrite("dst.jpg", dst);

	waitKey();
}

//�Ż���ͼ�����Ӵ���ʹ��ƴ����Ȼ
void ImageMerge::OptimizeSeam(Mat& img1, Mat& trans, Mat& dst)
{
	int start = MIN(corners.left_top.x, corners.left_bottom.x);//��ʼλ�ã����ص��������߽�  

	double processWidth = img1.cols - start;//�ص�����Ŀ��  
	int rows = dst.rows;
	int cols = img1.cols; //ע�⣬������*ͨ����
	double alpha = 1;//img1�����ص�Ȩ��  
	for (int i = 0; i < rows; i++)
	{
		uchar* p = img1.ptr<uchar>(i);  //��ȡ��i�е��׵�ַ
		uchar* t = trans.ptr<uchar>(i);
		uchar* d = dst.ptr<uchar>(i);
		for (int j = start; j < cols; j++)
		{
			//�������ͼ��trans�������صĺڵ㣬����ȫ����img1�е�����
			if (t[j * 3] == 0 && t[j * 3 + 1] == 0 && t[j * 3 + 2] == 0)
			{
				alpha = 1;
			}
			else
			{
				//img1�����ص�Ȩ�أ��뵱ǰ�������ص�������߽�ľ�������ȣ�ʵ��֤�������ַ���ȷʵ��  
				alpha = (processWidth - (j - start)) / processWidth;
			}

			d[j * 3] = p[j * 3] * alpha + t[j * 3] * (1 - alpha);
			d[j * 3 + 1] = p[j * 3 + 1] * alpha + t[j * 3 + 1] * (1 - alpha);
			d[j * 3 + 2] = p[j * 3 + 2] * alpha + t[j * 3 + 2] * (1 - alpha);

		}
	}

}