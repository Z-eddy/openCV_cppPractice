#include "opencv2/opencv.hpp"

int main()
{
	auto src{ cv::imread("images/dog.jpg").getUMat(cv::ACCESS_RW) };
	cv::UMat tempDst,dst;
	cv::Canny(src,tempDst, 80, 240, 3, false);//默认的使用sobel算子计算x/y方向的inputArray,非默认的自己指定xInput,yInput
	cv::cvtColor(tempDst, dst, cv::COLOR_GRAY2BGR);
	cv::putText(dst, "Canny", { 20,20 }, cv::FONT_ITALIC, 1.0, { 0,0,255 }, 2);//但是不能打印中文?
	cv::imshow("Canny边缘检测器", dst);

	cv::waitKey(0);
}