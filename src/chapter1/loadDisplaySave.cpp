 #include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <stdio.h>
#include <iostream>

using namespace std;
using namespace cv;



int main()
{
    Mat image= cv::imread("puppy.bmp",IMREAD_GRAYSCALE); // read an input image
	cout << "This image has " << image.channels() << " channel(s)";
	if (image.empty()) { // error handling
	// no image has been created...
	// possibly display an error message
	// and quit the application
		cout<< "no image has been created..." << endl;
	}

	// define the window (optional)
	cv::namedWindow("Original Image");
	// show the image
	cv::imshow("Original Image", image);
	std::cout << "This image is " << image.rows << " x " << image.cols<< std::endl;

	cv::Mat result; // we create
	cv::flip(image,result,0);
	//another empty image
	//positive for horizontal
	//0 for vertical,negative for both
	cv::namedWindow("Output Image"); // the output window
	cv::imshow("Output Image", result);
	cv::imwrite("output.bmp", result); // save result
	waitKey(0);
    return 0;
}

