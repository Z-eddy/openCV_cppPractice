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
	cv::VideoCapture video{ "D:/codeSofts/opencv/opencv/sources/samples/data/vtest.avi" };
	if (!video.isOpened()) {
		cout << "打开文件错误" << endl;
	}
	cv::Size size(video.get(cv::CAP_PROP_FRAME_WIDTH), video.get(cv::CAP_PROP_FRAME_HEIGHT));//获得帧的宽高
	auto fps{ video.get(cv::CAP_PROP_FPS) };//帧率
	cv::VideoWriter writer{ "videoDemo.mp4",cv::CAP_PROP_FOCUS,fps,size };
	cv::Mat frame;//每一帧
	while (video.read(frame)) {//读取帧数据
		writer.write(frame);//写入帧数据
	}
}