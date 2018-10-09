/* 尺寸调整
 * ex2tron 2017年6月5日
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

	//缩小图片
	Mat dstImage1;
	resize(srcImage, dstImage1, Size(srcImage.cols / 2, srcImage.rows / 2));
	imshow("缩小图", dstImage1);

	//放大图片
	Mat dstImage2;
	resize(srcImage, dstImage2, Size(srcImage.cols * 2, srcImage.rows *2));
	imshow("放大图", dstImage2);

	waitKey();
	return 0;
}