#include "QtGuiApplication5.h"
#include "ecaplayer.h"

#include <QLayout>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QDir>
#include <QPushButton>

QtGuiApplication5::QtGuiApplication5(QWidget *parent)
	: QWidget(parent)
{
	
	EcaPlayer *ecaPlayer = new EcaPlayer(this);

	QHBoxLayout *topLayout = new QHBoxLayout;
	topLayout->addWidget(ecaPlayer);
	topLayout->addSpacing(300);
	
	QVBoxLayout *layout = new QVBoxLayout;
	layout->addLayout(topLayout);
	layout->addSpacing(200);
	this->setLayout(layout);

	
}


