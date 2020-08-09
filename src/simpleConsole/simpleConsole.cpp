#include "opencv2/opencv.hpp"

int main()
{
	auto src{ cv::imread("E:/practice/openCV/material/images/coins.jpg").getUMat(cv::ACCESS_RW) };
	cv::imshow("original", src);

	cv::UMat tempDst;
	int fileter{ 3 };
	switch (fileter)
	{
	case 0://进行均值滤波后二值化
		cv::blur(src, tempDst, {3,3});
		break;
	case 1://进行高斯滤波后二值化
		cv::GaussianBlur(src, tempDst, { 3,3 }, 0);
		break;
	case 2://非局部均值去噪后二值化
		cv::fastNlMeansDenoisingColored(src, tempDst);
		break;
	case 3:
		cv::pyrMeanShiftFiltering(src, tempDst, 10, 100);
		break;
	default:
		tempDst = src;
		break;
	}
	cv::UMat grayDst;
	cv::cvtColor(tempDst, grayDst, cv::COLOR_BGR2GRAY);
	cv::UMat dst;
	cv::threshold(grayDst, dst, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);
	cv::imshow("dst", dst);

	cv::waitKey(0);
}