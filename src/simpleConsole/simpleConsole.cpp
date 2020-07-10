#include "opencv2/opencv.hpp"
using namespace cv;

int main()
{
	Mat src{ imread("./images/行走天涯柴犬.jpg") };
	imshow("dogTitle", src);
	waitKey(0);
	destroyAllWindows();
	return 0;
}