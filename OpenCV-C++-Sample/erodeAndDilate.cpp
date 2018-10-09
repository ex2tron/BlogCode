/* ��ʴ������ʾ��
 * OpenCV�ж�����԰�ɫ�����Ĳ���
 * ex2tron 2017��5��31��
 * http://ex2tron.lofter.com
 * �ٷ��ĵ���http://www.opencv.org.cn/opencvdoc/2.3.2/html/doc/tutorials/imgproc/erosion_dilatation/erosion_dilatation.html
 */
#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	//�Ҷ�ͼ����
	Mat srcImage = imread("Lena.png", CV_LOAD_IMAGE_GRAYSCALE);
	imshow("ԭͼ", srcImage);

	//���Ͳ���
	Mat element = getStructuringElement(MORPH_RECT, Size(3, 3));
	Mat dilateImage;
	dilate(srcImage, dilateImage, element);
	imshow("���ͺ��ͼ", dilateImage);

	//��ʴ����
	Mat elementErode = getStructuringElement(MORPH_RECT, Size(3, 3));
	Mat erodeImage;
	erode(srcImage, erodeImage, element);
	imshow("��ʴ���ͼ", erodeImage);

	waitKey();
	return 0;
}