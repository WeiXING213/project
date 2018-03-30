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
	int width = (int)cap->get(cv::CAP_PROP_FRAME_WIDTH);
	int height = (int)cap->get(cv::CAP_PROP_FRAME_HEIGHT);
	int fps = (int)cap->get(cv::CAP_PROP_FPS);
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
	
	cv::cvtColor(_frameOriginal, _frameProcessed, cv::COLORMAP_RAINBOW);
	QImage dest((const uchar *)_frameProcessed.data, _frameProcessed.cols, _frameProcessed.rows, _frameProcessed.step, QImage::Format_RGB888);
	dest.bits();
	
	QPainter p(&dest);
	p.setPen(QPen(Qt::white));
	p.setFont(QFont("Times", 12, QFont::Bold));
	p.drawText(dest.rect(), Qt::AlignBottom, QTime::currentTime().toString("AP hh:mm:ss:zzz"));


	emit sendFrame(dest);
	
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

