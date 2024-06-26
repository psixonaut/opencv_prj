#include "erosion_and_dilation.h"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
using namespace cv;
using namespace std;



int Erosion(int erosion_elem, int erosion_size, Mat src, Mat erosion_dst)
{
	int erosion_type = 0;
	if (erosion_elem == 0) { erosion_type = MORPH_RECT; }
	else if (erosion_elem == 1) { erosion_type = MORPH_CROSS; }
	else if (erosion_elem == 2) { erosion_type = MORPH_ELLIPSE; }

	Mat element = getStructuringElement(erosion_type,
		Size(2 * erosion_size + 1, 2 * erosion_size + 1),
		Point(erosion_size, erosion_size));

	erode(src, erosion_dst, element);
	namedWindow("Erosion", WINDOW_NORMAL);
	imshow("Erosion", erosion_dst);
	return 0;
}

int Dilation(int dilation_elem, int dilation_size, Mat src, Mat dilation_dst)
{
	int dilation_type = 0;
	if (dilation_elem == 0) { dilation_type = MORPH_RECT; }
	else if (dilation_elem == 1) { dilation_type = MORPH_CROSS; }
	else if (dilation_elem == 2) { dilation_type = MORPH_ELLIPSE; }

	Mat element = getStructuringElement(dilation_type,
		Size(2 * dilation_size + 1, 2 * dilation_size + 1),
		Point(dilation_size, dilation_size));

	dilate(src, dilation_dst, element);
	namedWindow("Dlation", WINDOW_NORMAL);
	imshow("Dilation", dilation_dst);
	return 0;
}

