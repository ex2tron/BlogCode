/* 打开图片并显示
 * ex2tron 2017年5月28日
 * http://ex2tron.top
 * 官方文档：http://www.opencv.org.cn/opencvdoc/2.3.2/html/doc/user_guide/ug_mat.html#id2
 */
#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	//打开图片并显示
	Mat srcImage = imread("Lena.png");

	imshow("Original Image", srcImage);
	
	waitKey(0);
	return 0;
}