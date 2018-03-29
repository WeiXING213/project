/********************************************************************************
** Form generated from reading UI file 'QtGuiApplication5.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTGUIAPPLICATION5_H
#define UI_QTGUIAPPLICATION5_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtGuiApplication5Class
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtGuiApplication5Class)
    {
        if (QtGuiApplication5Class->objectName().isEmpty())
            QtGuiApplication5Class->setObjectName(QStringLiteral("QtGuiApplication5Class"));
        QtGuiApplication5Class->resize(600, 400);
        centralWidget = new QWidget(QtGuiApplication5Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QtGuiApplication5Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtGuiApplication5Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 26));
        QtGuiApplication5Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtGuiApplication5Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtGuiApplication5Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtGuiApplication5Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtGuiApplication5Class->setStatusBar(statusBar);

        retranslateUi(QtGuiApplication5Class);

        QMetaObject::connectSlotsByName(QtGuiApplication5Class);
    } // setupUi

    void retranslateUi(QMainWindow *QtGuiApplication5Class)
    {
        QtGuiApplication5Class->setWindowTitle(QApplication::translate("QtGuiApplication5Class", "QtGuiApplication5", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtGuiApplication5Class: public Ui_QtGuiApplication5Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGUIAPPLICATION5_H
