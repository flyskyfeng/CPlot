CPlot
=====
##简介
Matlab的plot函数非常的强大，进行数据显示的效果非常的好，但是经常使用Opencv的同学如果每次将计算之后的数据导入到Matlab里显示又比较麻烦，因此决定写一类似于plot的C函数，用于在OpenCV中进行数据显示。设计一个Plot类，项目位于github上[https://github.com/libing64/CPlot](https://github.com/libing64/CPlot "CPlot-github")

##
##主要参数
  private:
	//窗口大小
	int window_height;
	int window_width;
	
	vector< vector<CvPoint2D64f> >dataset;//一个Figure中显示的数据集
	public:
	IplImage* Figure;// 用于显示的图片
	// manual or automatic range
	//显示比例和范围
	bool custom_range_y;
	double y_max;
	double y_min;
	double y_scale;
	

	bool custom_range_x;
	double x_max;
	double x_min;
	double x_scale;

	//边界大小
	int border_size;
##常用函数
	//分别加上几种数据类型，你可以尝试改为C++的泛型设计
	void plot(int *x, int *y, size_t Cnt, CvScalar color);
	void plot(float *x, float *y, size_t Cnt, CvScalar color);
	void plot(double *x, double *y, size_t Cnt, CvScalar color);

	//添加标签
	void xlabel(string xlabel_name, CvScalar label_color);
	void ylabel(string ylabel_name, CvScalar label_color);

	//清空数据
	void clear();

	//添加title
	void title(string title_name);
##实现
到项目主页上Plot.cpp中有完整的代码实现
[https://github.com/libing64/CPlot](https://github.com/libing64/CPlot "CPlot-github")
##范例
	#include "cv.h"
	#include "highgui.h"
	#include "plot.h"
	#include<iostream>
	
	int main(int argc, char* argv[])
	{
		const int Cnt = 100;
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
		plot.plot(X, Y, Cnt, color);
		cvShowImage("hello", plot.Figure);
		cvWaitKey(0);
		//plot.clear();
	
		for(int i = 0; i < Cnt; i++)
		{
			X[i] = (double)i;
			Y[i] = (double)(5*i - 20);
		}
		plot.plot(X, Y, Cnt, color);
		cvShowImage("hello", plot.Figure);
		cvWaitKey(0);
	
		for(int i = 0; i < Cnt; i++)
		{
			X[i] = (double)i;
			Y[i] = (double)(-5*i - 20);
		}
		plot.plot(X, Y, Cnt, color);
		cvShowImage("hello", plot.Figure);
		cvWaitKey(0);
	
	
		for(int i = 0; i < Cnt; i++)
		{
			X[i] = (double)i;
			Y[i] = (double)(50*sin(i*0.1));
		}
		plot.plot(X, Y, Cnt, color);
		cvShowImage("hello", plot.Figure);
		cvWaitKey(0);
	
		int X2[Cnt] = {0};
		int Y2[Cnt] = {0};
		for(int i = 0; i < Cnt; i++)
		{
			X2[i] = i;
			Y2[i] = -100*i - 20;
		}
		plot.clear();
		plot.plot(X2, Y2, Cnt/2, color);
		cvShowImage("hello", plot.Figure);
		cvWaitKey(0);
	
		return 0;
	}

##显示效果
![](https://github.com/libing64/CPlot/blob/master/plot.jpg)

##如何自己优化

如果感觉这些代码并不够优，你可以自己去优化它

* 注册一个github的账号
* 进入项目主页 [https://github.com/libing64/CPlot](https://github.com/libing64/CPlot "CPlot-github")
* 点击fork
* 进入自己的项目主页git clone git git@github.com:yourname/CPlot.git
* 修改代码并commit
 	
	git commit -m "commit"
* 当感觉自己写的比较优秀的时候可以，与原始项目合并，点击pull 
	

[CPlot](https://github.com/libing64/CPlot)

##TODO##
不同形式的显示，如点、圆、直线、虚线等
