/* ͼ�������
* ex2tron 2017��6��5��
* http://ex2tron.lofter.com
* ������http://www.opencv.org.cn/opencvdoc/2.3.2/html/doc/tutorials/imgproc/pyramids/pyramids.html#pyramids
*/
#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	//�Ҷ�ͼ����
	Mat srcImage = imread("D://ex2tron//Documents//01. Build//ImageProcess//Lena.png", CV_LOAD_IMAGE_GRAYSCALE);
	imshow("ԭͼ", srcImage);

	//����ȡ������
	Mat dstImage1;
	pyrUp(srcImage, dstImage1);
	imshow("����ȡ������ͼ", dstImage1);

	//����ȡ������
	Mat dstImage2;
	pyrDown(srcImage, dstImage2);
	imshow("����ȡ������ͼ", dstImage2);

	waitKey();
	return 0;
}