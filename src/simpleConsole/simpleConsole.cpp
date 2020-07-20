/**/
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include "opencv2/opencv.hpp"
using std::map;
using std::cerr;
using std::cout;
using std::endl;
using std::ends;
using std::string;
using std::vector;

int main()
{
	string fileName{ "./images/dog.jpg" };
	cv::Mat src{ cv::imread(fileName) };
	cv::imshow("original", src);

	vector<cv::Mat>chns;
	cv::split(src, chns);
	vector<cv::Mat>bChn{ chns[0] }, gChn{ chns[1] }, rChn{ chns[2] };
	cv::Mat bHist, gHist, rHist;//获得直方图数据,256一维数组
	cv::calcHist(bChn, { 0 }, cv::Mat{}, bHist, { 256 }, { 0,255 });
	cv::calcHist(gChn, { 0 }, cv::Mat{}, gHist, { 256 }, { 0,255 });
	cv::calcHist(rChn, { 0 }, cv::Mat{}, rHist, { 256 }, { 0,255 });

	// 手工计数,和算法一致
	//auto p{ chns.at(0).ptr(0) };
	//auto tempSize{ chns.at(0).rows*chns.at(0).cols };
	//map<int, int>tempMap;
	//for (int i{ 0 }; i != tempSize; ++p, ++i) {
		//++tempMap[*p];
	//}

	int hist_w{ 512 };
	int hist_h{ 400 };
	auto dst{ cv::Mat{hist_h,hist_w,CV_8UC3,cv::Scalar{255,255,255}} };//画布800*600,白色
	cv::normalize(bHist, bHist, 0,hist_h, cv::NORM_MINMAX);
	cv::normalize(gHist, gHist, 0,hist_h, cv::NORM_MINMAX);
	cv::normalize(rHist, rHist, 0,hist_h, cv::NORM_MINMAX);
	auto step{cvRound(hist_w/ 256) };//四舍五入计算,两点之间的间隔
	for (int i = 1; i != 256; ++i) {
		//搞不懂为何要 hist_h -
		line(dst, cv::Point{ (i - 1)*step, hist_h - cvRound(bHist.at<float>(i - 1)) },
			cv::Point{ (i)*step, hist_h - cvRound(bHist.at<float>(i)) }, cv::Scalar{ 255,0,0 }, 1);
		line(dst, cv::Point{ (i - 1)*step,hist_h - cvRound(gHist.at<float>(i - 1)) },
			cv::Point{ (i)*step,hist_h - cvRound(gHist.at<float>(i)) }, cv::Scalar{ 0,255,0 }, 1);
		line(dst, cv::Point{ (i - 1)*step,hist_h - cvRound(rHist.at<float>(i - 1)) },
			cv::Point{ (i)*step,hist_h - cvRound(rHist.at<float>(i)) }, cv::Scalar{ 0,0,255 }, 1);
	}
	cv::imshow("result", dst);

	cv::waitKey(0);
}