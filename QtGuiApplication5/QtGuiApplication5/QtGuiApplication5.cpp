#include "QtGuiApplication5.h"
#include "ecaplayer.h"

#include <QLayout>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QDir>
#include <QPushButton>
#include <ecaqcvwidget.h>

QtGuiApplication5::QtGuiApplication5(QWidget *parent)
	: QWidget(parent)
{
	
	
	QHBoxLayout *topLayout = new QHBoxLayout;
	//EcaPlayer *ecaPlayer = new EcaPlayer(this);
	//topLayout->addWidget(ecaPlayer);
	topLayout->addSpacing(300);
	
	QVBoxLayout *layout = new QVBoxLayout;
	layout->addLayout(topLayout);
	layout->addSpacing(200);
	EcaQCvWidget *qCvWidget = new EcaQCvWidget();
	layout->addWidget(qCvWidget->steamLabel);
	this->setLayout(layout);

}


