#ifndef _PLOT_H
#define _PLOT_H
#include"cv.h"
#include"highgui.h"
#include <cmath>
#include <iostream>
#include<vector>

using namespace cv;
using namespace std;

class Plot
{
	private:
	
	void DrawAxis (IplImage *image);
	int window_height;
	int window_width;

	
	public:
	IplImage* Figure;

	
	// manual or automatic range
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
		
	//显示范围
	void plot(IplImage* image, int *x, size_t Cnt, CvScalar color);
	

	void plot(IplImage* image, int *x, int *y, size_t Cnt, CvScalar color);
	
	void xlabel(string xlabel_name, CvScalar label_color);
	void ylabel(string ylabel_name, CvScalar label_color);
	//清空图片上的数据
	void clear();
	void title(string title_name);
	
	Plot();
	~Plot();
	
	
};
	
#endif
