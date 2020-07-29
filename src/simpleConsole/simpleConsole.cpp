#include "opencv2/opencv.hpp"
#include<string>
#include<iostream>
#include<vector>
using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::ends;

int main()
{
	auto src{ cv::imread("images/dog.jpg").getUMat(cv::ACCESS_RW) };
	cv::imshow("original", src);
	//算子0
	cv::Mat kernel0{ cv::Mat::ones({5,5},CV_32F) / 25.0 };//算子cpu初始化
	cv::UMat dst;
	cv::filter2D(src, dst, -1, kernel0);//gpuz中处理
	cv::imshow("kernel0", dst);
	//算子1,3*3矩阵
	cv::Mat kernel1{ { 3,3 },//C++11的初始化
		{ 0,-1,0,
		-1,5,-1,
		0,-1,0 }
	};
	cv::filter2D(src, dst, -1, kernel1);
	cv::imshow("kernel1", dst);
	//算子2,2*2矩阵
	cv::Mat kernel2{ (cv::Mat_<int>(2,2) << 1,0,0,-1) };//原始的初始化
	cv::filter2D(src, dst, CV_32F, kernel2);
	cv::UMat dstTemp;
	cv::convertScaleAbs(dst, dstTemp);
	cv::imshow("kernel2", dstTemp);

	cv::waitKey(0);
}