#include "opencv2/opencv.hpp"

int main()
{
	auto srcM{ cv::imread("images/dog.jpg") };
	cv::UMat src;
	srcM.copyTo(src);
	cv::imshow("original", src);
	cv::waitKey(0);
	cv::UMat dst;
	//0表示图片大小为自身,180是过滤的边缘颜色差,5是高斯的西格玛参数,越大参与运算的像素越多、运算越慢
	cv::bilateralFilter(src, dst, 0, 180, 5);
	cv::imshow("bilateralFilter",dst);
	cv::waitKey(0);
}