#include<vector>
#include "opencv2/opencv.hpp"
using std::vector;

int main()
{
	auto src{ cv::imread("E:/practice/openCV/material/images/zhifang_ball.png") };
	cv::Mat canny;
	cv::Canny(src, canny, 100, 200);
	cv::imshow("canny", canny);
	cv::Mat dilate;
	auto k{ cv::getStructuringElement(cv::MORPH_RECT,{3,3}) };
	cv::dilate(canny, dilate, k);
	vector<vector<cv::Point>> contours;
	cv::findContours(dilate, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
	for (int i{ 0 }; i != contours.size(); ++i) {
		auto area{ cv::contourArea(contours.at(i)) };//计算面积
		auto length{ cv::arcLength(contours.at(i),true) };//计算弧长
		if (area < 100 || length < 100) {//如果面积或者弧长<100则忽略
			continue;
		}
		auto rotateRect{ cv::minAreaRect(contours.at(i)) };
		cv::Point2f theRect[4];
		rotateRect.points(theRect);
		for (int i{ 0 }; i != 4; ++i) {
			cv::line(src, theRect[i % 4], theRect[(i + 1) % 4], { 0,0,255 });
		}
		cv::circle(src, rotateRect.center, 2, { 255,0,0 }, -1);
	}
	cv::imshow("dst", src);

	cv::waitKey(0);
}
