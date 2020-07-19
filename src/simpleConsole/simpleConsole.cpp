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
	cv::Mat dst;
	cv::cvtColor(src, dst, cv::COLOR_BGR2HSV);//先转换hsv图
	cv::Mat mask;
	cv::inRange(dst, cv::Scalar{ 36,43,46 }, cv::Scalar{ 99,255,255 }, mask);//获得mssk掩膜
	cv::bitwise_not(mask, mask);//反转mask,人白背景黑,人255,背景0
	cv::imshow("mask", mask);//显示mask
	cv::Mat person;
	cv::Mat temp{ cv::Mat::zeros(src.size(),src.type()) };
	temp.setTo(cv::Scalar{ 255,255,255 });
	cv::bitwise_and(src,temp, person, mask);//按照mask有效区内,src与temp做and计算
	cv::imshow("result", person);

	cv::waitKey(0);
}
