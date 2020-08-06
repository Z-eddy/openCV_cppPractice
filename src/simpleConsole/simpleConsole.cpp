#include "opencv2/opencv.hpp"

int main()
{
	auto src{ cv::imread("C:/Users/Zr/Desktop/temp/test.png") };
	cv::cvtColor(src, src, cv::COLOR_BGR2GRAY);

	cv::Mat dst;

	cv::threshold(src, dst, 127, 255, cv::THRESH_BINARY);//按照127的阈值进行分割,大于为1，小于为0
	cv::imshow("THRESH_BINARY", dst);

	cv::threshold(src, dst, 127, 255, cv::THRESH_BINARY_INV);//按照127的阈值进行分割,大于为0，小于为1
	cv::imshow("THRESH_BINARY_INV", dst);

	cv::threshold(src, dst, 127, 255, cv::THRESH_TRUNC);//大于127的都成为127
	cv::imshow("THRESH_TRUNC", dst);

	cv::threshold(src, dst, 127, 255, cv::THRESH_TOZERO);//小于127的都为0
	cv::imshow("THRESH_TOZERO", dst);

	cv::threshold(src, dst, 127, 255, cv::THRESH_TOZERO_INV);//大于127的都为0
	cv::imshow("THRESH_TOZERO_INV", dst);

	cv::waitKey(0);
}