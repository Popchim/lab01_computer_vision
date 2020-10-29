#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
using namespace cv;
int main(){
  Mat image = imread("lena.png", IMREAD_UNCHANGED);
  namedWindow("Lena");
  imshow("Lena", image);
  waitKey(0);
  return 0;
}
