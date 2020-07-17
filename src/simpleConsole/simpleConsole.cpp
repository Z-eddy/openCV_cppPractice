#include<iostream>
#include<string>
#include<chrono>
#include<thread>
#include "opencv2/opencv.hpp"
using std::cout;
using std::endl;
using std::ends;
using std::string;

int main()
{
	cv::VideoCapture v{ 0 };//使用摄像头
	if (!v.isOpened()) {
		cout << "摄像头无法打开" << endl;
	}
	cv::Mat frame;
	string winTitle{ "cameraDemo" };
	cv::namedWindow(winTitle, cv::WINDOW_AUTOSIZE);
	while (v.read(frame)) {
		cv::imshow(winTitle, frame);
		auto keyVal{ cv::waitKey(16) };
		if (keyVal == 27) {//退出键则退出
			break;
		}
	}
}