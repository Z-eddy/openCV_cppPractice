#include "opencv2/opencv.hpp"
#include<iostream>
using std::cout;

int main()
{
	auto src{ cv::imread("E:/openCV/opencv_tutorial/data/images/example.png").getUMat(cv::ACCESS_RW) };
	cv::imshow("original", src);
	cv::UMat dst;
	//src,dst,边缘保留滤波算法类型,空间sigma 0~200,颜色sigma 0~1.0
	cv::edgePreservingFilter(src,dst,1,60,0.4);
	cv::imshow("edgePreservingFilter",dst);
	cv::waitKey(0);
}
