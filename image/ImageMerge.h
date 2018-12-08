#pragma once
#include <opencv2/opencv.hpp>
#include "highgui/highgui.hpp"    
#include "opencv2/features2d/features2d.hpp"  
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc.hpp"
#include <opencv2/imgproc/types_c.h> 
#include<opencv2/xfeatures2d/nonfree.hpp>
#include<iostream>
#include<vector>

using namespace std;
using namespace cv;
using namespace cv::xfeatures2d;

typedef struct
{
	Point2f left_top;
	Point2f left_bottom;
	Point2f right_top;
	Point2f right_bottom;
}four_corners_t;

class ImageMerge {
public:
	Mat leftImage;
	Mat rightImage;
	Mat cuttedImage;
	Mat FeatureMatchImage;
	Mat mergedImage;
	four_corners_t corners;
	vector<vector<Point2f>> imagePoints;//ƥ���������
	//ImageMerge(Mat * leftImage, Mat * rightImage, Mat * cuttedImage, Mat * FeatureMatchImage, Mat * mergedImage);
	ImageMerge();
	~ImageMerge();
	void OptimizeSeam(Mat& img1, Mat& trans, Mat& dst);//�Ż�ƴ��
	void registrat(Mat image1, vector<Point2f> imagePoints1, Mat image2, vector<Point2f> imagePoints2);//ͼ����׼
	vector<vector<Point2f>> detectKeyPoint(Mat image1, Mat image2);//���������
	void CalcCorners(const Mat& H, const Mat& src);//����ǵ�

};
