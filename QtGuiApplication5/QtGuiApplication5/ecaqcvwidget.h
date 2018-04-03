#pragma once
#ifndef ECAQCVWIDGET_H
#define ECAQCVWIDGET_H

#include <QWidget>
#include <QThread>
#include <qLabel>
#include <QResizeEvent>

class EcaQCvWidget : public QWidget
{
	Q_OBJECT

private:
	QThread * thread;
	void setup();
	QImage currentImage;
	
public:
	explicit EcaQCvWidget(QWidget *parent = 0);
	~EcaQCvWidget();
	bool eventFilter(QObject *watched, QEvent *event);
	QLabel *steamLabel = nullptr;

signals:
	void sendSetup(int device);
	void sendToggleSteam();
	void sendRecoding();
	void resizeLabel(int width, int height);
	void progressBarValue(int);
	void stopRecording();
	

public slots:
	void receiveFrame(QImage frame);
	void receiveToggleStream();
	void recording();
	void receiveWriteFileBits(int);
};

#endif //ECAQCVWIDGET_H