#include "ecaplayer.h"
#include "ecaplayercontrols.h"

#include <QMediaService>
#include <QVideoProbe>
#include <QAudioProbe>
#include <QMediaMetaData>
#include <QtWidgets>
#include <QVideoWidget>
#include <QIcon>

EcaPlayer::EcaPlayer(QWidget *parent) 
	: QWidget(parent)
{
	//streaming
	m_videoWidget = new QVideoWidget(this);
	m_player = new QMediaPlayer(this);

	m_player->setMedia(QUrl("rtsp://192.168.1.1:9099/stream"));
	m_player->setVideoOutput(m_videoWidget);
	m_player->setVolume(50);
	m_player->play();
	m_videoWidget->show();
	
	QBoxLayout *displayLayout = new QHBoxLayout;
	displayLayout->setContentsMargins(0, 0, 0, 0);
	displayLayout->addWidget(m_videoWidget);

	//recording button
	QPixmap pmapRecord(40, 40);
	pmapRecord.load("images/recording.png");
	QIcon icon(pmapRecord);

	btnRecord = new QToolButton(this);
	btnRecord->setIcon(style()->standardIcon(QStyle::SP_DialogSaveButton));
	btnRecord->setIcon(icon);

	//progress bar
	progressBar = new QProgressBar(this);
	progressBar->setRange(0, 100);
	progressBar->setValue(12);
	
	//description line edit
	pLabel = new QLabel(this);
	pLabel->setText("Description: ");
	description = new QLineEdit(this);
	description->setPlaceholderText("input description text");
	btnSend = new QToolButton(this);
	btnSend->setText("send");


	//layout
	QBoxLayout *controlLayout = new QHBoxLayout;
	controlLayout->setAlignment(Qt::AlignLeft);
	controlLayout->setContentsMargins(0, 0, 0, 0);
	controlLayout->setSpacing(0);

	controlLayout->addWidget(btnRecord);
	controlLayout->addWidget(progressBar);

	controlLayout->addWidget(pLabel);
	controlLayout->addWidget(description);
	controlLayout->addWidget(btnSend);

	controlLayout->addStretch();

	//main layout
	QBoxLayout *layout = new QVBoxLayout;
	layout->setContentsMargins(0, 0, 0, 0);
	layout->addLayout(displayLayout);
	layout->addLayout(controlLayout);
	setLayout(layout);
	
}

EcaPlayer::~EcaPlayer()
{
}
