#include<random>
#include<chrono>
#include<iostream>
#include<vector>
#include "opencv2/opencv.hpp"
using std::vector;
using std::cout;
using std::endl;
using std::ends;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::chrono::system_clock;

int main()
{
	//准备分割的二值图像
	auto src{ cv::imread("E:/practice/openCV/material/images/rice.png").getUMat(cv::ACCESS_RW) };
	cv::imshow("original", src);
	cv::UMat tempFilter;
	cv::GaussianBlur(src, tempFilter, { 3,3 }, 0);//高斯模糊
	cv::UMat tempGray;
	cv::cvtColor(tempFilter, tempGray, cv::COLOR_BGR2GRAY);//灰度图转化
	cv::UMat tempThreshold;
	cv::threshold(tempGray, tempThreshold, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);//阈值分割

	//联通组件标记
	cv::UMat labels;
	int num{ cv::connectedComponents(tempThreshold, labels) };//返回有多少个联通值,labels则是联通值的分布图,0值是黑色背景
	cout << "找到对象数量:" << ends << num - 1 << endl;
	//根据找到的数量随机产生颜色
	default_random_engine e(system_clock::now().time_since_epoch().count());
	uniform_int_distribution<int> u(20, 255);
	vector<cv::Scalar>colors;
	for (int i{ 0 }; i != num; ++i) {
		int B{ u(e) };
		int G{ u(e) };
		int R{ u(e) };
		colors.push_back(cv::Scalar_<int>{ B,G,R });
	}
	//将随机的颜色填充至图像中
	auto row{ labels.rows }, col{ labels.cols };
	int totalN{ row*col };
	cv::Mat dstMap;
	labels.copyTo(dstMap);
	cv::Mat dst{ cv::Mat::zeros(src.size(),src.type()) };//全黑的图片
	auto mapP{ dstMap.ptr<int>(0) };
	auto dstP{ dst.ptr(0) };//第一个值的索引
	for (int i{ 0 }; i != totalN; ++mapP, ++i) {
		if (*mapP == 0) {
			std::advance(dstP, 3);
			continue;
		}
		*dstP++ = colors.at(*mapP)[0];
		*dstP++ = colors.at(*mapP)[1];
		*dstP++ = colors.at(*mapP)[2];
	}
	cv::putText(dst, "find num:" + std::to_string(num - 1), cv::Point{ 10,50 }, cv::FONT_ITALIC, 1.0, { 0,0,255 });
	cv::imshow("dst", dst);


	cv::waitKey(0);
}