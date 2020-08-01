#include "opencv2/opencv.hpp"
int main()
{
	auto src{ cv::imread("images/dog.jpg").getUMat(cv::ACCESS_RW) };
	cv::UMat tempGauss, tempDst, dst;
	//ksize为1指4领域,必须为奇数,如果为其他非1奇数则是8邻域
	if (true) {
		cv::GaussianBlur(src, tempGauss, { 3,3 }, 0);
		cv::Laplacian(tempGauss, tempDst, CV_32F, 1, 1, 150);
	}
	else {
		cv::Laplacian(src, tempDst, CV_32F, 1, 1, 150);
	}
	cv::convertScaleAbs(tempDst, dst);
	cv::imshow("Laplacian", dst);

	cv::waitKey(0);
}