#include<iostream>
#include<string>
#include<opencv2/opencv.hpp>
using std::cout;
using std::endl;
using std::ends;
using std::string;

int main()
{
	string pathDir{ "F:/Code/openCV/opencv/sources/samples/data/" };
	string img0{ pathDir + "WindowsLogo.jpg" };
	string img1{ pathDir + "LinuxLogo.jpg" };
	cv::Mat src0{ cv::imread(img0) };
	cv::imshow("img0", src0);
	cv::Mat src1{ cv::imread(img1) };
	cv::imshow("img1",src1);

	cv::Mat result{ cv::Mat::zeros(src0.size(),src0.type()) };
	cv::add(src0, src1, result);
	cv::imshow("add", result);

	cv::subtract(src0, src1, result);
	cv::imshow("subtract",result);

	cv::multiply(src0, src1, result);
	cv::imshow("multiply", result);

	cv::divide(src0, src1, result);
	cv::imshow("divide",result);

	cv::waitKey(0);
}