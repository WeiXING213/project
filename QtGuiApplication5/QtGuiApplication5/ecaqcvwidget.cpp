#include "ecaqcvwidget.h"
#include "ecaopencvworker.h"
#include <QTimer>

EcaQCvWidget::EcaQCvWidget(QWidget *parent) :
	QWidget(parent)
{
	//UI part goes here
	//label
	

	steamLabel = new QLabel();
	setup();

	emit sendToggleSteam();
}

EcaQCvWidget::~EcaQCvWidget() {
	
	thread->quit();
	while (!thread->isFinished());

	delete thread;
}

void EcaQCvWidget::setup(){
	
	thread = new QThread();
	EcaOpenCvWorker *worker = new EcaOpenCvWorker();
	QTimer *workerTrigger = new QTimer();
	workerTrigger->setInterval(1);

	bool ok = connect(workerTrigger, SIGNAL(timeout()),          worker, SLOT(receiveGrabFrame()));
	Q_ASSERT_X(ok, Q_FUNC_INFO, "connect timeout signal to receiveGrabFrame slot failed");

	ok = connect(this,		   SIGNAL(sendSetup(int)),     worker, SLOT(receiveSetup(int)));
	Q_ASSERT_X(ok, Q_FUNC_INFO, "connect sendSetup signal to receiveSetup  slot failed");

	ok = connect(worker,        SIGNAL(sendFrame(QImage)),  this,   SLOT(receiveFrame(QImage)));
	Q_ASSERT_X(ok, Q_FUNC_INFO, "connect sendFrame signal to mySlot slot failed");

	workerTrigger->start();
	worker->moveToThread(thread);
	workerTrigger->moveToThread(thread);
	thread->start();

	//connect(thread, SIGNAL(started()), workerTrigger, SLOT(start()));
	emit sendSetup(0);
}

void EcaQCvWidget::receiveFrame(QImage frame)
{
	steamLabel->setPixmap(QPixmap::fromImage(frame));
}

void EcaQCvWidget::receiveToggleStream()
{
	//SEND TOGGLESTREAM

	
}