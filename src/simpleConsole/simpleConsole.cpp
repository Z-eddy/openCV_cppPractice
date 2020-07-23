#include "opencv2/opencv.hpp"

int main()
{
	auto src{ cv::imread("E:/openCV/opencv_tutorial/data/images/sp_noise.png") };
	cv::imshow("origianl", src);
	cv::medianBlur(src, src, 3);
	cv::imshow("中值滤波", src);
	cv::waitKey(0);
}