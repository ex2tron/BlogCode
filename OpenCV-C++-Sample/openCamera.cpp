/* 打开摄像头或本地视频
 * ex2tron 2017年5月28日
 * http://ex2tron.lofter.com
 */
#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	//打开摄像头
	VideoCapture capture(0);
	//打开本地视频
	//VideoCapture capture("D://ex2tron//Videos//Neon_Sizzle.mp4");
	
	while (true)
	{
		Mat frame;
		capture >> frame;
		imshow("Camera", frame);

		//按下ESC键退出
		char key = waitKey(30);
		if (key == 27) break;
	}

	waitKey(0);
	return 0;
}