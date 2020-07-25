#include "opencv2/opencv.hpp"

int main()
{
	auto src{ cv::imread("images/dog.jpg").getUMat(cv::ACCESS_RW) };
	if (src.empty()) {
		return 0;
	}
	cv::imshow("original", src);
	/*
	fastNlMeansDenoising(
		src // 输入图像
		dst = None, // 输出结果
		h = None, // h值越大表示去噪声力度越大，同时细节丢失也越多，默认10即可。
		templateWindowSize = None, // 相似性权重计算窗口大小，一般为5～15之间
		searchWindowSize = None// 搜索窗口，大小可以设置为相似性计算窗口大小的3～5倍即可。
	)
	*/
	cv::fastNlMeansDenoisingColored(src,src,3,3,7,21);
	cv::imshow("非局部均值去噪",src);
	cv::waitKey(0);
}