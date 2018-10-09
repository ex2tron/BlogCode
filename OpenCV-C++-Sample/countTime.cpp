/* 统计程序运行时间
 * ex2tron 2017年5月28日
 * http://ex2tron.lofter.com
 */
#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;

//访问像素方式缩减颜色空间
void ColorReduce(Mat& input, Mat& output, int div)
{
	output = input.clone();
	int rows = output.rows;
	int cols = output.cols*output.channels();

	for (int i = 0; i < rows; i++)
	{
		uchar* data = output.ptr<uchar>(i);
		for (int j = 0; j < cols; j++)
		{
			data[j] = data[j] / div*div;
		}
	}
}

int main()
{
	Mat srcImage = imread("Lena.png");
	Mat dstImage;

	//统计时间：开始
	double timeCount = getTickCount();
	ColorReduce(srcImage, dstImage, 20);
	//统计时间：结束
	double time = ((double)getTickCount() - timeCount) / getTickFrequency();
	cout << time;

	imshow("原图", srcImage);
	imshow("颜色空间减缩后图", dstImage);

	waitKey(0);
	return 0;
}