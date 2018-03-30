#pragma once
#ifndef ECAQCVWIDGET_H
#define ECAQCVWIDGET_H

#include <QWidget>
#include <QThread>
#include <qLabel>

class EcaQCvWidget : public QWidget
{
	Q_OBJECT

private:
	QThread * thread;

	void setup();
	
public:
	explicit EcaQCvWidget(QWidget *parent = 0);
	~EcaQCvWidget();
	QLabel *steamLabel = nullptr;

signals:
	void sendSetup(int device);
	void sendToggleSteam();

public slots:
	void receiveFrame(QImage frame);
	void receiveToggleStream();
	
};

#endif //ECAQCVWIDGET_H