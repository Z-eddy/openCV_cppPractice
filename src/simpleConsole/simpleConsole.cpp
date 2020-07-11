#include<iostream>
#include<string>
#include<chrono>
#include "opencv2/opencv.hpp"
using std::chrono::high_resolution_clock;
using std::string;
using std::cout;
using std::endl;
using std::ends;

int main()
{
	string filePath{ "./images/dog.jpg" };
	cv::Mat src{ cv::imread(filePath) };
	if (src.empty()) {
		cout << "file error" << endl;
		return 0;
	}
	string winTitle{ "dogPic" };
	cv::namedWindow(winTitle, cv::WINDOW_AUTOSIZE);
	cv::imshow(winTitle, src);//显示原图
	cv::waitKey(0);
	auto nTime{ high_resolution_clock::now().time_since_epoch().count() };
	//图片反色
	auto r{ src.rows };//行数
	auto c{ src.cols };//列数
	auto ch{ src.channels() };//通道数
	/*
	//使用下标耗时54ms
	for (int i{ 0 }; i != r; ++i) {
		for (int j{ 0 }; j != c; ++j) {
			if (ch == 3) {//如果是bgr颜色通道
				auto &bgr{ src.at<cv::Vec3b>(i,j) };//获得坐标点的像素
				for (int i{ 0 }; i != 3; ++i) {
					bgr[i] = 255 - bgr[i];//反色
				}
			}
			else if (ch == 1) {
				auto &bgr{ src.at<uchar>(i,j) };
				bgr = 255 - bgr;
			}
		}
	}
	*/
	/*
	//使用迭代器 213.5ms
	if (ch == 3) {
		for (auto beg{ src.begin<cv::Vec3b>() }; beg != src.end<cv::Vec3b>(); ++beg) {
			for (int i{ 0 }; i != 3; ++i) {
				(*beg)[i] = 255 - (*beg)[i];
			}
		}
	}
	else {
		for (auto beg{ src.begin<uchar>() }; beg != src.end<uchar>(); ++beg) {
			*beg = 255 - *beg;
		}
	}
	*/
	//使用指针 1.2ms//可怕
	for (int i{ 0 }; i != r; ++i) {//对于每一行
		auto rPtr{ src.ptr(i) };//获得行的指针
		for (int j{ 0 }; j != c; ++j) {
			if (ch == 3) {
				rPtr[0] = 255 - rPtr[0];
				rPtr[1] = 255 - rPtr[1];
				rPtr[2] = 255 - rPtr[2];
				//std::advance(rPtr, 3);
				rPtr += 3;//手动挪动3个位置
			}
			else if (ch == 1) {
				*rPtr = 255 - *rPtr;
			}
		}
	}
	auto eTime{ high_resolution_clock::now().time_since_epoch().count() };
	cout << eTime - nTime << endl;
	cv::imshow(winTitle, src);
	cv::waitKey(0);
}