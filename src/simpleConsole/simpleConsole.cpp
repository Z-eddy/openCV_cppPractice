#include<iostream>
#include<vector>
#include "opencv2/opencv.hpp"
using std::vector;
using std::endl;
using std::ends;
using std::cout;
using namespace cv;

int main()
{
	auto src{ cv::imread("E:/practice/openCV/material/images/contours.png") };
	cv::Mat canny;
	cv::Canny(src, canny, 80, 160);
	cv::imshow("canny", canny);
	auto k{ cv::getStructuringElement(cv::MORPH_RECT,{3,3}) };
	cv::Mat dilate;
	cv::dilate(canny, dilate, k);
	vector<cv::Mat>contours;
	cv::findContours(dilate, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
	cv::Mat dst{ src.size(),src.type(),{0,0,0} };
	for (auto i{ 0 }; i != contours.size(); ++i) {
		cv::drawContours(dst, contours, i, { 255,255,255 });//绘制本身的轮廓
		auto rect{ cv::boundingRect(contours.at(i)) };
		//dst(rect)=cv::Scalar{ 255,0,255 };
		//cout << rect.x << ends << rect.y << endl;

		cv::Mat dataA{ src.size(),CV_32F };//单通道用于计数
		auto data{ dataA(rect) };
		auto row{ data.rows };
		auto col{ data.cols };
		for (int r{ 0 }; r != row; ++r) {//计算每个点距离轮廓的距离
			auto p{ data.ptr<float>(r) };//每行的开头指针
			for (int c{ 0 }; c != col; ++c) {
				*p++ = cv::pointPolygonTest(contours.at(i), cv::Point{ c + rect.x,r + rect.y }, true);
				//data.at<float>(r,c) = cv::pointPolygonTest(contours.at(i), cv::Point{ c,r }, true);
			}
		}
		double minV{ 0 }, maxV{ 0 };
		cv::Point point;
		cv::minMaxLoc(dataA, &minV, &maxV, nullptr, &point);
		//cout << minV << ends << maxV << '\t' << point.x << ends << point.y << endl;
		if (maxV > 0) {
			cv::circle(dst, point, maxV, { 0,0,255 });
		}
	}
	cv::imshow("dst", dst);

	cv::waitKey(0);
}