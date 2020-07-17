#include<iostream>
#include<string>
#include "opencv2/opencv.hpp"
using std::endl;
using std::ends;
using std::cout;
using std::string;

int main()
{
	auto src{ cv::imread("images/dog.jpg") };
	if (src.empty()) {
		cout << "can't open file" << endl;
	}
	cv::imshow("original", src);

	cv::Mat dst;
	cv::Size size(src.rows * 0.5, src.cols * 0.5);

	cv::resize(src, dst, { 0,0 }, 2, 2, cv::INTER_NEAREST);//Size为0时看后面的缩放比
	cv::imshow("NEARST", dst);

	cv::resize(src, dst, size, 0, 0, cv::INTER_LINEAR);
	cv::imshow("LINEAR", dst);

	cv::resize(src, dst, size, 0, 0, cv::INTER_CUBIC);
	cv::imshow("CUBIC", dst);

	cv::resize(src, dst, size, 0, 0, cv::INTER_LANCZOS4);
	cv::imshow("LANCZONS", dst);

	cv::waitKey(0);
}