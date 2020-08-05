#include "opencv2/opencv.hpp"

int main()
{
	auto src{ cv::imread("E:/practice/openCV/material/images/llk.jpg") };
	auto tpl{ cv::imread("E:/practice/openCV/material/images/llk_tpl.png") };
	cv::imshow("original", src);
	cv::Mat dst;
	cv::matchTemplate(src, tpl, dst, cv::TM_CCORR_NORMED);
	cv::imshow("dst", dst);

	auto h{ dst.rows }, w{ dst.cols };//结果的行列
	for (int i{ 0 }; i != h; ++i) {
		for (int j{ 0 }; j != w; ++j) {
			auto v{ dst.at<float>(i,j) };
			if (v > 0.95) {
				cv::rectangle(src, cv::Point{ j,i }, cv::Point{ j + tpl.cols,i + tpl.rows}, cv::Scalar{ 0,0,255 }, 1, 8, 0);//框选出匹配图
			}
		}
	}
	cv::imshow("rectangle",src);

	cv::waitKey(0);
}