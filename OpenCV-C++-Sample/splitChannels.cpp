/* ��ɫͨ������ͺϲ�
 * ex2tron 2017��5��28��
 * http://ex2tron.lofter.com
 */
#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	Mat srcImage = imread("Lena.png");

	vector<Mat> channels;
	split(srcImage, channels);

	//OpenCV:BGR˳��
	imshow("Blue Channel", channels[0]);
	imshow("Green Channel", channels[1]);
	imshow("Red Channel", channels[2]);
	//��������ķ���ͨ��������
	//Mat blueChannel = channels.at(0);
	//Mat greenChannel = channels.at(1);
	//Mat redChannel = channels.at(1);

	//�ϲ���ɫͨ����
	Mat dstImage;
	merge(channels, dstImage);
	imshow("remerge image", dstImage);

	waitKey(0);
	return 0;
}