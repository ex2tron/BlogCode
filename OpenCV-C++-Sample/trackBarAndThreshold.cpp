/* 创建滑动条调节阈值，进行二值化
 * ex2tron 2017年5月28日
 * http://ex2tron.lofter.com
 * 官方文档：http://www.opencv.org.cn/opencvdoc/2.3.2/html/doc/tutorials/imgproc/threshold/threshold.html?highlight=threshold
 */
#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;

#define WINDOW_NAME "Original Image"


Mat srcImage, dstImage;

//trackBar回调函数
void onTrackBar(int thValue, void *)
{
	//阈值分割
	threshold(srcImage, dstImage, thValue, 255, 0);
	imshow(WINDOW_NAME, dstImage);
}

int main()
{
	//以灰度图形式打开图片
	srcImage = imread("Lena.png",CV_LOAD_IMAGE_GRAYSCALE);

	int thValue = 80;
	namedWindow(WINDOW_NAME, WINDOW_NORMAL);
	createTrackbar("threshold", WINDOW_NAME, &thValue, 255, onTrackBar);
	onTrackBar(thValue, 0);

	waitKey(0);
	return 0;
}