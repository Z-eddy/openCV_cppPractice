#include "opencv2/opencv.hpp"

int main()
{
	auto src{ cv::imread("images/dog.jpg") };
	if (src.empty()) {
		return 0;
	}
	cv::cuda::GpuMat dst;
	src.copyTo(dst);
	cv::imshow("original", src);
	cv::fastNlMeansDenoisingColored(dst,dst);
	cv::imshow("非局部均值去噪",dst);
	cv::waitKey(0);
}