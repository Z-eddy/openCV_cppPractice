#include<iostream>
#include<string>
#include "opencv2/opencv.hpp"
using std::cout;
using std::endl;
using std::ends;
using std::string;

int main()
{
	//创建黄色方块
	cv::Mat yelloBlock{ cv::Mat::zeros(cv::Size{400,400 }, CV_8UC3) };//8位unsigned char的channel 3通道数据
	cv::Rect yelloRect{100,100,110,110};
	auto yRec{ yelloBlock(yelloRect) };//获得黄色方块的区域Mat
	yRec = cv::Scalar{ 0,255,255 };//返回rect区域内的Mat,指定Scalar标量
	cv::imshow("yelloBlock", yelloBlock);
	//创建红色方块
	cv::Mat redBlock{ cv::Mat::zeros(cv::Size{400,400},CV_8UC3) };
	cv::Rect redRect{ 150,150,100,100 };
	auto rRec{ redBlock(redRect) };//红色方块区
	rRec = cv::Scalar{ 0,0,255 };
	cv::imshow("redBlock", redBlock);

	cv::Mat resultBlock{ cv::Mat::zeros({400,400},CV_8UC3) };
	//and
	cv::bitwise_and(yelloBlock, redBlock, resultBlock);
	imshow("andBlock", resultBlock);
	//or
	cv::bitwise_or(yelloBlock, redBlock, resultBlock);
	imshow("orBlock", resultBlock);
	//xor
	cv::bitwise_xor(yelloBlock, redBlock, resultBlock);
	imshow("xor", resultBlock);
	//not
	string fileName{ "./images/dog.jpg" };
	auto src{ cv::imread(fileName) };
	cv::bitwise_not(src, src);
	imshow("not", src);

	cv::waitKey(0);
}