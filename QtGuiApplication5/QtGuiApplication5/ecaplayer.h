#pragma once
#ifndef ECAPLAYER_H
#define ECAPLAYER_H

#include <QMediaPlayer>
#include <QAbstractButton>
#include "ecaqcvwidget.h"

QT_BEGIN_NAMESPACE
class QLabel;
class QMediaPlayer;
class QModelIndex;
class QPushButton;
class QSlider;
class QVideoProbe;
class QVideoWidget;
class QAudioProbe;
class QLineEdit;
class QProgressBar;
class QWidget;
class QStatusBar;
QT_END_NAMESPACE

class EcaPlayer : public QWidget
{
	Q_OBJECT


signals:
	void fullScreenChanged(bool fullScreen);
	void textChanged(const QString &);
	void sendClearMessage();
	void sendShowMessage(const QString &, int);
	void sendSnapshot();

public slots:
	
	void recording();
	void stopRecordingSlot();
	void sendDescription();
	void receiveSnapShot();
	
	/*void durationChanged(qint64 duration);
	void positionChanged(qint64 progress);
	void metaDataChanged();

	void statusChanged(QMediaPlayer::MediaStatus status);
	void stateChanged(QMediaPlayer::State state);
	void bufferingProgress(int progress);
	void videoAvailableChanged(bool available);

	void displayErrorMessage();

	void showColorDialog();*/

private:
	/*void setTrackInfo(const QString &info);
	void setStatusInfo(const QString &info);
	void handleCursor(QMediaPlayer::MediaStatus status);
	void updateDurationInfo(qint64 currentInfo);*/
	EcaQCvWidget *qCvWidget = nullptr;
	QAbstractButton *btnRecord = nullptr;
	QProgressBar *progressBar = nullptr;
	QLineEdit *description = nullptr;
	QLabel *pLabel = nullptr;
	QAbstractButton *btnSend = nullptr;
	QAbstractButton *btnSnapShot = nullptr;
	QLabel *imageLabel = nullptr;
	QString recordingStatus;

	QMediaPlayer *m_player = nullptr;
	QMediaPlaylist *m_playlist = nullptr;
	QVideoWidget *m_videoWidget = nullptr;
	QLabel *m_coverLabel = nullptr;
	QSlider *m_slider = nullptr;
	QLabel *m_labelDuration = nullptr;
	QPushButton *m_fullScreenButton = nullptr;
	QPushButton *m_colorButton = nullptr;
	QDialog *m_colorDialog = nullptr;

	QLabel *m_labelHistogram = nullptr;
	QVideoProbe *m_videoProbe = nullptr;
	QAudioProbe *m_audioProbe = nullptr;

	QString m_trackInfo;
	QString m_statusInfo;
	qint64 m_duration;

public:
	explicit EcaPlayer(QWidget *parent = nullptr);
	~EcaPlayer();


	/*bool isPlayerAvailable() const;*/
};
#endif // PLAYER_H