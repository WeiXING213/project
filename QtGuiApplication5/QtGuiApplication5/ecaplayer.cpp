#include "ecaplayer.h"
#include "ecaplayercontrols.h"
#include <QMediaService>
#include <QVideoProbe>
#include <QAudioProbe>
#include <QMediaMetaData>
#include <QtWidgets>
#include <QVideoWidget>
#include <QIcon>

#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include <opencv2/video/video.hpp>
#include "opencv2/highgui/highgui.hpp"

using namespace cv;

EcaPlayer::EcaPlayer(QWidget *parent) 
	: QWidget(parent)
{
	//Opencv test
	cv::VideoCapture capture("rtsp://192.168.1.1:9099/stream");
	if (!capture.isOpened())
	{
		std::cout << "Read video Failed !" << std::endl;
	}

	cv::Mat frame;
	//cv::namedWindow("video test");

	int frame_num = capture.get(cv::CAP_PROP_FRAME_COUNT);
	std::cout << "total frame number is: " << frame_num << std::endl;

	time_t rawtimeFileName;
	time(&rawtimeFileName);
	char *timeFileName = ctime(&rawtimeFileName);
	char a[] = ".avi";
	char *b;
	b = a;

	std::string src1(timeFileName);
	std::string src2(b);
	std::string dest = src1 + src2;
	std::replace(dest.begin(), dest.end(), ' ', '_');
	std::replace(dest.begin(), dest.end(), ':', '_');
	std::replace(dest.begin(), dest.end(), '\n', '_');
	dest.c_str();

	int width = (int)capture.get(cv::CAP_PROP_FRAME_WIDTH);
	int height = (int)capture.get(cv::CAP_PROP_FRAME_HEIGHT);
	int fps = (int)capture.get(cv::CAP_PROP_FPS);

	VideoWriter writer(dest,
		CV_FOURCC('H', '2', '6', '4'),
		50,
		Size(width, height)
	);

	cv::Point origin;
	origin.x = 100;
	origin.y = 100;

	for (int i = 0; i < 1000; ++i)
	{
		capture >> frame;
		//std::string s = std::to_string(i);
		//char const *pchar = s.c_str();

		time_t rawtime;
		time(&rawtime);
		char const *time = ctime(&rawtime);
		cv::putText(frame, time, origin, cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar(0, 255, 255), 2, 8, 0);
		writer << frame;

		//imshow("video test", frame);
		/*if (cv::waitKey(30) == 'q')
		{
		break;
		}*/
	}

	writer.release();
	//cv::destroyWindow("video test");
	capture.release();
	
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
