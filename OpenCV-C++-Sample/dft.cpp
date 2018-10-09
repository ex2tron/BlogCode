/* ��ɢ����Ҷ�任��ʾ
 * ex2tron 2017��5��30��
 * http://ex2tron.lofter.com
 * �ٷ��ĵ���http://www.opencv.org.cn/opencvdoc/2.3.2/html/doc/tutorials/core/discrete_fourier_transform/discrete_fourier_transform.html?highlight=dft
*/
#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;


int main()
{
	//�Ҷ�ͼ��
	Mat srcImage = imread("Lena.png", CV_LOAD_IMAGE_GRAYSCALE);

	//��ɢ����Ҷ�任�������ٶ���ͼƬ�ĳߴ�ϢϢ��ء���ͼ��ĳߴ���2�� 3��5��������ʱ�������ٶ����
	int m = getOptimalDFTSize(srcImage.rows);
	int n = getOptimalDFTSize(srcImage.cols);
	// �ڱ�Ե���0
	Mat padded;
	copyMakeBorder(srcImage, padded, 0, m - srcImage.rows, 0, n - srcImage.cols, BORDER_CONSTANT, Scalar::all(0));

	//Ϊ����Ҷ�任�Ľ��(ʵ�����鲿)����洢�ռ�
	Mat planes[] = { Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F) };
	Mat complexI;
	merge(planes, 2, complexI);

	//������ɢ����Ҷ�任
	dft(complexI, complexI);

	//������ת��Ϊ����
	split(complexI, planes);
	// planes[0] = Re(DFT(I), planes[1] = Im(DFT(I))
	//magnitude:����x��y�ķ�ֵ
	magnitude(planes[0], planes[1], planes[0]);
	Mat magnitudeImage = planes[0];

	//�����߶�����
	magnitudeImage += Scalar::all(1);
	log(magnitudeImage, magnitudeImage);

	//���к��طֲ�����ͼ����
	magnitudeImage = magnitudeImage(Rect(0, 0, magnitudeImage.cols&-2, magnitudeImage.rows&-2));
	int cx = magnitudeImage.cols / 2;
	int cy = magnitudeImage.rows / 2;

	Mat q0(magnitudeImage, Rect(0, 0, cx, cy));   // ����
	Mat q1(magnitudeImage, Rect(cx, 0, cx, cy));  // ����
	Mat q2(magnitudeImage, Rect(0, cy, cx, cy));  // ����
	Mat q3(magnitudeImage, Rect(cx, cy, cx, cy)); // ����

	// �������� (���Ϻ����½���)
	Mat tmp;
	q0.copyTo(tmp);
	q3.copyTo(q0);
	tmp.copyTo(q3);

	// �������� (���Ϻ����½���)
	q1.copyTo(tmp);
	q2.copyTo(q1);
	tmp.copyTo(q2);

	//��һ��
	//��float���͵ľ���ת��������ʾͼ��Χfloat [0�� 1]
	normalize(magnitudeImage, magnitudeImage, 0, 1, CV_MINMAX);

	//��ʾ����ͼ��
	imshow("Ƶ�׷�ֵ", magnitudeImage);

	waitKey(0);
	return 0;
}