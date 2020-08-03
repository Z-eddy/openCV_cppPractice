#include "opencv2/opencv.hpp"

int main()
{
	auto src{ cv::imread("images/dog.jpg").getUMat(cv::ACCESS_RW) };
	cv::UMat dst;
	cv::Canny(src, dst, 80, 240, 3, false);//默认的使用sobel算子计算x/y方向的inputArray,非默认的自己指定xInput,yInput
	cv::imshow("Canny边缘检测器", dst);

	cv::waitKey(0);
}