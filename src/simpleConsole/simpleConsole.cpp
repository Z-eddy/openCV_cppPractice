#include "opencv2/opencv.hpp"

int main()
{
	auto src{ cv::imread("images/dog.jpg").getUMat(cv::ACCESS_RW) };
	cv::imshow("original", src);
	cv::UMat gaussian,dst;
	cv::GaussianBlur(src, gaussian, { 0,0 }, 25);
	cv::addWeighted(src, 1.5, gaussian, -0.5, 0, dst);//权重叠加,src*1.5-0.5*gaussian
	cv::imshow("USM", dst);

	cv::waitKey(0);
}