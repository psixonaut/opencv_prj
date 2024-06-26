#pragma once
#include<opencv2/core.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;


int Erosion(int erosion_elem, int erosion_size, Mat src, Mat erosion_dst);
int Dilation(int dilation_elem, int dilation_size, Mat src, Mat dilation_dst);
int refactor(int erosion_elem, int erosion_size, int dilation_elem, int dilation_size, int max_elem, int max_kernel_size, Mat src, Mat erosion_dst, Mat dilation_dst);