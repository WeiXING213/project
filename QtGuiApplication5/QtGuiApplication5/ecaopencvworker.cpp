#include "ecaopencvworker.h"
#include "qpainter.h"
#include <QTime>
#include <QFileInfo>
#include <QDebug>
#include <time.h>
#include <ctime>

EcaOpenCvWorker::EcaOpenCvWorker(QObject *parent) :
	QObject(parent),
	status(false),
	toggleStream(false),
	binaryThresholdEnable(false),
	binaryThreshold(127)
{
	cap = new cv::VideoCapture("rtsp://192.168.1.1:9099/stream");
	
	//debug
	cap_width = (int)cap->get(cv::CAP_PROP_FRAME_WIDTH);
	cap_height = (int)cap->get(cv::CAP_PROP_FRAME_HEIGHT);
	//int fps = (int)cap->get(cv::CAP_PROP_FPS);
	recordingFlag = false;
	recordingSerie = 1;
	//todo fps, with openCV can't always return good fps
	
	imageWidth = 100;
	imageheight = 100;

	videoWriter_init = false;
	snapshotFlag = false;
	recordingFileSize = 0;
	description = QString::null;

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
	//if (_frameOriginal.empty()) return;

	//process();
	
	cv::Point origin;
	origin.x = 0;
	origin.y = 800;

	time_t rawtime;
	time(&rawtime);
	char const *time = ctime(&rawtime);
	cv::putText(_frameOriginal, time, origin, cv::QT_FONT_NORMAL, 1, cv::Scalar(0, 255, 255), 1, 8, 0);

	//Description
	if (description != QString::null) {
		
		cv::Point origin(900, 800);

		cv::putText(_frameOriginal, description.toStdString(), origin, cv::QT_FONT_NORMAL, 1, cv::Scalar(255, 255, 255), 1, 8, 0);
	}

	//Snapshot
	if (snapshotFlag) {
		QString snapShotFileName = getCurrentTime().append(".jpg");
		imwrite(snapShotFileName.toStdString(), _frameOriginal);
		snapshotFlag = false;
	}

	//Recording
	if (recordingFlag &&  recordingFileSize <= 5 * 1024 * 1024){

		if(videoWriter_init)
		{
			//file name
			outputFileName = getCurrentTime().append(QString("_(%1).avi").arg(recordingSerie));
			videoWriter_init = false;
			videoWriter = new cv::VideoWriter(outputFileName.toStdString(), CV_FOURCC('H', '2', '6', '4'), 25, cv::Size(cap_width, cap_height));
		}
		
		videoWriter->write(_frameOriginal);
		QFileInfo info(outputFileName);
		recordingFileSize = info.size();
		emit sendWriteFileBits(recordingFileSize);
	}
	else {
		videoWriter_init = true;
		recordingFileSize = 0;
		if (recordingFlag){
			recordingSerie++;
		}
		else {
			recordingSerie = 1;
		}
	}

	//reset frame for QT widget
	cv::cvtColor(_frameOriginal, _frameProcessed, cv::COLORMAP_RAINBOW);

	//qt image
	QImage dest((const uchar *)_frameProcessed.data, _frameProcessed.cols, _frameProcessed.rows, _frameProcessed.step, QImage::Format_RGB888);
	dest.bits();
	//dest = dest.scaled(imageWidth, imageheight);

	emit sendFrame(dest);
}

QString EcaOpenCvWorker::getCurrentTime() const {

	QDateTime dt = QDateTime::currentDateTime();
	return dt.toString("yyyy_MM_dd_hh_mm_ss");
}

void EcaOpenCvWorker::setImageScale(int width, int height)
{
	imageWidth = width;
	imageheight = height;
}

void EcaOpenCvWorker::recording() {
	
	videoWriter_init = true;
	recordingFlag = true;
	recordingFileSize = 0;
	recordingSerie = 1;
}	

void EcaOpenCvWorker::checkIfDeviceAlreadyOpened(const int device) {
	/*
	if (cap->isOpened()) cap->release();
	cap->open(device);
	*/
}

void EcaOpenCvWorker::stopRecording() {
	
	if (videoWriter->isOpened())
		videoWriter->release();

	videoWriter_init = false;
	recordingFlag = false;
	recordingFileSize = 0;
	recordingSerie = 1;

}

void EcaOpenCvWorker::descriptionUpdated(const QString & text)
{
	description = text;
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

void EcaOpenCvWorker::snapShot()
{
	snapshotFlag = true;
}