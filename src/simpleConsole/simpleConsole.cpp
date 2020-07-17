#include<string>
#include<iostream>
#include "opencv2/opencv.hpp"
using std::string;
using std::endl;
using std::ends;
using std::cout;

int main()
{
	auto src{ cv::imread("./images/dog.jpg") };
	if (src.empty()) {
		cout << "error" << endl;
		return 0;
	}
	cv::imshow("original", src);

	cv::Mat dst;

	cv::flip(src, dst, 0);
	cv::imshow("x_flip", dst);

	cv::flip(src, dst, 1);
	cv::imshow("y_flip", dst);

	cv::flip(src, dst, -1);
	cv::imshow("xy_flip", dst);

	cv::waitKey(0);
}