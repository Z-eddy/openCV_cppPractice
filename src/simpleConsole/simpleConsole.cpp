/**/
#include<iostream>
#include<string>
#include<vector>
#include "opencv2/opencv.hpp"
using std::endl;
using std::ends;
using std::cout;
using std::cerr;
using std::string;
using std::vector;

int main()
{
	auto src0{ cv::imread("D:/codeSofts/opencv/sources/samples/data/lena.jpg") };
	auto src1{ cv::imread("D:/codeSofts/opencv/sources/samples/data/lena_tmpl.jpg") };
	auto src2{ cv::imread("D:/codeSofts/opencv/sources/samples/data/aero1.jpg") };
	auto src3{ cv::imread("D:/codeSofts/opencv/sources/samples/data/aero3.jpg") };

	cv::cvtColor(src0, src0, cv::COLOR_BGR2HSV);
	cv::cvtColor(src1, src1, cv::COLOR_BGR2HSV);
	cv::cvtColor(src2, src2, cv::COLOR_BGR2HSV);
	cv::cvtColor(src3, src3, cv::COLOR_BGR2HSV);

	cv::Mat hist0;
	vector<cv::Mat>src0Ve{ src0 };
	cv::calcHist(src0Ve, { 0,1 }, cv::Mat{}, hist0, { 60,64 }, { 0,180,0,256 });//计算直方图
	cv::normalize(hist0, hist0, 1, 0, cv::NORM_MINMAX);//归一化

	cv::Mat hist1;
	vector<cv::Mat>src1Ve{ src1 };
	cv::calcHist(src1Ve, { 0,1 }, cv::Mat{}, hist1, { 60,64 }, { 0,180,0,256 });
	cv::normalize(hist1, hist1, 1, 0, cv::NORM_MINMAX);

	cv::Mat hist2;
	vector<cv::Mat>src2Ve{ src2 };
	cv::calcHist(src2Ve, { 0,1 }, cv::Mat{}, hist2, { 60,64 }, { 0,180,0,256 });
	cv::normalize(hist2, hist2, 1, 0, cv::NORM_MINMAX);

	cv::Mat hist3;
	vector<cv::Mat>src3Ve{ src3 };
	cv::calcHist(src3Ve, { 0,1 }, cv::Mat{}, hist3, { 60,64 }, { 0,180,0,256 });
	cv::normalize(hist3, hist3, 1, 0, cv::NORM_MINMAX);

	auto v01{ cv::compareHist(hist0, hist1, cv::HISTCMP_CORREL) };
	auto v23{ cv::compareHist(hist2, hist3, cv::HISTCMP_CORREL) };
	cout << "HISTCMP_CORREL:" << v01 << ends << v23 << endl;

	v01 = cv::compareHist(hist0, hist1, cv::HISTCMP_BHATTACHARYYA);
	v23 = cv::compareHist(hist2, hist3, cv::HISTCMP_BHATTACHARYYA);
	cout << "HISTCMP_BHATTACHARYYA:" << v01 << ends << v23 << endl;

	cv::waitKey(0);
}