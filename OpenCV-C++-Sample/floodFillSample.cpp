/* ��ˮ����㷨
* ex2tron 2017��6��1��
* http://ex2tron.lofter.com
*/
#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	//�Ҷ�ͼ����
	Mat srcImage = imread("D://ex2tron//Documents//01. Build//ImageProcess//Lena.png", CV_LOAD_IMAGE_GRAYSCALE);
	imshow("ԭͼ", srcImage);

	//��ˮ����㷨
	floodFill(srcImage, Point(50, 50), Scalar(0, 0, 0),0,Scalar(20,20,20),Scalar(20,20,20));
	imshow("Ч��ͼ",srcImage);

	waitKey();
	return 0;
}