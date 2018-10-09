/* �������ͱղ���
 * ���������ȸ�ʴ������
 * �ղ����������ͺ�ʴ
 * OpenCV�ж�����԰�ɫ�����Ĳ���
 * ex2tron 2017��6��1��
 * http://ex2tron.lofter.com
 * �ٷ��ĵ���http://www.opencv.org.cn/opencvdoc/2.3.2/html/doc/tutorials/imgproc/opening_closing_hats/opening_closing_hats.html
 */
#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;

int gOpenCloseNum = 0;
int gMaxIterationNum = 10;
Mat gsrcImage, gDstImage;

static void onOpenClose(int, void*)
{
	int offset = gOpenCloseNum - gMaxIterationNum;
	int absoluteOffset = offset > 0 ? offset : -offset;

	Mat element = getStructuringElement(MORPH_RECT, Size(absoluteOffset * 2 + 1, absoluteOffset * 2 + 1), Point(absoluteOffset, absoluteOffset));

	//ִ�п�������ղ���
	if (offset < 0)
		morphologyEx(gsrcImage, gDstImage, MORPH_OPEN, element);
	else
		morphologyEx(gsrcImage, gDstImage, MORPH_CLOSE, element);

	imshow("������ͱ�����", gDstImage);
}

int main()
{
	//�Ҷ�ͼ����
	gsrcImage = imread("D://ex2tron//Documents//01. Build//ImageProcess//Lena.png", CV_LOAD_IMAGE_GRAYSCALE);
	imshow("ԭͼ", gsrcImage);

	namedWindow("������ͱ�����");
	createTrackbar("����ֵ", "������ͱ�����", &gOpenCloseNum, gMaxIterationNum * 2 + 1, onOpenClose);
	onOpenClose(0, 0);

	waitKey();
	return 0;
}