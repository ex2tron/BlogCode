/* ��ɫ�ռ�����
 * ex2tron 2017��5��28��
 * http://ex2tron.lofter.com
 */
#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;

//lut:look up table
Mat lut(1, 256, CV_8U);


//��ʼ����
void InitTable(int div)
{
	//����һ�����ұ�  
	uchar table[256];
	for (int i = 0; i < 256; i++)
		table[i] = i / div * div;

	//ΪMat�������Ԫ��ֵ  
	uchar *p = lut.data;
	for (int i = 0; i < 256; i++)
		p[i] = table[i];
}

int main()
{
	InitTable(20);

	Mat srcImage = imread("Lena.png");
	Mat dstImage;
	dstImage.create(srcImage.size(), srcImage.type());

	//���ұ����  
	LUT(srcImage, lut, dstImage);

	imshow("ԭͼ", srcImage);
	imshow("��ɫ�ռ������ͼ", dstImage);

	waitKey(0);
	return 0;
}