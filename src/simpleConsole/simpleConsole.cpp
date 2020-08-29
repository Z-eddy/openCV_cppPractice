#include<vector>
#include<iostream>
#include "opencv2/opencv.hpp"
using std::vector;
using std::cout;
using std::endl;
using std::ends;

int main()
{
	auto src{ cv::imread("E:/practice/openCV/material/images/hand.jpg").getUMat(cv::ACCESS_FAST) };
	cv::imshow("original", src);
	//cv::UMat canny;
	//cv::Canny(src, canny, 80, 160);
	cv::UMat gray;
	cv::cvtColor(src, gray, cv::COLOR_BGR2GRAY);
	cv::UMat bin;
	cv::threshold(gray, bin, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);

	auto k{ cv::getStructuringElement(cv::MORPH_RECT,{3,3}).getUMat(cv::ACCESS_FAST) };
	cv::UMat morphy;
	cv::morphologyEx(bin, morphy, cv::MORPH_OPEN, k);
	//cv::imshow("binary",morphy);

	vector<cv::UMat> contours;
	cv::findContours(morphy, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
	for (const auto&item : contours) {//对于每一个轮廓
		vector<cv::Point> ve;
		cv::convexHull(item, ve);
		if(!cv::isContourConvex(item)){//如果不是凸包轮廓则返回
			//continue;//为啥每个都不是凸包??
		}
		for (auto beg{ ve.cbegin() }; beg != ve.cend();++beg) {//凸包轮廓
			cv::circle(src, *beg, 4, { 255,0,0}, 2);
			auto nextPoint = beg == ve.cend() - 1 ? ve.cbegin() : beg + 1;//如果是最后一个点则连接第一个点
			cv::line(src, *beg, *nextPoint, { 0,0,255 }, 2);
		}
	}
	cv::imshow("dst", src);

	cv::waitKey(0);
}