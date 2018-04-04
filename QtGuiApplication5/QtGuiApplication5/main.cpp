#include "ecaMainWindow.h"
#include <QtWidgets/QApplication>
#include <QPushButton>
#include <QLayout>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	EcaMainWindow qt;	
	qt.setWindowTitle("Eca Robotics");
	
	//qt.move(100, 100);
	qt.setMinimumSize(800, 600);
	qt.show();
	
	return app.exec();
}
