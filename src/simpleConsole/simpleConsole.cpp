#include<vector>
#include<iostream>
#include "opencv2/opencv.hpp"
using std::vector;
using std::cout;
using std::ends;
using std::endl;

vector<cv::UMat> getContours(cv::UMat arg) {//从原图读取,然后进行轮廓提取
	if (arg.empty()) {//空的就返回
		cout << "empty" << endl;
		return{};
	}
	cv::UMat gray,threshold;
	cv::cvtColor(arg, gray, cv::COLOR_BGR2GRAY);
	cv::threshold(gray, threshold, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);
	vector<cv::UMat> contours;
	cv::findContours(threshold, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
	return contours;
}
int main()
{
	auto src0{ cv::imread("E:/practice/openCV/material/images/abc.png").getUMat(cv::ACCESS_FAST) };
	auto src1{ cv::imread("E:/practice/openCV/material/images/a5.png").getUMat(cv::ACCESS_FAST) };
	auto contours0{ getContours(src0) };
	auto contours1{ getContours(src1) };
	auto moment{ cv::moments(contours1.at(0)) };//模板的矩
	cv::UMat huMoment;//模板的胡矩
	cv::HuMoments(moment, huMoment);
	int i{ 0 };
	for (auto item : contours0) {
		auto theMoment{ cv::moments(item) };
		cv::UMat theHu;
		cv::HuMoments(theMoment, theHu);
		auto v{ cv::matchShapes(huMoment, theHu, cv::CONTOURS_MATCH_I1, 0) };
		cout << "val" << ends << v << endl;
		if (v < 1) {//即匹配高
			cout << "the" << ends << i << endl;
			cv::drawContours(src0, contours0, i, { 0,0,255 }, 2);
		}
		++i;
	}
	cv::imshow("dst", src0);

	cv::waitKey(0);
}
