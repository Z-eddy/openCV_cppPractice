#include<string>
#include<vector>
#include "opencv2/opencv.hpp"
using std::string;
using std::vector;

int main()
{
	cv::Mat src{ cv::imread("images/dog.jpg") };
	cv::Rect rect{ cv::Point{100,200},cv::Size{200,200} };
	cv::Mat roi{ src(rect) };
	//roi.setTo(cv::Scalar{ 255,0,0 });//三通道颜色更改,也可以直接roi=Scalar{255,0,0}
	//改变roi颜色
	for (int i{ 0 }; i != roi.rows; ++i) {
		auto p{ roi.ptr(i) };//行指针
		for (int j{ 0 }; j != roi.cols; ++j) {
			p[0] = 0;
			p += 3;
		}
	}
	cv::imshow("original", src);
	cv::imshow("roiToB255",roi);
	cv::waitKey(0);
}