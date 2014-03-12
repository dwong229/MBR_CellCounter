#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
//#include "config.h"
#include "cellcount.h"
#include <opencv2/core/core.hpp>

using namespace std;
using namespace cv;

/// Global variables

int threshold_value = 0;
int threshold_type = 3;;
int const max_value = 255;
int const max_type = 4;
int const max_BINARY_value = 255;

Mat imOrigG, imG, dst;
char* window_name = "Threshold Demo";

char* trackbar_type = "Type: \n 0: Binary \n 1: Binary Inverted \n 2: Truncate \n 3: To Zero \n 4: To Zero Inverted";
char* trackbar_value = "Value";

/// Function headers
void Threshold_Demo( int, void* );

int main(int argc, char **argv)
{
    //load image
//    Mat imOrigG = imread("/home/rosbuild_ws/trial1/src/im_000031.tif", CV_LOAD_IMAGE_GRAYSCALE);
    Mat imOrigG = imread("/home/denise/rosbuild_ws/trial1/src/bacteriacounttest.tiff", CV_LOAD_IMAGE_GRAYSCALE);

    imG = imOrigG.clone();

    // Create a window to display results
    namedWindow( window_name, CV_WINDOW_AUTOSIZE );

    // Create Tracker to choose type of Threshold

    createTrackbar( trackbar_type,
                  window_name, &threshold_type,
                  max_type, Threshold_Demo );

    createTrackbar( trackbar_value,
                  window_name, &threshold_value,
                  max_value, Threshold_Demo );

    /// Call the function to initialize
    Threshold_Demo( 0, 0 );

    /// Wait until user finishes program
    while(true)
    {
        int c;
        c = waitKey( 20 );
        if( (char)c == 27 )
        { break; }
    }

}

    /* display image;
    imwrite(IMAGES_PATH "imThresh.jpg", imThresh);
    cout << "image write complete" << endl;
    namedWindow("thresh",WINDOW_FLAGS);
    imshow("thresh",imThresh,);
    waitKey(0);
    */
/**
 * @function Threshold_Demo
 */
void Threshold_Demo( int, void* )
{
  /* 0: Binary
     1: Binary Inverted
     2: Threshold Truncated
     3: Threshold to Zero
     4: Threshold to Zero Inverted
   */

  threshold( imG, dst, threshold_value, max_BINARY_value,threshold_type );

  imshow( window_name, dst );
}
