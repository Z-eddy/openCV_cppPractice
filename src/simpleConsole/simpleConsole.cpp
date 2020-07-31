#include"opencv2/opencv.hpp"

int main()
{
	auto src{ cv::imread("images/dog.jpg").getUMat(cv::ACCESS_RW) };
	cv::UMat dstTemp, dst;

	//robert x方向算子??y??
	cv::Mat robert_x{ {2,2},{1,0,0,-1} };
	cv::filter2D(src, dstTemp, CV_16S, robert_x);
	cv::convertScaleAbs(dstTemp, dst);
	cv::imshow("robert_x", dst);
	//robert y方向算子??x??
	cv::Mat robert_y{ {2,2},{0,-1,1,0} };
	cv::filter2D(src, dstTemp, CV_16S, robert_y);
	cv::convertScaleAbs(dstTemp, dst);
	cv::imshow("robert_y", dst);
	//prewitt x方向算子
	cv::Mat prewitt_x{ {3,3},
		{ -1,0,1,
		-1,0,1,
		-1,0,1 }
	};
	cv::filter2D(src, dstTemp, CV_32F, prewitt_x);
	cv::convertScaleAbs(dstTemp, dst);
	cv::imshow("prewittX", dst);
	//prewitt y方向算子
	cv::Mat prewitt_y{ {3,3},
		{-1,-1,-1,
		0,0,0,
		1,1,1 }
	};
	cv::filter2D(src, dstTemp, CV_32F, prewitt_y);
	cv::convertScaleAbs(dstTemp, dst);
	cv::imshow("prewittY", dst);

	cv::waitKey(0);
}