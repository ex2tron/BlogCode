/* 颜色空间缩减
 * ex2tron 2017年5月28日
 * http://ex2tron.lofter.com
 */
#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;

//lut:look up table
Mat lut(1, 256, CV_8U);


//初始化表
void InitTable(int div)
{
	//建立一个查找表  
	uchar table[256];
	for (int i = 0; i < 256; i++)
		table[i] = i / div * div;

	//为Mat矩阵添加元素值  
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

	//查找表操作  
	LUT(srcImage, lut, dstImage);

	imshow("原图", srcImage);
	imshow("颜色空间减缩后图", dstImage);

	waitKey(0);
	return 0;
}