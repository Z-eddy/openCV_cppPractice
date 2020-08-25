#include<vector>
#include<iostream>
#include"opencv2/opencv.hpp"
using std::cout;
using std::ends;
using std::endl;
using std::vector;
using std::min;
using std::max;

int main()
{
	auto src{ cv::imread("E:/practice/openCV/material/images/stuff.jpg").getUMat(cv::ACCESS_RW) };
	cv::imshow("original", src);
	cv::UMat canny;
	cv::Canny(src, canny, 80, 160);
	cv::UMat k{ cv::getStructuringElement(cv::MORPH_RECT,{3,3}).getUMat(cv::ACCESS_RW) };
	cv::UMat dilate;
	cv::dilate(canny, dilate, k);
	vector<cv::UMat> contours;
	cv::findContours(dilate.getMat(cv::ACCESS_RW), contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
	for (auto item : contours) {
		//获得轮廓的中心
		auto moment{ cv::moments(item) };
		int cx = moment.m10 / moment.m00;
		int cy = moment.m01 / moment.m00;
		//获得外接矩形的长宽比
		auto rotateRect{ cv::minAreaRect(item) };
		vector<cv::Point2f> lines(4);
		rotateRect.points(&lines[0]);
		auto w{ rotateRect.size.width };
		auto h{ rotateRect.size.height };
		auto ratio{ min(w, h) / max(w,h) };
		if (ratio > 0.9) {//趋向于正方形
			cv::circle(src, { cx,cy }, 2, { 255,0,0 }, -1);
			for (auto beg{ lines.cbegin() }; beg != lines.cend(); ++beg) {//绘制矩形框
				auto second{ beg + 1 };
				if (beg == lines.cend() - 1) {//如果当前点是最后一点,则连接到第一点
					second = lines.cbegin();
				}
				cv::line(src, *beg, *second, { 0,0,255 }, 2);
			}
		}
		else if (ratio < 0.5) {//长方形
			cv::circle(src, { cx,cy }, 2, { 0,0,255 }, -1);
			for (auto beg{ lines.cbegin() }; beg != lines.cend(); ++beg) {//绘制矩形框
				auto second{ beg + 1 };
				if (beg == lines.cend() - 1) {//如果当前点是最后一点,则连接到第一点
					second = lines.cbegin();
				}
				cv::line(src, *beg, *second, { 255,0,255 }, 2);
			}
		}
	}
	cv::imshow("dst", src);

	cv::waitKey(0);
}
