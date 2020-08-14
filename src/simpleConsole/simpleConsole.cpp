#include "opencv2/opencv.hpp"
#include<vector>
#include<iostream>
using std::vector;
using std::cout;
using std::endl;
using std::ends;

int main()
{
	auto src{ cv::imread("images/dog.jpg") };
	cv::imshow("original", src);

	cv::Mat tempCanny;
	cv::Canny(src, tempCanny, 100, 200);//使用canny默认的sobel算法进行轮廓发现

	vector<vector<cv::Point>> contours;//轮廓点集合
	cv::findContours(tempCanny, contours, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);

	for (int i{ 0 }; i != contours.size(); ++i) {
		cv::drawContours(src, contours, i, cv::Scalar{ 0,0,255 });
	}
	cv::imshow("dst", src);

	cv::waitKey(0);
}