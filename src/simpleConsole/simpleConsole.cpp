#include<iostream>
#include "opencv2/opencv.hpp"
using std::cout;
using std::endl;
using std::ends;
int main()
{
	auto src{ cv::imread("images/dog.jpg") };
	cv::cvtColor(src, src, cv::COLOR_BGR2GRAY);
	cv::Mat dst;
	auto v{ cv::threshold(src, dst, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU) };
	cout << v << endl;
	cv::imshow("dst", dst);

	cv::waitKey(0);
}
