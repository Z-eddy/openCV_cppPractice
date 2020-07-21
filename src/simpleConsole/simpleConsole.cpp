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
	cv::Mat src{ cv::imread("images/dog.jpg") };
	cv::imshow("original", src);
	cout << src.type() << endl;

	//分离并计算直方图y数据
	vector<cv::Mat>chnls;
	cv::split(src, chnls);
	vector<cv::Mat> bChn{ chnls[0] }, gChn{ chnls[1] }, rChn{ chnls[2] };
	cv::Mat bHist, gHist, rHist;
	cv::calcHist(bChn, { 0 }, cv::Mat{}, bHist, { 256 }, { 0,255 });
	cv::calcHist(gChn, { 0 }, cv::Mat{}, gHist, { 256 }, { 0,255 });
	cv::calcHist(rChn, { 0 }, cv::Mat{}, rHist, { 256 }, { 0,255 });

	//归一化后在画布上可视化呈现
	int rows{ 600 }, cols{ 800 };
	cv::Mat dst{ rows,cols,CV_8UC3,cv::Scalar{255,255,255} };//画布
	//不归一化就难以在图上显示完全(计数8000时,严重超过rows的像素)
	cv::normalize(bHist, bHist, 0, rows, cv::NORM_MINMAX);
	cv::normalize(gHist, gHist, 0, rows, cv::NORM_MINMAX);
	cv::normalize(rHist, rHist, 0, rows, cv::NORM_MINMAX);
	auto step{ cvRound(cols*1.0 / 256) };
	for (int i{ 1 }; i != 256; ++i) {//必须用rows-，因为y轴像素是负增长
		cv::line(dst, { (i - 1)*step,cvRound(rows - bHist.at<float>(i - 1)) }, { i*step ,cvRound(rows - bHist.at<float>(i)) }, cv::Scalar{ 255,0,0 }, 2);
		cv::line(dst, { (i - 1)*step,cvRound(rows - gHist.at<float>(i - 1)) }, { i*step ,cvRound(rows - gHist.at<float>(i)) }, cv::Scalar{ 0,255,0 }, 2);
		cv::line(dst, { (i - 1)*step,cvRound(rows - rHist.at<float>(i - 1)) }, { i*step ,cvRound(rows - rHist.at<float>(i)) }, cv::Scalar{ 0,0,255 }, 2);
	}
	cv::imshow("dst", dst);

	cv::waitKey(0);
}