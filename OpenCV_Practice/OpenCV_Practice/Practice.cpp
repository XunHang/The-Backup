#include <iostream>
#include <string>
#include <fstream>
#include "cv.h"
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/calib3d.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/viz.hpp"	//����3D�ռ���ʾ��OpenCV��
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
		const float* ptr = (const float*)(mat->data.ptr + row*mat->step);//���ָ��ĵط�������
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
		 int y = atoi("300"); //������ʼ����λ��
		 int width = atoi("200");
		 int height = atoi("200");//����ROI�Ŀ�͸�
		 int add = atoi("100");//-255~255

		 cvSetImageROI(src, cvRect(x, y, width, height));//ѡ�����Ȥ����
		 cvAddS(src, cvScalarAll(add), src);//cvScalar������ͨ��RGB��all�Ļ��Ͷ�����
		 cvResetImageROI(src);//�ָ�����ͼ�񣨲���ֻ�Ǹ���Ȥ���֣�
		 cvRectangle(src, cvPoint(100, 300), cvPoint(300, 500), cvScalar(0,0,255));//�������ο�����
		 cvCircle(src, cvPoint(200, 400), 100, cvScalar(0, 0, 255), 2);//������Բ��
		 //��һ���Լ���ˮӡ:-)
		 CvFont font;
		 cvInitFont(&font, CV_FONT_HERSHEY_SIMPLEX, 0.5, 0.5,0,1,8);
		 cvPutText(src, "Made By Lawliet.", cvPoint(0,11), &font, cvScalar(255, 255, 255));

		 cvNamedWindow("Rio_Add", 1);//������Ҫ��ͼ����ʾ�ľ��Ӷ�Ӧ�÷������ǰ��
		 cvShowImage("Rio_Add", src);

		 cvWaitKey(0);
		 cvReleaseImage(&src);
		 cvDestroyAllWindows;
	 
	 return 0;
}