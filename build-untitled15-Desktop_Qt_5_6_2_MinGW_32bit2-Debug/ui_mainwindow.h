/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QPushButton *OPENButton;
    QPushButton *PIXButton;
    QSlider *horizontalSlider;
    QPushButton *Dir_Img;
    QPushButton *pixel2pic;
    QLabel *label_2;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(917, 698);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QStringLiteral(""));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 50, 601, 581));
        label->setStyleSheet(QStringLiteral("border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(102, 14, 255, 255), stop:1 rgba(255, 255, 255, 255));"));
        OPENButton = new QPushButton(centralWidget);
        OPENButton->setObjectName(QStringLiteral("OPENButton"));
        OPENButton->setGeometry(QRect(760, 100, 121, 41));
        PIXButton = new QPushButton(centralWidget);
        PIXButton->setObjectName(QStringLiteral("PIXButton"));
        PIXButton->setGeometry(QRect(760, 250, 121, 41));
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(730, 200, 160, 22));
        horizontalSlider->setOrientation(Qt::Horizontal);
        Dir_Img = new QPushButton(centralWidget);
        Dir_Img->setObjectName(QStringLiteral("Dir_Img"));
        Dir_Img->setGeometry(QRect(760, 330, 121, 41));
        pixel2pic = new QPushButton(centralWidget);
        pixel2pic->setObjectName(QStringLiteral("pixel2pic"));
        pixel2pic->setGeometry(QRect(760, 430, 121, 41));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(880, 170, 31, 21));
        label_2->setStyleSheet(QStringLiteral("border-color: rgb(0, 0, 255);"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(760, 540, 121, 41));
        MainWindow->setCentralWidget(centralWidget);
        label->raise();
        OPENButton->raise();
        PIXButton->raise();
        Dir_Img->raise();
        pixel2pic->raise();
        horizontalSlider->raise();
        label_2->raise();
        pushButton->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 917, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label->setText(QString());
        OPENButton->setText(QApplication::translate("MainWindow", "OPEN", 0));
        PIXButton->setText(QApplication::translate("MainWindow", "PIXELISE", 0));
        Dir_Img->setText(QApplication::translate("MainWindow", "Add Image From Dir", 0));
        pixel2pic->setText(QApplication::translate("MainWindow", "pixel to pic", 0));
        label_2->setText(QString());
        pushButton->setText(QApplication::translate("MainWindow", "Save", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
