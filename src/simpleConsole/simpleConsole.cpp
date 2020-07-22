#include<string>
#include "opencv2/opencv.hpp"
using std::string;

int main()
{
	auto src{ cv::imread("images/dog.jpg") };
	string winTitle{ "demo" };
	cv::namedWindow(winTitle,cv::WINDOW_AUTOSIZE);
	cv::imshow(winTitle, src);
	cv::waitKey(0);

	cv::blur(src, src, { 3,3 });//3*3卷积核/掩膜
	cv::imshow("卷积模糊后图像", src);
	cv::waitKey(0);
}