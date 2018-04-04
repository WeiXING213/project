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
	int recordingFileSize;
	int recordingSerie;
	QString outputFileName;

	bool status;
	bool toggleStream;
	bool binaryThresholdEnable;
	int binaryThreshold;
	bool recordingFlag;
	
	void checkIfDeviceAlreadyOpened(const int device);
	void process();

	int imageWidth;
	int imageheight;

	int cap_width;
	int cap_height;

	bool videoWriter_init;
	QString description;

	bool snapshotFlag;


public:
	explicit EcaOpenCvWorker(QObject *parent = 0);
	void snapShot();
	QString getCurrentTime() const;
	~EcaOpenCvWorker();

signals:
	void sendFrame(QImage frameProcessed);
	void sendWriteFileBits(int size);

public slots:
	void receiveGrabFrame();
	void receiveSetup(const int device);
	void receiveToggleStream();
	void recording();
	void stopRecording();

	void receiveEnableBinaryThreshold();
	void receiveBinaryThreshold(int threshold);

	void setImageScale(int width, int height);

	void descriptionUpdated(const QString &);
};

#endif //ECAOPENCVWORKER_H