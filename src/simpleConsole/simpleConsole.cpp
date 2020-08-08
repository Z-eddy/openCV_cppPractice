#include "opencv2/opencv.hpp"

int main()
{
	auto src{ cv::imread("images/dog.jpg") };
	cv::Mat gray;
	cv::cvtColor(src, gray, cv::COLOR_BGR2GRAY);
	cv::Mat dst;
	//自适应光照不均与阈值算法,最后两个参数,开窗大小,C一般是10左右,影响过滤效果,低保留的黑色多,越高越少
	cv::adaptiveThreshold(gray, dst, 255, cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY, 25, 8);
	cv::imshow("adaptiveThreshold", dst);

	cv::waitKey(0);
}