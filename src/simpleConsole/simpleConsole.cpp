#include "opencv2/opencv.hpp"
int main()
{
	auto src{ cv::imread("images/dog.jpg").getUMat(cv::ACCESS_RW) };
	cv::UMat tempDst, dst;
	//ksize为1指4领域,必须为奇数,如果为其他非1奇数则是8邻域
	cv::Laplacian(src, tempDst, CV_32F, 1, 1, 150);
	cv::convertScaleAbs(tempDst, dst);
	cv::imshow("Laplacian", dst);

	cv::waitKey(0);
}