#include<string>
#include<iostream>
#include<vector>
#include "opencv2/opencv.hpp"
using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::ends;

int main()
{
	auto src{ cv::imread("images/dog.jpg") };
	if (src.empty()) {
		cout << "文件空" << endl;
	}
	string winTitle{ "dogImg" };
	cv::namedWindow(winTitle, cv::WINDOW_AUTOSIZE);
	cv::imshow(winTitle, src);
	cv::waitKey(0);

	/* Mat类型的时候,访问通过at来进行二维数组
	cv::Mat means, stdDev;
	cv::meanStdDev(src, means, stdDev);
	cout << "blue:" << ends << "means: " << means.at<double>(0, 0) << ends << "standard deviation: " << stdDev.at<double>(0, 0) << endl;
	cout << "green:" << ends << "means: " << means.at<double>(1, 0) << ends << "standard deviation: " << stdDev.at<double>(1, 0) << endl;
	cout << "red:" << ends << "means: " << means.at<double>(2, 0) << ends << "standard deviation: " << stdDev.at<double>(2, 0) << endl;
	*/
	//Scalar类型直接通过下标
	cv::Scalar means, stdDev;
	cv::meanStdDev(src, means, stdDev);
	cout << "blue:" << ends << "means: " << means[0] << ends << "standard deviation: " << stdDev[0] << endl;
	cout << "green:" << ends << "means: " << means[1] << ends << "standard deviation: " << stdDev[1] << endl;
	cout << "red:" << ends << "means: " << means[2] << ends << "standard deviation: " << stdDev[2] << endl;

	vector<cv::Mat>m;
	cv::split(src, m);
	auto src1{ m[0] };//蓝色通道的值表示的灰度
	cv::imshow(winTitle, src1);
	cv::waitKey(0);
	double minV{ -1 }, maxV{ -1 };
	cv::Point minP{ -1,-1 }, maxP{ -1,-1 };
	cv::minMaxLoc(src1, &minV, &maxV, &minP, &maxP);
	cout << minV << ends << maxV << ends << minP.x << ',' << minP.y << "\t" << ends << maxP << endl;
}