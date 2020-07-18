#include "opencv2/opencv.hpp"

int main()
{
	cv::Mat dst{ cv::Mat::zeros({ 400,400 }, CV_8UC3) };//绘画容器
	cv::line(dst, { 100,100 }, { 200,200 }, { 255,0,0 }, 1);
	cv::rectangle(dst, cv::Rect{ {200,200},cv::Point{300,300} }, { 0,0,255 }, -1, cv::LINE_AA);//AA为抗锯齿
	cv::imshow("test", dst);
	cv::waitKey(0);
}