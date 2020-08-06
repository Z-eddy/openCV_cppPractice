#include "opencv2/opencv.hpp"

int main()
{
	auto src{ cv::imread("E:/practice/openCV/material/images/llk.jpg") };
	auto tpl{ cv::imread("E:/practice/openCV/material/images/llk_tpl.png") };
	cv::imshow("original", src);
	cv::Mat dst;
	cv::matchTemplate(src, tpl, dst, cv::TM_CCORR_NORMED);
	cv::imshow("dst", dst);

	auto row{ dst.rows }, col{ dst.cols };//结果的行列
	for (int i{ 0 }; i != row; ++i) {
		auto p{ dst.ptr<float>(i) };
		for (int j{ 0 }; j != col; ++j) {
			//auto v{ dst.at<float>(i,j) };//使用指针效率更高
			if (*p++ > 0.95) {
				cv::rectangle(src, cv::Point{ j,i }, cv::Point{ j + tpl.cols,i + tpl.rows}, cv::Scalar{ 0,0,255 }, 1, 8, 0);//框选出匹配图
			}
		}
	}
	cv::imshow("rectangle",src);

	cv::waitKey(0);
}