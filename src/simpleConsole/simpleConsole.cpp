#include "opencv2/opencv.hpp"
#include<iostream>
using std::cout;

int main()
{
	auto src{ cv::imread("images/dog.jpg").getUMat(cv::ACCESS_RW) };
	cv::UMat sumMat;
	cv::integral(src, sumMat);//计算积分
	auto nums{ sumMat(cv::Rect{ {10,10},cv::Size{10,10} }) };
	auto ve{ nums.getMat(cv::ACCESS_RW).at<cv::Vec3i>(5, 5) };
	for (int i{ 0 }; i != ve.channels; ++i) {
		cout << ve[i] << '\n';
	}
	cv::waitKey(0);
}
