#include<iostream>
#include<string>
#include<vector>
#include "opencv2/opencv.hpp"
using std::cout;
using std::endl;
using std::ends;
using std::string;
using std::vector;

int main()
{
	cv::Mat image{ cv::imread("E:/practice/openCV/material/images/target.png") };
	cv::imshow("original",image);
	cv::Mat theModule{ cv::imread("E:/practice/openCV/material/images/sample.png") };
	cv::imshow("module",theModule);
	cv::cvtColor(image, image, cv::COLOR_BGR2HSV);
	cv::cvtColor(theModule, theModule, cv::COLOR_BGR2HSV);

	//计算直方图
	vector<cv::Mat>mVe{ theModule };
	cv::Mat roiHist;
	cv::calcHist(mVe, { 0,1 }, cv::Mat{}, roiHist, { 30,32 }, { 0,180,0,256 });
	cv::normalize(roiHist, roiHist, 255, 0, cv::NORM_MINMAX);
	//cv::resize(roiHist, roiHist, { 400,400 });

	//计算图像直方图反向投影
	vector<cv::Mat>imaVe{ image };
	cv::Mat dst;
	cv::calcBackProject(imaVe, { 0,1 }, roiHist, dst, { 0,180,0,255 }, 1);
	cv::imshow("result", dst);

	cv::waitKey(0);
}