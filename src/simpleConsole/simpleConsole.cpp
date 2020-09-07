#include<vector>
#include<iostream>
#include "opencv2/opencv.hpp"
using std::vector;
using std::cout;
using std::endl;
using std::ends;

int main()
{
	auto src{ cv::imread("E:/practice/openCV/material/images/myMask.png") };
	cv::Mat canny;
	cv::Canny(src, canny, 80, 160);
	vector<cv::Mat>contours;
	cv::findContours(canny, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
	cv::Mat dst{ cv::Mat::zeros(src.size(),CV_32FC3) };
	cout << contours.size() << endl;
	auto row{ dst.rows };
	auto col{ dst.cols };
	for (int i{ 0 }; i != row; ++i) {
		for (int j{ 0 }; j != col; ++j) {
			auto distance{ cv::pointPolygonTest(contours[0],cv::Point{j,i},true) };
			if (distance == 0) {//点在边缘上
				dst.at<cv::Vec3f>(i, j) = cv::Vec3f{ 255,255,255 };
			}
			else if (distance > 0) {//点在内部
				dst.at<cv::Vec3f>(i, j) = cv::Vec3f(255 - distance, 0, 0);
			}
			else {//点在外部
				dst.at<cv::Vec3f>(i, j) = cv::Vec3f(0, 0, 255 + distance);
			}
		}
	}
	cv::convertScaleAbs(dst, dst);
	dst.convertTo(dst, CV_8UC3);
	cv::imshow("dst", dst);

	cv::waitKey(0);
}