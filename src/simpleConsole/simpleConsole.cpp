#include<string>
#include<vector>
#include<iostream>
#include "opencv2/opencv.hpp"
using std::cout;
using std::endl;
using std::ends;
using std::string;
using std::vector;

int main()
{
	auto src{ cv::imread("./images/dog.jpg") };
	cv::imshow("original", src);
	vector<cv::Mat>channels;
	cv::split(src, channels);

	cv::Mat bHist,gHist,rHist;
	//inputArr,输入的通道数,mask,outputArr,柱个数,每个柱取值范围
	vector<int>channelN{ 0 };
	vector<int>hitSize{ 256 };
	vector<float>ranges{ 0,255 };
	vector<cv::Mat>bSrc{ channels[0] }, gSrc{ channels[1] }, rSrc{ channels[2] };
	vector<cv::Mat>outArrays;
	cv::calcHist(bSrc, channelN, cv::Mat{}, bHist, hitSize, ranges);//计算b通道直方图
	cv::calcHist(gSrc, channelN, cv::Mat{}, gHist, hitSize, ranges);//计算g通道直方图
	cv::calcHist(rSrc, channelN, cv::Mat{}, rHist, hitSize, ranges);//计算r通道直方图

	cout << bHist.type() << endl;

	//画布,rows=600,columns=800
	cv::Mat dst{ 600,800,CV_8UC3,cv::Scalar{255,255,255} };

	cv::waitKey(0);
}
