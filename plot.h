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
	void DrawData (IplImage *image);
	void DrawData (IplImage *image, char shape);
	int window_height;
	int window_width;


	vector< vector<CvPoint2D64f> >dataset;	
	
	//color
	CvScalar backgroud_color;
	CvScalar axis_color;
	CvScalar text_color;

	
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
	
//	void plot(int *x, int *y, size_t Cnt, CvScalar color);
//	void plot(float *x, float *y, size_t Cnt, CvScalar color);
//	void plot(double *x, double *y, size_t Cnt, CvScalar color);

	template<class T>
	void plot(T *x, T *y, size_t Cnt, CvScalar color);
	
	
	//l Line
	//r rectange 
	//c circle 
	//p point
	template<class T>
	void plot(T *x, T *y, size_t Cnt, CvScalar color, char shape);
	
	
	
	void xlabel(string xlabel_name, CvScalar label_color);
	void ylabel(string ylabel_name, CvScalar label_color);
	//清空图片上的数据
	void clear();
	void title(string title_name);
	
	Plot();
	~Plot();
		
};



//implement
//采用范型设计，因此将实现部分和声明部分放在一个文件中
Plot::Plot()
{
	this->border_size = 30;
	this->window_height = 600;
	this->window_width = 600;;
	this->Figure = cvCreateImage(cvSize(this->window_height, this->window_width),IPL_DEPTH_8U, 3);
	memset(Figure->imageData, 255, sizeof(unsigned char)*Figure->widthStep*Figure->height);
	
	//color
	this->backgroud_color = CV_RGB(255,255,255);
	this->axis_color = CV_RGB(0,0,0);
	this->text_color = CV_RGB(255,0 ,0);
}

Plot::~Plot()
{

}
//void Plot::plot(int *X, int *Y, size_t Cnt, CvScalar color)
//{
//		//对数据进行存储
//	vector<CvPoint2D64f>data;
//	for(int i = 0; i < Cnt;i++)
//	{
//		data.push_back(cvPoint2D64f((double)X[i], (double)Y[i]));
//	}
//	this->dataset.push_back(data);
//	printf("data count:%d\n", this->dataset.size());
//	this->DrawData(this->Figure);
//}

//void Plot::plot(float *X, float *Y, size_t Cnt, CvScalar color)
//{
//	//对数据进行存储
//	vector<CvPoint2D64f>data;
//	for(int i = 0; i < Cnt;i++)
//	{
//		data.push_back(cvPoint2D64f((double)X[i], (double)Y[i]));
//	}
//	this->dataset.push_back(data);
//	printf("data count:%d\n", this->dataset.size());
//	this->DrawData(this->Figure);
//}

//void Plot::plot(double *X, double *Y, size_t Cnt, CvScalar color)
//{
//	//对数据进行存储
//	vector<CvPoint2D64f>data;
//	for(int i = 0; i < Cnt;i++)
//	{
//		data.push_back(cvPoint2D64f(X[i], Y[i]));
//	}
//	this->dataset.push_back(data);
//	printf("data count:%d\n", this->dataset.size());
//	this->DrawData(this->Figure);
//		
//}


//范型设计
template<class T>
void Plot::plot(T *X, T *Y, size_t Cnt, CvScalar color)
{
	//对数据进行存储
	T tempX, tempY;
	vector<CvPoint2D64f>data;
	for(int i = 0; i < Cnt;i++)
	{
		tempX = X[i];
		tempY = Y[i];
//		data.push_back(cvPoint2D64f((double)X[i], (double)Y[i]));
		data.push_back(cvPoint2D64f((double)tempX, (double)tempY));
	}
	this->dataset.push_back(data);
	printf("data count:%d\n", this->dataset.size());
	this->DrawData(this->Figure);
}

//范型设计
template<class T>
void Plot::plot(T *X, T *Y, size_t Cnt, CvScalar color, char shape)
{
	//对数据进行存储
	T tempX, tempY;
	vector<CvPoint2D64f>data;
	for(int i = 0; i < Cnt;i++)
	{
		tempX = X[i];
		tempY = Y[i];
		data.push_back(cvPoint2D64f((double)tempX, (double)tempY));
	}
	this->dataset.push_back(data);
	printf("data count:%d\n", this->dataset.size());
	
	this->DrawData(this->Figure);
}

void Plot::clear()
{
	this->dataset.clear();
	//memset(Figure->imageData, 255, sizeof(unsigned char)*Figure->widthStep*Figure->height);
}

//TODO
void Plot::plot(IplImage* image, int *x, size_t Cnt, CvScalar color)
{
	
}


void Plot::DrawAxis (IplImage *image)
{
	
	//TODO 临时颜色
//	CvScalar axis_color = CV_RGB(0,0,0);
//	CvScalar text_color = CV_RGB(0,0,0);

	CvScalar axis_color = this->axis_color;
	CvScalar text_color = this->text_color;
	
	int bs = this->border_size;		
	int h = this->window_height;
	int w = this->window_width;

	// size of graph
	int gh = h - bs * 2;
	int gw = w - bs * 2;

	// draw the horizontal and vertical axis
	// let x, y axies cross at zero if possible.
	double y_ref = this->y_min;
	if ((this->y_max > 0) && (this->y_min <= 0))
		y_ref = 0;

	int x_axis_pos = h - bs - cvRound((y_ref - this->y_min) * this->y_scale);

	cvLine(image, cvPoint(bs,     x_axis_pos), 
		           cvPoint(w - bs, x_axis_pos),
				   axis_color);
	cvLine(image, cvPoint(bs, h - bs), 
		           cvPoint(bs, h - bs - gh),
				   axis_color);

	// Write the scale of the y axis
	CvFont font;
	cvInitFont(&font,CV_FONT_HERSHEY_PLAIN,0.55,0.7, 0,1,CV_AA);

	int chw = 6, chh = 10;
	char text[16];

	// y max
	if ((this->y_max - y_ref) > 0.05 * (this->y_max - this->y_min))
	{
		snprintf(text, sizeof(text)-1, "%.1f", this->y_max);
		cvPutText(image, text, cvPoint(bs / 5, bs - chh / 2), &font, text_color);
	}
	// y min
	if ((y_ref - this->y_min) > 0.05 * (this->y_max - this->y_min))
	{
		snprintf(text, sizeof(text)-1, "%.1f", this->y_min);
		cvPutText(image, text, cvPoint(bs / 5, h - bs + chh), &font, text_color);
	}

	// x axis
	snprintf(text, sizeof(text)-1, "%.1f", y_ref);
	cvPutText(image, text, cvPoint(bs / 5, x_axis_pos + chh / 2), &font, text_color);

	// Write the scale of the x axis
	snprintf(text, sizeof(text)-1, "%.0f", this->x_max );
	cvPutText(image, text, cvPoint(w - bs - strlen(text) * chw, x_axis_pos + chh), 
		      &font, text_color);

	// x min
	snprintf(text, sizeof(text)-1, "%.0f", this->x_min );
	cvPutText(image, text, cvPoint(bs, x_axis_pos + chh), 
		      &font, text_color);
}

void Plot::DrawData (IplImage *image)
{
	this->x_min = this->x_max = this->dataset[0][0].x;
	this->y_min = this->y_max = this->dataset[0][0].y;
	
	int bs = this->border_size;
	for(size_t i = 0; i < this->dataset.size(); i++)
	{
		for(size_t j = 0; j < this->dataset[i].size(); j++)
		{
			if(this->dataset[i][j].x < this->x_min)
			{
				this->x_min = this->dataset[i][j].x;
			}else if(this->dataset[i][j].x > this->x_max)
			{
				this->x_max = this->dataset[i][j].x;
			}
		
			if(this->dataset[i][j].y < this->y_min)
			{
				this->y_min = this->dataset[i][j].y;
			}else if(this->dataset[i][j].y > this->y_max)
			{
				this->y_max = this->dataset[i][j].y;
			}
		}
	}
	double x_range = this->x_max - this->x_min;
	double y_range = this->y_max - this->y_min;
	this->x_scale = (image->width - bs*2)/x_range;
	this->y_scale = (image->height- bs*2)/y_range;
	
	
	//清屏
	memset(image->imageData, 255, sizeof(unsigned char)*Figure->widthStep*Figure->height);
	//绘制坐标系 TODO如果需要绘制多做数据时，此处需要修改
	this->DrawAxis(image);
	
	printf("x_range: %f y_range: %f\n", x_range, y_range);
	//绘制点
	double tempX, tempY;
	CvPoint prev_point, next_point;
	for(size_t i = 0; i < this->dataset.size(); i++)
	{
		printf("dataset[i].size(): %d\n", dataset[i].size());
		for(size_t j = 0; j < this->dataset[i].size(); j++)
		{
			tempX = (int)((this->dataset[i][j].x - this->x_min)*this->x_scale);
			tempY = (int)((this->dataset[i][j].y - this->y_min)*this->y_scale);
			next_point = cvPoint(bs + tempX, image->height - (tempY + bs));
	//		cvCircle(image, next_point, 1,CV_RGB(255,0,0),1,CV_AA);		
			// draw a line between two points
			if (j >= 1)
			{
				cvLine(image, prev_point, next_point, CV_RGB(255,0,0), 1, CV_AA);
			}		
			prev_point = next_point;
		}
	}	
}

#endif
