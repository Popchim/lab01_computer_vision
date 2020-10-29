#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include <string>
using namespace std;
using namespace cv;
int main(){
  string item01 = "1.  Load an image by reading it from a file";
  cout << item01 << endl;
  string imagePath;
  cout << "Enter the image path: ";
  cin >> imagePath;
  Mat image = imread(imagePath, IMREAD_UNCHANGED);
  namedWindow(item01);
  imshow(item01, image);
  waitKey(0);
  return 0;
}
