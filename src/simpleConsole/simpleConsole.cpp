#include<vector>
#include "opencv2/opencv.hpp"
using std::vector;

int main()
{
	auto src{ cv::imread("E:/practice/openCV/material/images/stuff.jpg") };
	cv::imshow("src", src);
	cv::Mat canny;
	cv::Canny(src, canny,80,160);

	auto k{ cv::getStructuringElement(cv::MORPH_RECT,{3,3}) };
	cv::Mat theDialate;
	cv::dilate(canny, theDialate, k);//膨胀,连接断开的边缘

	vector<vector<cv::Point>>contours;
	cv::findContours(theDialate, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
	for (int i{ 0 }; i != contours.size(); ++i) {
		//最小轮廓矩形发现
		auto routateRect{ cv::minAreaRect(contours.at(i)) };
		cv::Point2f fourLine[4];
		routateRect.points(fourLine);
		for (int i{ 0 }; i != 4; ++i) {
			cv::line(src, fourLine[i % 4], fourLine[(i + 1) % 4], cv::Scalar{ 0,0,255 });
		}
		//最大外接矩形发现
		auto rect{ cv::boundingRect(contours.at(i)) };
		cv::rectangle(src,rect, cv::Scalar{ 0,0,255 });
	}
	cv::imshow("dst", src);

	cv::waitKey(0);
}