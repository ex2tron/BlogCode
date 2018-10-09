/* 图像金字塔
* ex2tron 2017年6月5日
* http://ex2tron.lofter.com
* 官网：http://www.opencv.org.cn/opencvdoc/2.3.2/html/doc/tutorials/imgproc/pyramids/pyramids.html#pyramids
*/
#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	//灰度图读入
	Mat srcImage = imread("D://ex2tron//Documents//01. Build//ImageProcess//Lena.png", CV_LOAD_IMAGE_GRAYSCALE);
	imshow("原图", srcImage);

	//向上取样操作
	Mat dstImage1;
	pyrUp(srcImage, dstImage1);
	imshow("向上取样操作图", dstImage1);

	//向下取样操作
	Mat dstImage2;
	pyrDown(srcImage, dstImage2);
	imshow("向下取样操作图", dstImage2);

	waitKey();
	return 0;
}