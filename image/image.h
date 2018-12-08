#pragma once
#include <opencv2/opencv.hpp>

using namespace cv;

class Img {
private:
	Mat image;
	Mat grayImage;
public:
	Img(Mat image);
	Mat image2gray(Mat image);
	Mat getImage();
	Mat getGrayImage();
};

Img::Img(Mat image) {
	this->image = image;
	//this->grayImage = image2gray(image);
}

Mat Img::image2gray(Mat image) {
	Mat image1;
	cvtColor(image1, image, CV_BGR2GRAY);
	return image1;
}

Mat Img::getImage()
{
	return this->image;
}

Mat Img::getGrayImage()
{
	return this->grayImage;
}

