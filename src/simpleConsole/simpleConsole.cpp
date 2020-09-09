#include<vector>
#include<iostream>
#include"opencv2/opencv.hpp"
using std::vector;
using std::cout;
using std::endl;
using std::ends;

int main()
{
	auto src{ cv::imread("D:/temp.png").getUMat(cv::ACCESS_FAST) };
	cv::UMat canny;
	cv::Canny(src, canny, 80, 160);
	vector<cv::Vec4i>ve;
	cv::HoughLinesP(canny, ve, 1, CV_PI / 180, 80,120,10);//(src,ve,极坐标r步长,theta角度步长,统计点阈值)
	for (const auto&item : ve) {//每条直线
		cv::line(src, cv::Point(item[0],item[1]), cv::Point(item[2],item[3]), { 0,0,255 });
	}
	cv::imshow("dst", src);

	cv::waitKey(0);
}