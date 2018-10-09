/* 开操作和闭操作
 * 开操作：先腐蚀后膨胀
 * 闭操作：先膨胀后腐蚀
 * OpenCV中都是针对白色高亮的部分
 * ex2tron 2017年6月1日
 * http://ex2tron.lofter.com
 * 官方文档：http://www.opencv.org.cn/opencvdoc/2.3.2/html/doc/tutorials/imgproc/opening_closing_hats/opening_closing_hats.html
 */
#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;

int gOpenCloseNum = 0;
int gMaxIterationNum = 10;
Mat gsrcImage, gDstImage;

static void onOpenClose(int, void*)
{
	int offset = gOpenCloseNum - gMaxIterationNum;
	int absoluteOffset = offset > 0 ? offset : -offset;

	Mat element = getStructuringElement(MORPH_RECT, Size(absoluteOffset * 2 + 1, absoluteOffset * 2 + 1), Point(absoluteOffset, absoluteOffset));

	//执行开操作或闭操作
	if (offset < 0)
		morphologyEx(gsrcImage, gDstImage, MORPH_OPEN, element);
	else
		morphologyEx(gsrcImage, gDstImage, MORPH_CLOSE, element);

	imshow("开运算和闭运算", gDstImage);
}

int main()
{
	//灰度图读入
	gsrcImage = imread("D://ex2tron//Documents//01. Build//ImageProcess//Lena.png", CV_LOAD_IMAGE_GRAYSCALE);
	imshow("原图", gsrcImage);

	namedWindow("开运算和闭运算");
	createTrackbar("迭代值", "开运算和闭运算", &gOpenCloseNum, gMaxIterationNum * 2 + 1, onOpenClose);
	onOpenClose(0, 0);

	waitKey();
	return 0;
}