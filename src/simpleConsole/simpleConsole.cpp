#include<iostream>
#include<string>
#include "opencv2/opencv.hpp"
using std::string;
using std::cout;
using std::ends;
using std::endl;

int main()
{
	//原始图像读取、显示
	string fileName{ "./images/行走天涯柴犬.jpg" };
	cv::Mat src{ cv::imread(fileName) };
	string winTitle{ "showPic" };
	cv::namedWindow(winTitle, cv::WINDOW_AUTOSIZE);
	cv::imshow(winTitle, src);
	cv::waitKey(0);

	//图像转换为灰度图
	cv::Mat tempPic;
	//色彩转换
	cv::cvtColor(src, tempPic, cv::COLOR_RGB2GRAY);
	//cv::cvtColor(src, tempPic, cv::COLOR_BGR2GRAY);
	cv::imshow(winTitle, tempPic);
	cv::waitKey(0);

	//保存转换出来的灰度图
	string newFile{ "黑白色行走天涯柴犬.jpg" };
	bool ok{ cv::imwrite(newFile,tempPic) };
	if (ok) {
		cout << "图片生成完毕" << endl;
	}
	else
	{
		cout << "图片转换失败" << ends;
	}

	return 0;
}