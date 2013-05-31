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
	//plot.clear();
	
	
	//如何在一幅图中绘制多组数据？每次绘制的同时还对数据进行存储？
	for(size_t i = 0; i < Cnt; i++)
	{
		X[i] = i;
		Y[i] = 5*i - 20;
	}
	plot.plot(plot.Figure, X, Y, Cnt, color);
	cvShowImage("hello", plot.Figure);
	cvWaitKey(0);
	
	for(size_t i = 0; i < Cnt; i++)
	{
		X[i] = i;
		Y[i] = -5*i - 20;
	}
	plot.plot(plot.Figure, X, Y, Cnt, color);
	cvShowImage("hello", plot.Figure);
	cvWaitKey(0);
	
	for(int i = 0; i < Cnt; i++)
	{
		X[i] = i;
		Y[i] = 20*sin(i);
	}
	plot.plot(plot.Figure, X, Y, Cnt, color);
	cvShowImage("hello", plot.Figure);
	cvWaitKey(0);
	
	
	
	return 0;
}

