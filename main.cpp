#include "stdafx.h"
#include <iostream>

/*
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
*/
#include "smartCpp.h"
#include "smartOpenCV.h"

using namespace std;


static void egShowImage() {

	std::string filename = "C:/smartllc/data/samples/somalian.jpg";
	exitFileNotFound(filename);
	//--------------------------------------------------------------

	// Establish Variables
	cv::Mat image;

	// Read the file "image.jpg".
	image = cv::imread(filename, CV_LOAD_IMAGE_COLOR);

	// Check for invalid input
	if (!image.data)
	{
		cout << "Could not open or find the image" << std::endl;
		return;
	}

	// Create a window for display.
	cv::namedWindow("window", CV_WINDOW_AUTOSIZE);

	// Show our image inside it.
	cv::imshow("window", image);

	// Pause Execution until image window closed
	cv::waitKey(0);
}

static void egVideoPlay() {

	std::string filename = "C:/smartllc/data/samples/sample1.mp4";
	exitFileNotFound(filename);
	//--------------------------------------------------------------

	// Create a VideoCapture object and open the input file / If the input is the web camera, pass 0 instead of the video file name
	cv::VideoCapture cap;
	cap.open(filename);

	// Check if camera opened successfully
	if (!cap.isOpened()) {
		cout << "Error opening video stream or file" << endl;
		int key = getchar();
		return;
	}

	while (1) {

		cv::Mat frame;
		// Capture frame-by-frame
		cap >> frame;

		// If the frame is empty, break immediately
		if (frame.empty())
			break;

		// Display the resulting frame
		cv::imshow("Frame", frame);

		cv::waitKey(25);
		// Press  ESC on keyboard to exit
		char c = (char)cv::waitKey(25);
		if (c == 27)
			break;
	}

	// When everything done, release the video capture object
	cap.release();

	// Closes all the frames
	cv::destroyAllWindows();

}

static void VideoLive(int camera) {

	// Create a VideoCapture object and open the input file / If the input is the web camera, pass 0 instead of the video file name
	cv::VideoCapture cap(camera);

	// Check if camera opened successfully
	if (!cap.isOpened()) {
		cout << "Error opening video stream or file" << endl;
		int key = getchar();
		return;
	}

	while (1) {

		cv::Mat frame;
		// Capture frame-by-frame
		cap >> frame;

		// If the frame is empty, break immediately
		if (frame.empty())
			break;

		// Display the resulting frame
		cv::imshow("Frame", frame);

		cv::waitKey(25);
		// Press  ESC on keyboard to exit
		char c = (char)cv::waitKey(25);
		if (c == 27)
			break;
	}

	// When everything done, release the video capture object
	cap.release();

	// Closes all the frames
	cv::destroyAllWindows();
}



int main()
{

	//egShowImage();
	egVideoPlay();

	return 0;
}