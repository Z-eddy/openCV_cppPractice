#include<string>
#include "opencv2/opencv.hpp"
using std::string;

int main()
{
	auto src{ cv::imread("images/dog.jpg") };
	string winTitle{ "demo" };
	cv::namedWindow(winTitle,cv::WINDOW_AUTOSIZE);
	cv::imshow(winTitle, src);

	cv::GaussianBlur(src, src, { 3,3 }, 5);
	cv::imshow("卷积模糊后图像", src);//高斯卷积模糊
	cv::waitKey(0);
}