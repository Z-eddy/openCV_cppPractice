#include<iostream>
#include "opencv2/opencv.hpp"
using std::endl;
using std::ends;
using std::cout;

int main()
{
	auto src{ cv::imread("images/dog.jpg") };
	cv::imshow("original", src);
	cv::Mat tempSrc;
	cv::cvtColor(src, tempSrc, cv::COLOR_BGR2GRAY);//转化为灰度图好进行二值化
	cv::Mat dst;
	auto val{ cv::threshold(tempSrc, dst, 0, 255, cv::THRESH_BINARY | cv::THRESH_TRIANGLE) };
	cout << val << endl;
	cv::imshow("threshold_triangle", dst);

	cv::waitKey(0);
}
