#include<vector>
#include<iostream>
#include "opencv2/opencv.hpp"
using std::cout;
using std::endl;
using std::ends;
using std::vector;

int main()
{
	auto src{ cv::imread("E:/openCV/opencv_tutorial/data/images/twolines.png") };
	cv::Mat canny;
	cv::Canny(src, canny, 80, 160);
	auto k{ cv::getStructuringElement(cv::MORPH_RECT,{3,3}) };
	//cv::Mat temp;
	//cv::dilate(canny, temp, k);
	//cv::imshow("dilate",temp);
	vector<vector<cv::Point>>contours;
	cv::findContours(canny, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
	for (auto item : contours) {//每个轮廓
		auto rect{ cv::boundingRect(item) };
		auto v{ std::max(rect.width, rect.height) };//寻找最大的边
		if (v < 30) {//如果最大的宽/高都小于30像素则不计
			continue;
		}
		cv::Vec4f ve4;
		cv::fitLine(item, ve4, cv::DIST_L1, 0, 0.01, 0.01);//拟合直线
		//归一化后的vx,vy(单位1向量)
		auto vx{ ve4[0] };
		auto vy{ ve4[1] };
		//线上的某个点
		auto x0{ ve4[2] };
		auto y0{ ve4[3] };
		//斜率
		auto k{ vy / vx };
		if (std::abs(k) > 1e5) {//轮廓趋近于垂直时
			continue;
		}
		//截距
		auto b{ y0 - x0 * k };
		int xMax{ INT_MIN }, xMin{ INT_MAX };
		for (auto point:item) {//求得轮廓的x的最大最小值
			xMax = xMax > point.x ? xMax : point.x;
			xMin = xMin < point.x ? xMin : point.x;
		}
		//获得对应的y
		int yMax = xMax * k + b;
		int yMin = xMin * k + b;

		cv::line(src, { xMin,yMin }, { xMax,yMax }, { 0,0,255 });
	}
	cv::imshow("dst", src);

	cv::waitKey(0);
}