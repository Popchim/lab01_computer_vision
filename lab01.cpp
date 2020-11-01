#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "iostream"
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
using namespace cv;
void onTrackbar(int pos, void *dat){
  if (pos != 0) {
  void **data = static_cast<void**>(dat);
    const Mat image = *(static_cast<Mat*>(data[0]));
    Mat& changingImage = *(static_cast<Mat*>(data[1]));
    string& windowName = *(static_cast<string*>(data[2]));
    blur(image, changingImage, Size(pos, pos));
    imshow(windowName, changingImage);
  }
}
int main(){
  string item05 = "Filter a color image/ a grayscale image usingaverage filter operator. Add a trackbarin the output window to modify the kernel size parameter";
  cout << item05 << endl;
  string imagePath;
  cout << "Enter the image path: ";
  cin >> imagePath;
  Mat image = imread(imagePath, IMREAD_UNCHANGED);
  Mat changingImage(image);
  void *data[3];
  data[0] = &image;
  data[1] = &changingImage;
  data[2] = &item05;
  namedWindow(item05);
  imshow(item05, image);
  int kernelSize = 1;
  createTrackbar("Kernel Size Trackbar", item05, &kernelSize, max(image.rows, image.cols), onTrackbar, data);
  waitKey(0);
  return 0;
}
