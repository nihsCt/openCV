#include "opencv2/objdetect.hpp"
#include "opencv2/core.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/xfeatures2d.hpp"
#include "opencv2/features2d.hpp"

#include <iostream>
#include <vector>

#define FILE_PATH "lena.bmp"
#define CASCADE_PATH "haarcascade_frontalface_alt2.xml"

using namespace std;
using namespace cv;
using namespace cv::xfeatures2d;

int main( int argc , char ** argv ) {

	Ptr<FastFeatureDetector> featrueDetector;
	featrueDetector = FastFeatureDetector::create(20, true, FastFeatureDetector::TYPE_9_16);

	vector<KeyPoint> features;

	Mat frame = imread(FILE_PATH);
	Mat gray;

	cvtColor(frame, gray, CV_BGR2GRAY);
	//featrueDetector->detect(gray, features, NULL);

	//drawKeypoints(frame, features, frame, Scalar(0, 0, 255), 0);



	CascadeClassifier cascade(CASCADE_PATH);
	vector<Rect> heads;


	cvtColor(frame, gray, CV_BGR2GRAY);

	cascade.detectMultiScale(gray, heads, 1.1, 2, 0|CASCADE_SCALE_IMAGE, Size(30, 30));

	for( int i = 0 ; i < (int)heads.size() ; i++ ) {

		rectangle(frame, heads[i].tl(), heads[i].br(), Scalar(255, 0, 0), 2, CV_AA, 0);
	}

	imshow("Demo", frame);
	cvWaitKey(-1);

	return EXIT_SUCCESS;
}
