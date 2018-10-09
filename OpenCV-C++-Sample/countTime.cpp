/* ͳ�Ƴ�������ʱ��
 * ex2tron 2017��5��28��
 * http://ex2tron.lofter.com
 */
#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;

//�������ط�ʽ������ɫ�ռ�
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

	//ͳ��ʱ�䣺��ʼ
	double timeCount = getTickCount();
	ColorReduce(srcImage, dstImage, 20);
	//ͳ��ʱ�䣺����
	double time = ((double)getTickCount() - timeCount) / getTickFrequency();
	cout << time;

	imshow("ԭͼ", srcImage);
	imshow("��ɫ�ռ������ͼ", dstImage);

	waitKey(0);
	return 0;
}