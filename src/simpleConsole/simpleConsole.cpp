#include<iostream>
#include "opencv2/opencv.hpp"
using std::cout;
using std::endl;
using std::ends;
int main()
{
	cv::Mat src{ cv::imread("./images/行走天涯柴犬.jpg") };
	cv::namedWindow("pic", cv::WINDOW_AUTOSIZE);
	cv::imshow("pic", src);
	cv::waitKey(0);
}