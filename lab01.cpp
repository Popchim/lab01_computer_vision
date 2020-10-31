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
  void **data = static_cast<void**>(dat);
  Mat& image = *(static_cast<Mat*>(data[0]));
  Mat& changingImage = *(static_cast<Mat*>(data[1]));
  string& windowName = *(static_cast<string*>(data[2]));
  GaussianBlur(image, changingImage, Size(pos*2 + 1, pos*2 + 1), 1);
  imshow(windowName, changingImage);
}
int main(){
  string item06 = "Filter a color image/ a grayscale image using Gaussian filter operator. Add a trackbarin the output window to modify the kernel size parameter";
  cout << item06 << endl;
  string imagePath;
  cout << "Enter the image path: ";
  cin >> imagePath;
  Mat image = imread(imagePath, IMREAD_UNCHANGED);
  Mat changingImage;
  void *data[3];
  data[0] = &image;
  data[1] = &changingImage;
  data[2] = &item06;
  namedWindow("original");
  imshow("original", image);
  namedWindow(item06);
  imshow(item06, image);
  int kernelSize = 0;
  createTrackbar("Kernel Size Trackbar", item06, &kernelSize, int(max(image.rows, image.cols)/2-1), onTrackbar, data);
  waitKey(0);
  return 0;
}
