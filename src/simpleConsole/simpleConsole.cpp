#include<iostream>
#include<string>
#include "opencv2/opencv.hpp"
using std::string;
using std::endl;
using std::ends;
using std::cout;

int main()
{
	cv::Mat src{ cv::imread("./images/行走天涯柴犬.jpg") };
	string winTitle{ "dogPic" };
	cv::namedWindow(winTitle, cv::WINDOW_AUTOSIZE);

	//深拷贝,独立的Mat
	auto tempSrc0{ src.clone() };//复制,也可以用src.copyTo(tempSrc0)
	tempSrc0 = cv::Mat::zeros(src.size(), src.type());//黑色图片
	cv::imshow(winTitle, src);
	cv::waitKey(0);

	//浅拷贝
	auto tempSrc1{ src };//智能指针复制
	tempSrc1 = cv::Mat::zeros(src.size(), src.type());//改变了共同的源//size不同时,会成为独立的源!
	cv::imshow(winTitle, src);
	cv::waitKey(0);
}