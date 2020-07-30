#include"opencv2/opencv.hpp"

int main()
{
	auto src{ cv::imread("images/dog.jpg").getUMat(cv::ACCESS_RW) };
	cv::UMat xDerivation, yDerivation;
	//src,dst,图像深度(1表示和原图一样,防止溢出手动指定CV_32F),x方向求导,y方向求导,窗口大小,放缩比例,补偿(偏移值,在结果上增加),图像边缘处理方式
	cv::Sobel(src, xDerivation, CV_32F, 1, 0, 3, 1, 0, 4);
	cv::Sobel(src, yDerivation, CV_32F, 0, 1);
	cv::UMat xDst, yDst;
	cv::convertScaleAbs(xDerivation,xDst);//归一化到255
	cv::convertScaleAbs(yDerivation,yDst);
	cv::imshow("x",xDst);
	cv::imshow("y",yDst);
	//合并x\y
	cv::UMat dst0,dst1;
	cv::add(xDst, yDst, dst0, cv::UMat(), CV_16S);
	cv::convertScaleAbs(dst0, dst1);
	cv::imshow("dst", dst1);

	cv::waitKey(0);
}