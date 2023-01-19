#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>

using namespace std;
using namespace cv;

int main()
{

    Mat image = imread("puppy.bmp");
    Mat logo = imread("smalllogo.png");

    Rect myRoi = Rect(image.cols - logo.cols, image.rows - logo.rows, // ROI coordinates
                      logo.cols, logo.rows);                          // ROI size
    // define image ROI at image bottom-right
    Mat imageROI(image, myRoi);
    // insert logo
    logo.copyTo(imageROI);

    imshow("MY ROI", image);
    waitKey(0);

    image = imread("puppy.bmp");
    imageROI = image(Rect(image.cols - logo.cols, image.rows - logo.rows,
                          logo.cols, logo.rows));
    Mat mask(logo);
    logo.copyTo(imageROI, mask);
    imshow("Image Mask logo", image);
    waitKey(0);
    return 0;
}