/* ��ͼƬ����ʾ
 * ex2tron 2017��5��28��
 * http://ex2tron.top
 * �ٷ��ĵ���http://www.opencv.org.cn/opencvdoc/2.3.2/html/doc/user_guide/ug_mat.html#id2
 */
#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	//��ͼƬ����ʾ
	Mat srcImage = imread("Lena.png");

	imshow("Original Image", srcImage);
	
	waitKey(0);
	return 0;
}