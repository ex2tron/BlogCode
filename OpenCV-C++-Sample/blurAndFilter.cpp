/* ƽ���˲�����
 * �����˲��������˲�����ֵ�˲�����˹�˲�
 * �������˲�����ֵ�˲���˫���˲�
 * ex2tron 2017��5��31��
 * http://ex2tron.lofter.com
 * �ٷ��ĵ���http://www.opencv.org.cn/opencvdoc/2.3.2/html/doc/tutorials/imgproc/gausian_median_blur_bilateral_filter/gausian_median_blur_bilateral_filter.html#smoothing
 */
#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	//�Ҷ�ͼ����
	Mat srcImage = imread("Lena.png", CV_LOAD_IMAGE_GRAYSCALE);
	imshow("ԭͼ", srcImage);

	//�����˲�
	Mat boxFilterImage;
	boxFilter(srcImage, boxFilterImage, -1, Size(5, 5));
	imshow("�����˲�Ч��ͼ", boxFilterImage);

	//��ֵ�˲�
	Mat blurImage;
	blur(srcImage, blurImage, Size(7, 7));
	imshow("��ֵ�˲�Ч��ͼ", blurImage);

	//��˹�˲�
	Mat gaussImage;
	GaussianBlur(srcImage, gaussImage, Size(5, 5), 0, 0);
	imshow("��˹�˲�Ч��ͼ", gaussImage);


	/* �������˲� */
	// ��ֵ�˲���
	//����λ����http://baike.baidu.com/link?url=fiRF2gifeQddJEXT4XnPbS0Z4ZM-2F7OlLcsHlOzYnAoxCTnUVzzL6ppxkCw9JCaAcP9vhmcNNfcaGBMCmGQfcXHR9deYWvapcdxcONpBji
	Mat medianImage;
	medianBlur(srcImage, medianImage, 7);
	imshow("��ֵ�˲�Ч��ͼ", medianImage);

	//˫���˲�
	Mat bilateralImage;
	bilateralFilter(srcImage, bilateralImage, 25, 25 * 2, 25 / 2);
	imshow("˫���˲�Ч��ͼ", bilateralImage);

	waitKey();
	return 0;
}