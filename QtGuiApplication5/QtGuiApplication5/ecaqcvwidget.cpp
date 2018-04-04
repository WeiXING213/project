#include "ecaqcvwidget.h"
#include "ecaopencvworker.h"
#include <QTimer>

EcaQCvWidget::EcaQCvWidget(QWidget *parent) :
	QWidget(parent)
{
	//UI part goes here
	//label
	steamLabel = new QLabel();
	steamLabel->installEventFilter(this);
	//steamLabel->setScaledContents(true); //doesn't work so well 
	setup();
	

	emit sendToggleSteam();
}

bool EcaQCvWidget::eventFilter(QObject *watched, QEvent *event) {

	if (watched == steamLabel && event->type() == QEvent::Resize){

		emit resizeLabel(steamLabel->width(), steamLabel->height());

		return true;
	}
	
	return QWidget::eventFilter(watched, event); ;
}


EcaQCvWidget::~EcaQCvWidget() {
	
	thread->quit();
	while (!thread->isFinished());

	delete thread;
}

void EcaQCvWidget::receiveWriteFileBits(int size)
{
	int totalValue = 5 ; 
	float progressValue = (size/totalValue)*100/1024/1024;

	emit progressBarValue(int(progressValue));

	if (progressValue >= 100)
		emit stopRecording();
}

void EcaQCvWidget::setup(){
	
	thread = new QThread();
	EcaOpenCvWorker *worker = new EcaOpenCvWorker();
	QTimer *workerTrigger = new QTimer();
	workerTrigger->setInterval(1);

	bool ok = connect(workerTrigger, SIGNAL(timeout()), worker, SLOT(receiveGrabFrame()));
	Q_ASSERT_X(ok, Q_FUNC_INFO, "connect [timeout] signal to [receiveGrabFrame] slot failed");

	ok = connect(this, SIGNAL(sendSetup(int)), worker, SLOT(receiveSetup(int)));
	Q_ASSERT_X(ok, Q_FUNC_INFO, "connect [sendSetup] signal to [receiveSetup]  slot failed");

	ok = connect(worker, SIGNAL(sendFrame(QImage)),  this, SLOT(receiveFrame(QImage)));
	Q_ASSERT_X(ok, Q_FUNC_INFO, "connect [sendFrame] signal to [mySlot] slot failed");

	ok = connect(this, SIGNAL(sendRecoding()), worker, SLOT(recording()));
	Q_ASSERT_X(ok, Q_FUNC_INFO, "connect [sendRecoding] signal to [recording] slot failed");

	ok = connect(this, SIGNAL(resizeLabel(int, int)), worker, SLOT(setImageScale(int, int)));
	Q_ASSERT_X(ok, Q_FUNC_INFO, "connect [EcaQCvWidget.resizeLabel] signal to [worker.setImageScale] slot failed");

	ok = connect(worker, SIGNAL(sendWriteFileBits(int)), this, SLOT(receiveWriteFileBits(int)));
	Q_ASSERT_X(ok, Q_FUNC_INFO, "connect [worker.sendWriteFileBits] signal to [EcaQCvWidget.receiveWriteFileBits] slot failed");

	ok = connect(this, SIGNAL(stopRecording()), worker, SLOT(stopRecording()));
	Q_ASSERT_X(ok, Q_FUNC_INFO, "connect [this.stopRecroding] signal to [worker.stopRecording] slot failed");

	ok = connect(this, SIGNAL(descriptionUpdated(const QString &)), worker, SLOT(descriptionUpdated(const QString &)));
	Q_ASSERT_X(ok, Q_FUNC_INFO, "connection error");

	//TODO: use signal and slot
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

void EcaQCvWidget::recording()
{
	emit sendRecoding();
}

void EcaQCvWidget::descriptionChanged(const QString & text)
{
	emit descriptionUpdated(text);
}