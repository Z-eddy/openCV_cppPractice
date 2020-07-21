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
	//归一化后在画布上可视化呈现
	int rows{ 600 }, cols{ 800 };
	cv::Mat dst{ rows,cols,CV_8UC3,cv::Scalar{255,255,255} };//画布
	auto step{ cvRound(cols*1.0 / 256) };
	//绘制直方图
	cv::Mat hist;
	vector<cv::Scalar>vColor{ {255,0,0},{0,255,0},{0,0,255} };//颜色集
	for (int i{ 0 }; i != chnls.size(); ++i) {//对于每个通道
		cv::calcHist(chnls, { i }, cv::Mat{}, hist, { 256 }, { 0,255 });//计算通道的直方图
		cv::normalize(hist, hist, 0, rows, cv::NORM_MINMAX);//归一化直方图的值
		for (int j{ 1 }; j != 256; ++j) {//绘制折线,必须用rows-，因为y轴像素是负增长
			cv::line(dst, { (j - 1)*step,cvRound(rows - hist.at<float>(j - 1)) }, { j*step ,cvRound(rows - hist.at<float>(j)) }, vColor.at(i), 2);
		}
	}

	cv::imshow("dst", dst);

	cv::waitKey(0);
}