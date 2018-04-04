#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_QtGuiApplication5.h"

QT_BEGIN_NAMESPACE
class QStatusBar;
QT_END_NAMESPACE

class EcaMainWindow : public QWidget
{
	Q_OBJECT

public:

	QStatusBar * statuBar = nullptr;
	EcaMainWindow(QWidget *parent = Q_NULLPTR);


};
