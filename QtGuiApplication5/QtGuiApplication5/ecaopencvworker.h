#pragma once
#ifndef ECAOPENCVWORKER_H
#define ECAOPENCVWORKER_H
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2\videoio.hpp>
#include <QObject>
#include <QImage>


QT_BEGIN_NAMESPACE
class QObject;
class QImage;
QT_END_NAMESPACE

class EcaOpenCvWorker :public QObject
{
	Q_OBJECT

private:
	cv::Mat _frameOriginal;
	cv::Mat _frameProcessed;
	cv::VideoCapture *cap = nullptr;
	cv::VideoWriter *videoWriter = nullptr;

	bool status;
	bool toggleStream;
	bool binaryThresholdEnable;
	int binaryThreshold;
	bool recordingFlag;
	
	void checkIfDeviceAlreadyOpened(const int device);
	void process();

	int imageWidth;
	int imageheight;


public:
	explicit EcaOpenCvWorker(QObject *parent = 0);
	~EcaOpenCvWorker();

signals:
	void sendFrame(QImage frameProcessed);

public slots:
	void receiveGrabFrame();
	void receiveSetup(const int device);
	void receiveToggleStream();
	void recording();

	void receiveEnableBinaryThreshold();
	void receiveBinaryThreshold(int threshold);

	void setImageScale(int width, int height);
};

#endif //ECAOPENCVWORKER_H