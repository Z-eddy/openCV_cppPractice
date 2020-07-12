#include<iostream>
#include<string>
#include "opencv2/opencv.hpp"
using std::cout;
using std::endl;
using std::ends;
using std::string;

int main()
{
	string filePath{ "G:/Practice/openCV/images/LUT_test.PNG" };
	cv::Mat src{ cv::imread(filePath) };
	string winTitle{ "picTest" };
	cv::namedWindow(winTitle, cv::WINDOW_AUTOSIZE);
	//原图展示
	cv::imshow(winTitle, src);
	cv::waitKey(0);
	//LUT转换后
	cv::applyColorMap(src, src, cv::COLORMAP_JET);
	cv::imshow(winTitle, src);
	cv::waitKey(0);
	return 0;
}