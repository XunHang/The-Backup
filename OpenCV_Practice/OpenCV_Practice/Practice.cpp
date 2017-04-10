#include <iostream>
#include <string>
#include <fstream>
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

float sum(const CvMat* mat)
{
	float s = 0.0f;
	for (int row = 0; row < mat->rows; row++)
	{
		const float* ptr = (const float*)(mat->data.ptr + row*mat->step);
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