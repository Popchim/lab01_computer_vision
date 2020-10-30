#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include <string>
using namespace std;
using namespace cv;
int main(){
  string item02 = "2.  Convert a color image into a grayscale image.  The command line is";
  cout << item02 << endl;
  string imagePath;
  cout << "Enter the image path: ";
  cin >> imagePath;
  size_t imagePathLength = imagePath.length();
  string imageName = imagePath.substr(0, imagePathLength - 4);
  string saveName = imageName.append("_GRAY.png");
  Mat imageBGR = imread(imagePath, IMREAD_UNCHANGED);
  Mat imageGRAY;
  cvtColor(imageBGR, imageGRAY, COLOR_BGR2GRAY);
  string windowBGR = "Your original image (BGR)";
  string windowGRAY = "The grayscale version";
  namedWindow(windowBGR);
  imshow(windowBGR, imageBGR);
  waitKey(0);
  namedWindow(windowGRAY);
  imshow(windowGRAY, imageGRAY);
  waitKey(0);
  imwrite(saveName, imageGRAY);
  return 0;
}
