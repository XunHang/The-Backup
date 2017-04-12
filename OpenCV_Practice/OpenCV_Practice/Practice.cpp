#include <iostream>
#include <string>
#include <fstream>
#include "cv.h"
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/calib3d.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/viz.hpp"	//用于3D空间显示的OpenCV库
//These two libs can't be opened.
//#pragma comment(lib,"opencv_viz300d.lib")
//#pragma comment(lib,"opencv_viz300.lib")

using namespace std;
using namespace cv;
/***************************************************************************
float sum(const CvMat* mat)
{
	float s = 0.0f;
	for (int row = 0; row < mat->rows; row++)
	{
		const float* ptr = (const float*)(mat->data.ptr + row*mat->step);//这句指针的地方看不懂
		for (int col = 0; col < mat->cols; col++)
		{
			s += *ptr++;
		}
	}
	return s;
}
int main(int argc, char** argv)
{
	CvMat* mat = cvCreateMat(5, 5, CV_32FC1);
	float s = sum(mat);
	cout << s << endl;
	system("pause");
	return 0;

}
*****************************************************************/

int main(int argc, char** argv)
{
	IplImage* src = cvLoadImage("C:\\Users\\Lawliet\\Git\\Backup\\OpenCV_Practice\\OpenCV_Practice\\X64\\Lenna.png", 1);
	 
		 int x = atoi("100");
		 int y = atoi("300"); //设置起始像素位置
		 int width = atoi("200");
		 int height = atoi("200");//设置ROI的宽和高
		 int add = atoi("100");//-255~255

		 cvSetImageROI(src, cvRect(x, y, width, height));//选择感兴趣区域
		 cvAddS(src, cvScalarAll(add), src);//cvScalar有三个通道RGB，all的话就都加上
		 cvResetImageROI(src);//恢复整个图像（不再只是感兴趣部分）
		 cvRectangle(src, cvPoint(100, 300), cvPoint(300, 500), cvScalar(0,0,255));//画个矩形框起来
		 cvCircle(src, cvPoint(200, 400), 100, cvScalar(0, 0, 255), 2);//再来个圆形
		 //加一个自己的水印:-)
		 CvFont font;
		 cvInitFont(&font, CV_FONT_HERSHEY_SIMPLEX, 0.5, 0.5,0,1,8);
		 cvPutText(src, "Made By Lawliet.", cvPoint(0,11), &font, cvScalar(255, 255, 255));

		 cvNamedWindow("Rio_Add", 1);//各种需要在图中显示的句子都应该放在这句前面
		 cvShowImage("Rio_Add", src);

		 cvWaitKey(0);
		 cvReleaseImage(&src);
		 cvDestroyAllWindows;
	 
	 return 0;
}