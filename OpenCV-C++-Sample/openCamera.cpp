/* ������ͷ�򱾵���Ƶ
 * ex2tron 2017��5��28��
 * http://ex2tron.lofter.com
 */
#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	//������ͷ
	VideoCapture capture(0);
	//�򿪱�����Ƶ
	//VideoCapture capture("D://ex2tron//Videos//Neon_Sizzle.mp4");
	
	while (true)
	{
		Mat frame;
		capture >> frame;
		imshow("Camera", frame);

		//����ESC���˳�
		char key = waitKey(30);
		if (key == 27) break;
	}

	waitKey(0);
	return 0;
}