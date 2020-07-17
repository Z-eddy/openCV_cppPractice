#include<iostream>
#include<string>
#include<vector>
#include "opencv2/opencv.hpp"
using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::ends;

int main()
{
	auto src{ cv::imread("./images/dog.jpg") };
	string winTitle{ "imgShow" };
	cv::namedWindow(winTitle, cv::WINDOW_AUTOSIZE);
	//原图显示
	cv::imshow(winTitle, src);
	cv::waitKey(0);

	//灰度图转换
	cv::cvtColor(src, src, cv::COLOR_BGR2GRAY);//此时只有1个通道
	src.convertTo(src, CV_32F);

	cv::Mat dst{ cv::Mat::zeros(src.size(),CV_32FC1) };
	//MINMAX归一化
	cv::normalize(src, dst, 1, 0, cv::NORM_MINMAX);
	dst *= 255;//此数值是估计的,过大则曝光强烈,否则黯淡
	dst.convertTo(dst, CV_8UC1);
	cv::imshow("MINMAX", dst);
	//INF归一化
	cv::normalize(src, dst, 1, 0, cv::NORM_INF);
	dst *= 255;
	dst.convertTo(dst, CV_8UC1);
	cv::imshow("INF", dst);
	//L1归一化
	cv::normalize(src, dst, 1, 0, cv::NORM_L1);
	dst *= 10000000;
	dst.convertTo(dst, CV_8UC1);
	cv::imshow("L1", dst);
	//L2归一化
	cv::normalize(src, dst, 1, 0, cv::NORM_L2);
	dst *= 10000;
	dst.convertTo(dst, CV_8UC1);
	cv::imshow("L2", dst);

	cv::waitKey(0);
}