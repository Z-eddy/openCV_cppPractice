#include<vector>
#include "opencv2/opencv.hpp"
using std::vector;

int main()
{
	auto src{ cv::imread("E:/practice/openCV/material/images/coins.jpg").getUMat(cv::ACCESS_FAST) };
	cv::UMat temp0;
	cv::cvtColor(src, temp0, cv::COLOR_BGR2GRAY);
	cv::UMat gaussian;
	cv::GaussianBlur(temp0, gaussian, { 9,9 }, 2, 2);
	vector<cv::Vec3f>ve;//储存霍夫圆的结果
	/*
	dp:检测内侧圆心的累加器图像的分辨率于输入图像之比的倒数，如dp=1，累加器和输入图像具有相同的分辨率，如果dp=2，累计器便有输入图像一半那么大的宽度和高度
	*/
	cv::HoughCircles(gaussian, ve, cv::HOUGH_GRADIENT, 2, 10, 100, 100, 20, 100);//(input,output,梯度法,dp,圆心之间的最小距离,梯度值阈值,累加值阈值,最小半径,最大半径)
	for (const auto&item : ve) {
		cv::Point center(item[0], item[1]);
		auto r{ item[2] };
		cv::circle(src, center, r, { 0,0,255 });
		cv::circle(src, center, 3, { 255,0,255 },-1);
	}
	cv::imshow("dst", src);

	cv::waitKey(0);
}