/* 调整对比度和亮度：g(x)=a*f(x)+b
 * a叫做增益：控制图像的对比度
 * b称为偏置：控制图像的亮度
 * ex2tron 2017年5月28日
 * http://ex2tron.lofter.com
 * 官方文档：http://www.opencv.org.cn/opencvdoc/2.3.2/html/doc/tutorials/core/basic_linear_transform/basic_linear_transform.html
 */
#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;

//对比度和亮度
int gContrastValue, gBrightValue;
Mat gSrcImage, gDstImage;

void onContrastAndBright(int, void*)
{
	//访问每一个像素的方式
	for (int y = 0; y < gSrcImage.rows; y++)
	{
		for (int x = 0; x < gSrcImage.cols; x++)
		{
			for (int c = 0; c < 3; c++)
			{
				//运算结果可能超出像素取值范围，所以用 saturate_cast对结果进行转换，以确保它为有效值
				gDstImage.at<Vec3b>(y, x)[c] =saturate_cast<uchar>( gContrastValue*0.01*gSrcImage.at<Vec3b>(y, x)[c] + gBrightValue);
			}
		}
	}

	//或者用下面一句话搞定
	//gSrcImage.convertTo(gDstImage, -1, gContrastValue*0.01, gBrightValue);

	imshow("效果图", gDstImage);
}

int main()
{
	gSrcImage = imread("Lena.png");
	gDstImage = Mat::zeros(gSrcImage.size(), gSrcImage.type());

	gContrastValue = 80;
	gBrightValue = 80;

	namedWindow("效果图");
	createTrackbar("对比度:", "效果图", &gContrastValue, 300, onContrastAndBright);
	createTrackbar("亮度:", "效果图", &gBrightValue, 200, onContrastAndBright);
	onContrastAndBright(0, 0);

	waitKey(0);
	return 0;
}