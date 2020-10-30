#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include <string>
using namespace std;
using namespace cv;
void onTrackbar(int pos, void *dat){
  void **data = static_cast<void**>(dat);
  Mat& image = *(static_cast<Mat*>(data[0]));
  Mat& changingImage = *(static_cast<Mat*>(data[1]));
  string& windowName = *(static_cast<string*>(data[2]));
  for( int y = 0; y < image.rows; y++ ) {
    for( int x = 0; x < image.cols; x++ ) {
       for( int c = 0; c < image.channels(); c++ ) {
          changingImage.at<Vec3b>(y,x)[c] = saturate_cast<uchar>(image.at<Vec3b>(y,x)[c] + pos - 255);
       }
    }
  }
  imshow(windowName, changingImage);
}
int main(){
  string item03 = "3.  Change the brightness of the color image.  Add a trackbar in the output window tomodify the brightness parameter";
  cout << item03 << endl;
  string imagePath;
  cout << "Enter the image path: ";
  cin >> imagePath;
  Mat image = imread(imagePath, IMREAD_UNCHANGED);
  Mat changingImage(image.rows, image.cols, CV_8UC3);
  string windowName = "3.  Change the brightness of the color image.  Add a trackbar in the output window tomodify the brightness parameter";
  void *data[3];
  data[0] = &image;
  data[1] = &changingImage;
  data[2] = &windowName;
  namedWindow(windowName);
  imshow(windowName, image);
  int brightnessValue = 255;
  createTrackbar("Brightness Trackbar", windowName, &brightnessValue, 511, onTrackbar, data);
  waitKey(0);
  return 0;
}
