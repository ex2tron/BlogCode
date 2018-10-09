/* �����ԱȶȺ����ȣ�g(x)=a*f(x)+b
 * a�������棺����ͼ��ĶԱȶ�
 * b��Ϊƫ�ã�����ͼ�������
 * ex2tron 2017��5��28��
 * http://ex2tron.lofter.com
 * �ٷ��ĵ���http://www.opencv.org.cn/opencvdoc/2.3.2/html/doc/tutorials/core/basic_linear_transform/basic_linear_transform.html
 */
#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;

//�ԱȶȺ�����
int gContrastValue, gBrightValue;
Mat gSrcImage, gDstImage;

void onContrastAndBright(int, void*)
{
	//����ÿһ�����صķ�ʽ
	for (int y = 0; y < gSrcImage.rows; y++)
	{
		for (int x = 0; x < gSrcImage.cols; x++)
		{
			for (int c = 0; c < 3; c++)
			{
				//���������ܳ�������ȡֵ��Χ�������� saturate_cast�Խ������ת������ȷ����Ϊ��Чֵ
				gDstImage.at<Vec3b>(y, x)[c] =saturate_cast<uchar>( gContrastValue*0.01*gSrcImage.at<Vec3b>(y, x)[c] + gBrightValue);
			}
		}
	}

	//����������һ�仰�㶨
	//gSrcImage.convertTo(gDstImage, -1, gContrastValue*0.01, gBrightValue);

	imshow("Ч��ͼ", gDstImage);
}

int main()
{
	gSrcImage = imread("Lena.png");
	gDstImage = Mat::zeros(gSrcImage.size(), gSrcImage.type());

	gContrastValue = 80;
	gBrightValue = 80;

	namedWindow("Ч��ͼ");
	createTrackbar("�Աȶ�:", "Ч��ͼ", &gContrastValue, 300, onContrastAndBright);
	createTrackbar("����:", "Ч��ͼ", &gBrightValue, 200, onContrastAndBright);
	onContrastAndBright(0, 0);

	waitKey(0);
	return 0;
}