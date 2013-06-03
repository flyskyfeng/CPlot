// Matlab style plot functions for OpenCV
//author libing64
//https://github.com/libing64/CPlot
#include "cv.h"
#include "highgui.h"
#include "plot.h"
#include<iostream>

int main(int argc, char* argv[])
{
	const int Cnt = 80;
	double X[Cnt] = {0};
	double Y[Cnt] = {0};
	for(int i = 0; i < Cnt; i++)
	{
		X[i] = (double)i;
		Y[i] = (double)4*i - 20;
	}
	
	cvNamedWindow("hello",1);
	Plot plot;
	CvScalar color = CV_RGB(255, 0, 0);
	plot.plot(X, Y, Cnt, color, 's');
	cvShowImage("hello", plot.Figure);
	cvWaitKey(0);
	//plot.clear();
	
	
	//如何在一幅图中绘制多组数据？每次绘制的同时还对数据进行存储？
	for(int i = 0; i < Cnt; i++)
	{
		X[i] = (double)i;
		Y[i] = (double)(5*i - 20);
	}
	plot.plot(X, Y, Cnt, color, '.');
	cvShowImage("hello", plot.Figure);
	cvWaitKey(0);
	
	for(int i = 0; i < Cnt; i++)
	{
		X[i] = (double)i;
		Y[i] = (double)(-5*i - 20);
	}
	plot.plot(X, Y, Cnt, color, '+');
	cvShowImage("hello", plot.Figure);
	cvWaitKey(0);
	
	
	for(int i = 0; i < Cnt; i++)
	{
		X[i] = (double)i;
		Y[i] = (double)(50*sin(i*0.1));
	}
	plot.plot(X, Y, Cnt, color, 'x');
	cvShowImage("hello", plot.Figure);
	cvWaitKey(0);
	
	for(int i = 0; i < Cnt; i++)
	{
		X[i] = (double)i;
		Y[i] = (double)(100*sin(i*0.1));
	}
	plot.plot(X, Y, Cnt, color, 'o');
	cvShowImage("hello", plot.Figure);
	cvWaitKey(0);
	
	int X2[Cnt] = {0};
	int Y2[Cnt] = {0};
	for(int i = 0; i < Cnt; i++)
	{
		X2[i] = i;
		Y2[i] = -30*i - 20;
	}
	plot.plot(X2, Y2, Cnt/2, color);
	cvShowImage("hello", plot.Figure);
	cvWaitKey(0);
	//cvSaveImage("example.jpg", plot.Figure);
	return 0;
}

