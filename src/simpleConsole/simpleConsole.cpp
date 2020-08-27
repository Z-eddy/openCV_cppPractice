#include<vector>
#include"opencv2/opencv.hpp"
using std::vector;

int main()
{
	auto src{ cv::imread("E:/practice/openCV/material/images/stuff.jpg").getUMat(cv::ACCESS_FAST) };
	cv::UMat canny;
	cv::Canny(src, canny, 80, 160);
	auto k{ cv::getStructuringElement(cv::MORPH_RECT,{3,3}) };
	cv::UMat dilate;
	cv::dilate(canny, dilate, k);

	vector<cv::UMat>contours;
	cv::findContours(dilate, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
	for (auto item : contours) {
		auto rotatedRect{ cv::fitEllipse(item) };
		cv::ellipse(src, rotatedRect, { 0,0,255 }, 2);
	}
	cv::imshow("dst", src);

	cv::waitKey(0);
}