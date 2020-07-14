#include<iostream>
#include<string>
#include<vector>
#include "opencv2/opencv.hpp"
using std::vector;
using std::cout;
using std::endl;
using std::ends;
using std::string;

int main()
{
	string fileName{ "./images/dog.jpg" };
	auto src{ cv::imread(fileName) };
	if (src.empty()) {
		cout << "read file error" << endl;
		return 0;
	}
	string winTitle{ "dogPic" };
	cv::namedWindow(winTitle, cv::WINDOW_AUTOSIZE);
	//原图显示
	cv::imshow(winTitle, src);
	cv::waitKey(0);
	//颜色分离
	for (int i{ 0 }; i != 3; ++i) {
		vector<cv::Mat>mv;//分离出来的盛放容器
		cv::split(src, mv);//通道分离,结果独立
		mv[i] = cv::Scalar{ 0 };//依次去除BGR通道
		cv::Mat des;
		cv::merge(mv, des);
		cv::imshow(winTitle, des);
		cv::waitKey(0);
	}
}