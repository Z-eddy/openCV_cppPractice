#include "opencv2/opencv.hpp"

int main()
{
	auto src{ cv::imread("images/dog.jpg").getUMat(cv::ACCESS_RW) };
	cv::imshow("original", src);
	
	cv::UMat pyrDownDst;
	cv::pyrDown(src, pyrDownDst);//高斯金字塔reduce
	cv::imshow("pyrDownDst", pyrDownDst);

	cv::UMat pyrUpDst;
	cv::pyrUp(pyrDownDst, pyrUpDst);//高斯金字塔expand
	cv::imshow("pyrUpDst", pyrUpDst);

	cv::waitKey(0);
}