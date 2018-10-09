/* 腐蚀和膨胀示例
 * OpenCV中都是针对白色高亮的部分
 * ex2tron 2017年5月31日
 * http://ex2tron.lofter.com
 * 官方文档：http://www.opencv.org.cn/opencvdoc/2.3.2/html/doc/tutorials/imgproc/erosion_dilatation/erosion_dilatation.html
 */
#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	//灰度图读入
	Mat srcImage = imread("Lena.png", CV_LOAD_IMAGE_GRAYSCALE);
	imshow("原图", srcImage);

	//膨胀操作
	Mat element = getStructuringElement(MORPH_RECT, Size(3, 3));
	Mat dilateImage;
	dilate(srcImage, dilateImage, element);
	imshow("膨胀后的图", dilateImage);

	//腐蚀操作
	Mat elementErode = getStructuringElement(MORPH_RECT, Size(3, 3));
	Mat erodeImage;
	erode(srcImage, erodeImage, element);
	imshow("腐蚀后的图", erodeImage);

	waitKey();
	return 0;
}