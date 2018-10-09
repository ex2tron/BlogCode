/* 颜色通道分离和合并
 * ex2tron 2017年5月28日
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

	//OpenCV:BGR顺序
	imshow("Blue Channel", channels[0]);
	imshow("Green Channel", channels[1]);
	imshow("Red Channel", channels[2]);
	//或用下面的访问通道方法：
	//Mat blueChannel = channels.at(0);
	//Mat greenChannel = channels.at(1);
	//Mat redChannel = channels.at(1);

	//合并颜色通道：
	Mat dstImage;
	merge(channels, dstImage);
	imshow("remerge image", dstImage);

	waitKey(0);
	return 0;
}