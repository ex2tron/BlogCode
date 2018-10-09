/* 离散傅里叶变换演示
 * ex2tron 2017年5月30日
 * http://ex2tron.lofter.com
 * 官方文档：http://www.opencv.org.cn/opencvdoc/2.3.2/html/doc/tutorials/core/discrete_fourier_transform/discrete_fourier_transform.html?highlight=dft
*/
#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;


int main()
{
	//灰度图打开
	Mat srcImage = imread("Lena.png", CV_LOAD_IMAGE_GRAYSCALE);

	//离散傅立叶变换的运行速度与图片的尺寸息息相关。当图像的尺寸是2， 3，5的整数倍时，计算速度最快
	int m = getOptimalDFTSize(srcImage.rows);
	int n = getOptimalDFTSize(srcImage.cols);
	// 在边缘添加0
	Mat padded;
	copyMakeBorder(srcImage, padded, 0, m - srcImage.rows, 0, n - srcImage.cols, BORDER_CONSTANT, Scalar::all(0));

	//为傅立叶变换的结果(实部和虚部)分配存储空间
	Mat planes[] = { Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F) };
	Mat complexI;
	merge(planes, 2, complexI);

	//进行离散傅立叶变换
	dft(complexI, complexI);

	//将复数转换为幅度
	split(complexI, planes);
	// planes[0] = Re(DFT(I), planes[1] = Im(DFT(I))
	//magnitude:计算x，y的幅值
	magnitude(planes[0], planes[1], planes[0]);
	Mat magnitudeImage = planes[0];

	//对数尺度缩放
	magnitudeImage += Scalar::all(1);
	log(magnitudeImage, magnitudeImage);

	//剪切和重分布幅度图象限
	magnitudeImage = magnitudeImage(Rect(0, 0, magnitudeImage.cols&-2, magnitudeImage.rows&-2));
	int cx = magnitudeImage.cols / 2;
	int cy = magnitudeImage.rows / 2;

	Mat q0(magnitudeImage, Rect(0, 0, cx, cy));   // 左上
	Mat q1(magnitudeImage, Rect(cx, 0, cx, cy));  // 右上
	Mat q2(magnitudeImage, Rect(0, cy, cx, cy));  // 左下
	Mat q3(magnitudeImage, Rect(cx, cy, cx, cy)); // 右下

	// 交换象限 (左上和右下交换)
	Mat tmp;
	q0.copyTo(tmp);
	q3.copyTo(q0);
	tmp.copyTo(q3);

	// 交换象限 (右上和坐下交换)
	q1.copyTo(tmp);
	q2.copyTo(q1);
	tmp.copyTo(q2);

	//归一化
	//将float类型的矩阵转换到可显示图像范围float [0， 1]
	normalize(magnitudeImage, magnitudeImage, 0, 1, CV_MINMAX);

	//显示幅度图像
	imshow("频谱幅值", magnitudeImage);

	waitKey(0);
	return 0;
}