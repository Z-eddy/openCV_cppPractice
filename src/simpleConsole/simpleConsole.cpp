#include<iostream>
#include<vector>
#include<string>
#include "opencv2/opencv.hpp"
using std::cout;
using std::endl;
using std::ends;
using std::vector;
using std::string;

int main()
{
	auto src{ cv::imread("images/dog.jpg") };
	vector<cv::Mat>chnls;
	cv::imshow("original", src);
	cv::split(src, chnls);
	for (auto item : chnls) {
		cv::equalizeHist(item, item);
	}
	cv::merge(chnls, src);
	cv::imshow("equalizeHist", src);
	cv::waitKey(0);
}