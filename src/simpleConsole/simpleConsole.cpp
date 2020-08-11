#include<iostream>
#include "opencv2/opencv.hpp"
using std::cout;
using std::endl;
using std::ends;

int main()
{
	auto src{ cv::imread("E:/practice/openCV/material/images/rice.png").getUMat(cv::ACCESS_RW) };
	cv::imshow("original", src);
	cv::UMat gaussian;
	cv::GaussianBlur(src, gaussian, { 3,3 }, 0);
	cv::UMat gray;
	cv::cvtColor(gaussian, gray, cv::COLOR_BGR2GRAY);
	cv::UMat threBin;
	cv::threshold(gray, threBin, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);
	cv::Mat labels, labStatus, labCenterPoint;//map分布,单个的联通单元具体参数,单个联通单元的中心点,要具体单个值处理,使用Mat而非UMat
	auto nums{ cv::connectedComponentsWithStats(threBin, labels, labStatus, labCenterPoint) };//返回具体发现的个数,0索引是黑色背景
	cv::Mat dst{ src.getMat(cv::ACCESS_READ) };
	for (int i{ 1 }; i != nums; ++i) {
		//中心点绘制圆心
		cv::Point_<double> center{ labCenterPoint.at<double>(i,0),labCenterPoint.at<double>(i,1) };//中心点获得
		cv::circle(dst, center, 2, { 0,255,0 }, -1);//大米中间填充圆心
		//绘制方框
		cv::Point pointLeft{ labStatus.at<int>(i, cv::CC_STAT_LEFT),labStatus.at<int>(i,cv::CC_STAT_TOP) };//左上角的点
		cv::Size size{ labStatus.at<int>(i,cv::CC_STAT_WIDTH),labStatus.at<int>(i,cv::CC_STAT_HEIGHT) };//宽高
		int pixelNum{ labStatus.at<int>(i,cv::CC_STAT_AREA) };//像素的多少
		cout << i << ends << pixelNum << endl;
		cv::rectangle(dst, { pointLeft,size }, { 0,255,0 });//绘制方框
		cv::putText(dst, cv::format("index:%d", i), pointLeft, cv::FONT_HERSHEY_SIMPLEX, 0.5, { 0,0,255 });
	}
	cv::imshow("dst", dst);

	cv::waitKey(0);
}
