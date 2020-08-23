#include<vector>
#include<iostream>
#include "opencv2/opencv.hpp"
using std::endl;
using std::ends;
using std::cout;
using std::vector;

int main()
{
	auto src{ cv::imread("E:/practice/openCV/material/images/contours.png") };
	cv::Mat canny;
	cv::Canny(src, canny, 80, 160);//轮廓勾勒
	vector<vector<cv::Point>> contours;
	cv::findContours(canny, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
	for (auto item : contours) {
		auto rotatedRect{ cv::minAreaRect(item) };
		auto center{ rotatedRect.center };//获得圆心
		vector<cv::Point2f>curve;
		cv::approxPolyDP(item, curve, 4, true);
		auto size{ curve.size() };//每条曲线的点数
		switch (size)
		{
		case 3:
			cv::putText(src, "Triangle", center, cv::FONT_ITALIC, 0.8, { 0,0,255 });
			break;
		case 4:
			cv::putText(src, "Rectangle", center, cv::FONT_ITALIC, 0.8, { 0,0,255 });
			break;
		case 6:
			cv::putText(src, "Polygon", center, cv::FONT_ITALIC, 0.8, { 0,0,255 });
			break;
		default:
			break;
		}
		if (size < 3 || size > 6 && size < 10) {
			cv::putText(src, "Unknown", center, cv::FONT_ITALIC, 0.8, { 0,0,255 });
		}
		else if (size >= 10) {
			cv::putText(src, "Cycle", center, cv::FONT_ITALIC, 0.8, { 0,0,255 });
		}
	}
	cv::imshow("dst", src);

	cv::waitKey(0);
}