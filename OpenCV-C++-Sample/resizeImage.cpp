/* �ߴ����
 * ex2tron 2017��6��5��
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

	//��СͼƬ
	Mat dstImage1;
	resize(srcImage, dstImage1, Size(srcImage.cols / 2, srcImage.rows / 2));
	imshow("��Сͼ", dstImage1);

	//�Ŵ�ͼƬ
	Mat dstImage2;
	resize(srcImage, dstImage2, Size(srcImage.cols * 2, srcImage.rows *2));
	imshow("�Ŵ�ͼ", dstImage2);

	waitKey();
	return 0;
}