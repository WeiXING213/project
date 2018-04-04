#include "ecaMainWindow.h"
#include "ecaplayer.h"
#include <QLayout>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QDir>
#include <QPushButton>
#include <ecaqcvwidget.h>

EcaMainWindow::EcaMainWindow(QWidget *parent)
	: QWidget(parent)
{
	
	//player
	QHBoxLayout *topLayout = new QHBoxLayout;
	EcaPlayer *ecaPlayer = new EcaPlayer(this);
	topLayout->addWidget(ecaPlayer);
	topLayout->addSpacing(300);
	
	//PTZ & status bar
	statuBar = new QStatusBar();

	QVBoxLayout *layout = new QVBoxLayout;
	layout->addLayout(topLayout);
	layout->addSpacing(200);
	layout->addWidget(statuBar);
	
	this->setLayout(layout);

	bool ok = connect(ecaPlayer, SIGNAL(sendClearMessage()), this->statuBar, SLOT(clearMessage()));
	Q_ASSERT_X(ok, Q_FUNC_INFO, "connection error");

	ok = connect(ecaPlayer, SIGNAL(sendShowMessage(const QString &, int)), this->statuBar, SLOT(showMessage(const QString &, int)));
	Q_ASSERT_X(ok, Q_FUNC_INFO, "connection error");

}


