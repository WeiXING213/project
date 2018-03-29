#include "ecaplayercontrols.h"

#include <QBoxLayout>
#include <QSlider>
#include <QStyle>
#include <QToolButton>
#include <QComboBox>
#include <QAudio>

EcaPlayerControls::EcaPlayerControls(QWidget *parent) : QWidget(parent)
{
	//m_playButton = new QToolButton(this);
	//m_playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
	//connect(m_playButton, &QAbstractButton::clicked, this, &EcaPlayerControls::playClicked);

	//m_stopButton = new QToolButton(this);
	//m_stopButton->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
	//connect(m_stopButton, &QAbstractButton::clicked, this, &EcaPlayerControls::stop);

	//m_muteButton =new QToolButton(this);
	//m_muteButton->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));
	//connect(m_muteButton, &QAbstractButton::click, this, &EcaPlayerControls::muteClicked);

	//m_volumeSlider = new QSlider(Qt::Horizontal, this);
	//m_volumeSlider->setRange(0, 100);
	//connect(m_volumeSlider, &QSlider::valueChanged, this, &EcaPlayerControls::onVolumeSliderValueChanged);

	//QBoxLayout *layout = new QHBoxLayout;
	//layout->setMargin(0);
	//layout->addWidget(m_stopButton);

	/*layout->addWidget(m_playButton);
	layout->addWidget(m_muteButton);
	layout->addWidget(m_volumeSlider);
	*/
	
	QToolButton *qtl = new QToolButton(parent);
	QToolButton *qtl2 = new QToolButton(parent);
	QToolButton *qtl3 = new QToolButton(parent);
	QToolButton *qtl4 = new QToolButton(parent);


	QBoxLayout *controlLayout = new QHBoxLayout;
	controlLayout->setMargin(0);
	controlLayout->addWidget(qtl);
	controlLayout->addWidget(qtl2);
	controlLayout->addWidget(qtl3);
	controlLayout->addWidget(qtl4);

	
	setLayout(controlLayout);
}
