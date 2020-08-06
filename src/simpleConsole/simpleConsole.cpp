#include "opencv2/opencv.hpp"

int main()
{
	auto src{ cv::imread("images/dog.jpg") };
	cv::imshow("original", src);
	cv::cvtColor(src, src, cv::COLOR_BGR2GRAY);
	auto row{ src.rows }, col{ src.cols };
	unsigned char val{ 127 };
	for (int i{ 0 }; i != row; ++i) {
		auto p{ src.ptr(i) };
		for (int j{ 0 }; j != col; ++p, ++j) {
			if (*p > val) {
				*p = 255;
			}
			else {
				*p = 0;
			}
		}
	}
	cv::imshow("dst", src);

	cv::waitKey(0);
}