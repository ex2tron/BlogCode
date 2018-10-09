/* 漫水填充算法
* ex2tron 2017年6月1日
* http://ex2tron.lofter.com
*/
#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	//灰度图读入
	Mat srcImage = imread("D://ex2tron//Documents//01. Build//ImageProcess//Lena.png", CV_LOAD_IMAGE_GRAYSCALE);
	imshow("原图", srcImage);

	//漫水填充算法
	floodFill(srcImage, Point(50, 50), Scalar(0, 0, 0),0,Scalar(20,20,20),Scalar(20,20,20));
	imshow("效果图",srcImage);

	waitKey();
	return 0;
}