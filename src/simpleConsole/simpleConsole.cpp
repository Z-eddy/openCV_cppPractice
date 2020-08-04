#include "opencv2/opencv.hpp"

int main()
{
	auto src{ cv::imread("images/dog.jpg") };
	cv::imshow("origianl", src);
	cv::Mat temp0, temp1, dst;
	cv::pyrDown(src, temp0);//先reduce
	cv::pyrUp(temp0, temp1, src.size());//然后expand
	cv::subtract(src, temp1, temp0);//计算拉普拉斯金字塔
	cv::imshow("laplacian pyramid", temp0);
	cv::imshow("expand", temp1);
	cv::add(temp1, temp0, dst);//再叠加expand与Laplacian
	cv::imshow("reverse to original", dst);//复原图

	cv::waitKey(0);
}