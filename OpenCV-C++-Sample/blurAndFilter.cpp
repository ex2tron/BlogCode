/* 平滑滤波处理
 * 线性滤波：方框滤波、均值滤波、高斯滤波
 * 非线性滤波：中值滤波、双边滤波
 * ex2tron 2017年5月31日
 * http://ex2tron.lofter.com
 * 官方文档：http://www.opencv.org.cn/opencvdoc/2.3.2/html/doc/tutorials/imgproc/gausian_median_blur_bilateral_filter/gausian_median_blur_bilateral_filter.html#smoothing
 */
#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	//灰度图读入
	Mat srcImage = imread("Lena.png", CV_LOAD_IMAGE_GRAYSCALE);
	imshow("原图", srcImage);

	//方框滤波
	Mat boxFilterImage;
	boxFilter(srcImage, boxFilterImage, -1, Size(5, 5));
	imshow("方框滤波效果图", boxFilterImage);

	//均值滤波
	Mat blurImage;
	blur(srcImage, blurImage, Size(7, 7));
	imshow("均值滤波效果图", blurImage);

	//高斯滤波
	Mat gaussImage;
	GaussianBlur(srcImage, gaussImage, Size(5, 5), 0, 0);
	imshow("高斯滤波效果图", gaussImage);


	/* 非线性滤波 */
	// 中值滤波：
	//即中位数：http://baike.baidu.com/link?url=fiRF2gifeQddJEXT4XnPbS0Z4ZM-2F7OlLcsHlOzYnAoxCTnUVzzL6ppxkCw9JCaAcP9vhmcNNfcaGBMCmGQfcXHR9deYWvapcdxcONpBji
	Mat medianImage;
	medianBlur(srcImage, medianImage, 7);
	imshow("中值滤波效果图", medianImage);

	//双边滤波
	Mat bilateralImage;
	bilateralFilter(srcImage, bilateralImage, 25, 25 * 2, 25 / 2);
	imshow("双边滤波效果图", bilateralImage);

	waitKey();
	return 0;
}