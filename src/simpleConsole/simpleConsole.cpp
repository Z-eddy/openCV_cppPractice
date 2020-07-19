#include<string>
#include<vector>
#include<iostream>
#include "opencv2/opencv.hpp"
using std::cout;
using std::endl;
using std::ends;
using std::string;
using std::vector;

int main()
{
	cv::Mat src{ cv::imread("G:/Practice/openCV/images/TinyGreen.PNG") };
	cv::Mat hsv;
	cv::cvtColor(src, hsv, cv::COLOR_BGR2HSV);//先转换hsv图
	cv::Mat origiMask;//掩膜
	cv::inRange(hsv, cv::Scalar{ 36,43,46 }, cv::Scalar{ 99,255,255 }, origiMask);//获得掩膜,人黑背景白
	
	cv::Mat blue{ cv::Mat{cv::Mat::zeros(src.size(),src.type())}.setTo(cv::Scalar{255,0,0}) };//蓝色背景
	cv::bitwise_and(blue, blue,src, origiMask);//origiMask的有效区(背景区)内,blue与blue做and计算后,替换src中对应的像素
	cv::imshow("bluePerson",src);
	cv::waitKey(0);
}
