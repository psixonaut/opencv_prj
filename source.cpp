#include<opencv2/core.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/imgproc.hpp>
#include <iostream>
#include "erosion_and_dilation.h"

using namespace std;
using namespace cv;



int erosion_elem = 0;
int erosion_size = 0;
int dilation_elem = 0;
int dilation_size = 0;
int const max_elem = 2;
int const max_kernel_size = 21;



int main(int argc, char** argv) {
    string imagePath;
    cout << "Enter the path to the image: ";
    cin >> imagePath;
    int block_size = 3, C = 10;
    namedWindow("Tools", WINDOW_NORMAL);
    createTrackbar("Block", "Tools", &block_size, 1000);
    createTrackbar("C", "Tools", &C, 150);
    Mat img_orig;
    Mat img_redoe(260, 301, CV_8UC3, Scalar(0, 0, 0));
    Mat img_redod(260, 301, CV_8UC3, Scalar(0, 0, 0));
    img_orig = imread(imagePath);
    namedWindow("picture", WINDOW_NORMAL);
    imshow("picture", img_orig);
    Mat img_redo(260, 301, CV_8UC3, Scalar(0, 0, 0));

    while (true)
    {
        cvtColor(img_orig, img_redo, COLOR_BGR2GRAY);
        if (block_size < 3) {block_size = 3;}
        if (block_size % 2 == 0) {block_size++;}
        adaptiveThreshold(img_redo, img_redo, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, block_size, C);
        namedWindow("picture redo", WINDOW_NORMAL);
        imshow("picture redo", img_redo);
        char key = waitKey(1);
        if (key == 27) {
            break;
        }
    }

    namedWindow("Erosion and Dlation tools", WINDOW_NORMAL);
    createTrackbar("Erosion:\n 0: Rect \n 1: Cross \n 2: Ellipse", "Erosion and Dlation tools", &erosion_elem, max_elem);
    createTrackbar("Kernel size:\n 2n +1", "Erosion and Dlation tools", &erosion_size, max_kernel_size);

    while (true)
    {
        Erosion(erosion_elem, erosion_size, img_redo, img_redoe);
        char key = waitKey(1);
        if (key == 27) {
            break;
        }
    }

    waitKey(0);
    return 0;
}
