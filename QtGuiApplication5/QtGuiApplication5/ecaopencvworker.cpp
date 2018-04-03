#include "ecaopencvworker.h"
#include "qpainter.h"
#include <QTime>


EcaOpenCvWorker::EcaOpenCvWorker(QObject *parent) :
	QObject(parent),
	status(false),
	toggleStream(false),
	binaryThresholdEnable(false),
	binaryThreshold(127)
{
	cap = new cv::VideoCapture("rtsp://192.168.1.1:9099/stream");
	
	//debug
	int width = (int)cap->get(cv::CAP_PROP_FRAME_WIDTH);
	int height = (int)cap->get(cv::CAP_PROP_FRAME_HEIGHT);
	int fps = (int)cap->get(cv::CAP_PROP_FPS);
	recordingFlag = false;
	//todo fps, with openCV can't always return good fps
	
	videoWriter = new cv::VideoWriter("new.avi", CV_FOURCC('H', '2', '6', '4'), 50, cv::Size(width, height));

	imageWidth = 100;
	imageheight = 100;
}

EcaOpenCvWorker::~EcaOpenCvWorker()
{
	if (cap->isOpened()) cap->release();
	delete cap;
}

void EcaOpenCvWorker::receiveGrabFrame()
{
	//if (!toggleStream) return;
	(*cap) >> _frameOriginal;
	if (_frameOriginal.empty()) return;

	process();
	
	cv::Point origin;
	origin.x = 300;
	origin.y = 500;

	
	time_t rawtime;
	time(&rawtime);
	char const *time = ctime(&rawtime);
	cv::putText(_frameOriginal, time, origin, cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar(0, 255, 255), 2, 8, 0);

	if (recordingFlag)
		videoWriter->write(_frameOriginal);


	cv::cvtColor(_frameOriginal, _frameProcessed, cv::COLORMAP_RAINBOW);

	//qt image
	QImage dest((const uchar *)_frameProcessed.data, _frameProcessed.cols, _frameProcessed.rows, _frameProcessed.step, QImage::Format_RGB888);
	dest.bits();
	//dest = dest.scaled(imageWidth, imageheight);

	emit sendFrame(dest);	
}

void EcaOpenCvWorker::setImageScale(int width, int height)
{
	imageWidth = width;
	imageheight = height;
}


void EcaOpenCvWorker::recording() {
	recordingFlag = !recordingFlag;
}	

void EcaOpenCvWorker::checkIfDeviceAlreadyOpened(const int device) {
	/*
	if (cap->isOpened()) cap->release();
	cap->open(device);
	*/
}

void EcaOpenCvWorker::process()
{
	
	

	/*if (binaryThresholdEnable) {
		cv::threshold(_frameOriginal, _frameProcessed, binaryThreshold, 255, cv::THRESH_BINARY);
	}*/
}

void EcaOpenCvWorker::receiveSetup(const int device)
{
	/*
	checkIfDeviceAlreadyOpened(device);
	if (!cap->isOpened()) {
		status = false;
		return;
	}
	status = true;
	*/
}

void EcaOpenCvWorker::receiveToggleStream() {
	toggleStream != toggleStream;
}

void EcaOpenCvWorker::receiveEnableBinaryThreshold() {
	binaryThresholdEnable = !binaryThresholdEnable;
}

void EcaOpenCvWorker::receiveBinaryThreshold(int threshold)
{
	binaryThreshold = threshold;
}

