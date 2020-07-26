#include "opencv2/opencv.hpp"

int main()
{
	auto src{ cv::imread("images/dog.jpg").getUMat(cv::ACCESS_RW)};
	cv::imshow("original", src);
	//pyramid金字塔
	//src,dst,空间窗口半径,颜色窗口半径,最大金字塔分割,最大停止条件(最多移动5次,RGB颜色差<1)
	cv::pyrMeanShiftFiltering(src, src, 10, 15, 1, cv::TermCriteria(cv::TermCriteria::COUNT + cv::TermCriteria::EPS, 5, 1));
	cv::imshow("pyrMeanShiftFilter", src);
	cv::waitKey(0);
}
