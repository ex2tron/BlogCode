/* ����������������ֵ�����ж�ֵ��
 * ex2tron 2017��5��28��
 * http://ex2tron.lofter.com
 * �ٷ��ĵ���http://www.opencv.org.cn/opencvdoc/2.3.2/html/doc/tutorials/imgproc/threshold/threshold.html?highlight=threshold
 */
#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;

#define WINDOW_NAME "Original Image"


Mat srcImage, dstImage;

//trackBar�ص�����
void onTrackBar(int thValue, void *)
{
	//��ֵ�ָ�
	threshold(srcImage, dstImage, thValue, 255, 0);
	imshow(WINDOW_NAME, dstImage);
}

int main()
{
	//�ԻҶ�ͼ��ʽ��ͼƬ
	srcImage = imread("Lena.png",CV_LOAD_IMAGE_GRAYSCALE);

	int thValue = 80;
	namedWindow(WINDOW_NAME, WINDOW_NORMAL);
	createTrackbar("threshold", WINDOW_NAME, &thValue, 255, onTrackBar);
	onTrackBar(thValue, 0);

	waitKey(0);
	return 0;
}