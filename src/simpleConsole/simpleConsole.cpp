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
	vector<cv::Vec2f>ve;
	cv::HoughLines(canny, ve, 1, CV_PI / 180, 180);//(src,ve,极坐标r步长,theta角度步长,统计点阈值)
	for (const auto&item : ve) {//每条直线
		//原点到直线的垂直线
		auto r{ item[0] };
		auto theta{ item[1] };
		//恰好垂直的点
		auto x0{ r*std::cos(theta) };
		auto y0{ r*std::sin(theta) };
		//随便指定(x1,y1),(x2,y2)绘制线段
		int L{ 1000 };
		auto x1{ x0 - L * std::sin(theta) };
		auto y1{ y0 + L * std::cos(theta) };

		auto x2{ x0 + L * std::sin(theta) };
		auto y2{ y0 - L * std::cos(theta) };

		cv::line(src, cv::Point( x1,y1 ), cv::Point( x2,y2 ), { 0,0,255 });
	}
	cv::imshow("dst", src);

	cv::waitKey(0);
}