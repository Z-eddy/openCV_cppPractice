#include "opencv2/opencv.hpp"

int main()
{
	auto src{ cv::imread("images/dog.jpg").getUMat(cv::ACCESS_RW) };
	cv::imshow("original", src);
	cv::Mat sharpenAlgorithm{ {3,3},\
		{ 0, -1, 0,
		-1, 5, -1,//拉普拉斯算子是4,然后越大则越接近原图效果(原图权重像素占比越大)
		0, -1, 0 }
	};
	cv::UMat dstTemp,dst;
	cv::filter2D(src, dstTemp, CV_32F, sharpenAlgorithm);
	cv::convertScaleAbs(dstTemp, dst);
	cv::imshow("sharpen", dst);

	cv::waitKey(0);
}