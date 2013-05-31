// Matlab style plot functions for OpenCV by Changbo (zoccob@gmail).

#include "cv.h"
#include "highgui.h"
#include "plot.h"
#include<iostream>

int main(int argc, char* argv[])
{
	const int Cnt = 100;
	int X[Cnt] = {0};
	int Y[Cnt] = {0};
	for(size_t i = 0; i < Cnt; i++)
	{
		X[i] = i;
		Y[i] = 4*i - 20;
	}
	
	cvNamedWindow("hello",1);
	Plot plot;
	CvScalar color = CV_RGB(255, 0, 0);
	plot.plot(plot.Figure, X, Y, Cnt, color);
	cvShowImage("hello", plot.Figure);
	cvWaitKey(0);
	
	plot.clear();
	
	cvShowImage("hello", plot.Figure);
	cvWaitKey(0);
	
	return 0;
}

