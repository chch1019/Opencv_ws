#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

// function to create an Image
Mat createImage()
{
    // generates a new gray image with a default value for all its pixels:
    Mat image(500, 500, CV_8U, 50);
    return image;
}
int main()
{
    // create a new image made of 240rX320c
    Mat image1(240, 320, CV_8U, 100);
    imshow("Image_1", image1);
    waitKey(0);

    // re-allocate a new image
    image1.create(200, 200, CV_8U);
    imshow("Image_1", image1);
    waitKey(0);

    // creates red color image
    Mat image2(240, 320, CV_8UC3, Scalar(0, 0, 255));
    imshow("Image_2", image2);
    waitKey(0);

    // read amn image
    Mat image3 = imread("puppy.bmp");

    // all these images points to same data block
    Mat image4(image3);
    image1 = image3;

    // these images are new copies of the source image
    image3.copyTo(image2);
    Mat image5 = image3.clone();

    // transform the image for testing
    cv::flip(image3, image3, 1);

    // check which images have been affected by the processing
    imshow("Image 3", image3);
    imshow("Image 1", image1);
    imshow("Image 2", image2);
    imshow("Image 4", image4);
    imshow("Image 5", image5);
    waitKey(0); // wait for a key pressed

    // Generate new gray mat using the function
    Mat gray = createImage();
    imshow("Grgay ", gray);
    waitKey(0);

    //read image in gray scale
    image1 = imread("puppy.bmp", IMREAD_GRAYSCALE);

    // convert the image into a floating point image [0,1]
    image1.convertTo(image2, CV_32F, 1 / 255.0, 0.0);
    imshow("Image_Float", image2);
    

    Matx33d matrix(3.0, 2.0, 1.0,
                   2.0, 1.0, 3.0,
                   1.0, 2.0, 3.0);

    Matx31d vector(5.0, 1.0, 3.0);

    Matx31d result = matrix * vector;

    cout << result << endl;
    waitKey(0);
    return 0;
}