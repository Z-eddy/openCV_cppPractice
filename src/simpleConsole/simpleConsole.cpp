#include<string>
#include"opencv2/opencv.hpp"
using std::string;

int main()
{
	cv::Mat src{ cv::imread("G:/Practice/openCV/images/TinyGreen.PNG") };
	if (src.empty()) {
		return 0;
	}
	string winTitle{ "dogPic" };
	cv::namedWindow(winTitle, cv::WINDOW_AUTOSIZE);
	cv::imshow(winTitle, src);

	cv::Mat dst{ cv::Mat::zeros(src.size(),src.type()) };
	cv::cvtColor(src, dst, cv::COLOR_BGR2YUV);//YUV
	cv::imshow("YUV", dst);
	cv::cvtColor(src, dst, cv::COLOR_BGR2YCrCb);//YCrCb
	cv::imshow("YCrCb", dst);
	cv::cvtColor(src, dst, cv::COLOR_BGR2HSV);//转成HSV图片
	cv::imshow("HSV", dst);

	cv::Scalar tMin{ 26,43,46 }, tMax{ 77,255,255 };//范围内为白色,范围外黑色
	cv::inRange(dst, tMin, tMax, dst);
	cv::cvtColor(dst, dst, cv::COLOR_GRAY2BGR);//必须转换为3通道,否则相加则错误
	dst += src;
	cv::imshow(winTitle, dst);

	cv::waitKey(0);
}