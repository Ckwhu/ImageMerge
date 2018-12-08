/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE


class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QScrollBar *verticalScrollBar;
    QScrollBar *horizontalScrollBar;
    QSlider *horizontalSlider;
    QSpinBox *spinBox;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_5;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(650, 494);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(570, 20, 75, 23));
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(0, 20, 551, 361));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 549, 359));

      /*  verticalScrollBar = new QScrollBar(scrollAreaWidgetContents);
        verticalScrollBar->setObjectName(QStringLiteral("verticalScrollBar"));
        verticalScrollBar->setGeometry(QRect(530, 0, 16, 341));
        verticalScrollBar->setOrientation(Qt::Vertical);
        horizontalScrollBar = new QScrollBar(scrollAreaWidgetContents);
        horizontalScrollBar->setObjectName(QStringLiteral("horizontalScrollBar"));
        horizontalScrollBar->setGeometry(QRect(0, 340, 551, 16));
        horizontalScrollBar->setOrientation(Qt::Horizontal);*/

        scrollArea->setWidget(scrollAreaWidgetContents);
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(70, 400, 160, 22));
		horizontalSlider->setOrientation(Qt::Horizontal);

		horizontalSlider->setMinimum(-10);//设置最大值
		horizontalSlider->setMaximum(10);//设置最小值
		horizontalSlider->setSingleStep(1);//设置步长
		horizontalSlider->setValue(0);//设置初始值

		spinBox = new QSpinBox(centralWidget);
		spinBox->setObjectName(QStringLiteral("spinBox"));
		spinBox->setGeometry(QRect(10, 400, 42, 22));
		spinBox->setMaximum(10);//设置最大值
		spinBox->setMinimum(-10);//设置最小值
		spinBox->setSingleStep(1);//设置步长
		spinBox->setValue(0);//设置初值

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(570, 70, 75, 23));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(570, 370, 75, 23));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(570, 220, 75, 23));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(570, 270, 75, 23));
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(570, 320, 75, 23));
        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(570, 120, 75, 23));
        pushButton_8 = new QPushButton(centralWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(570, 170, 75, 23));
        radioButton = new QRadioButton(centralWidget);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(20, 0, 89, 16));
        radioButton_2 = new QRadioButton(centralWidget);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(120, 0, 89, 16));
        radioButton_3 = new QRadioButton(centralWidget);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setGeometry(QRect(220, 0, 89, 16));
        radioButton_4 = new QRadioButton(centralWidget);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));
        radioButton_4->setGeometry(QRect(330, 0, 89, 16));
        radioButton_5 = new QRadioButton(centralWidget);
        radioButton_5->setObjectName(QStringLiteral("radioButton_5"));
        radioButton_5->setGeometry(QRect(470, 0, 89, 16));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(250, 400, 291, 21));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setUnderline(false);
        font.setWeight(75);
        label->setFont(font);
        label->setCursor(QCursor(Qt::ForbiddenCursor));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 650, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
		QObject::connect(pushButton, SIGNAL(clicked()), MainWindow, SLOT(OpenImage()));
		QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), MainWindow, SLOT(changeImage()));
		QObject::connect(spinBox, SIGNAL(valueChanged(int)), MainWindow, SLOT(changeImage()));
		QObject::connect(spinBox, SIGNAL(valueChanged(int)), horizontalSlider, SLOT(setValue(int)));
		QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));

		QObject::connect(pushButton_2, SIGNAL(clicked()), MainWindow, SLOT(cutImage()));
		QObject::connect(pushButton_3, SIGNAL(clicked()), MainWindow, SLOT(saveImage()));
		QObject::connect(pushButton_4, SIGNAL(clicked()), MainWindow, SLOT(featureMatch()));
		QObject::connect(pushButton_5, SIGNAL(clicked()), MainWindow, SLOT(imgMerge()));
		QObject::connect(pushButton_7, SIGNAL(clicked()), MainWindow, SLOT(concelCut()));
		QObject::connect(pushButton_8, SIGNAL(clicked()), MainWindow, SLOT(getCuttedImage()));

		QObject::connect(radioButton, SIGNAL(clicked()), MainWindow, SLOT(changeDisplay()));
		QObject::connect(radioButton_2, SIGNAL(clicked()), MainWindow, SLOT(changeDisplay()));
		QObject::connect(radioButton_3, SIGNAL(clicked()), MainWindow, SLOT(changeDisplay()));
		QObject::connect(radioButton_4, SIGNAL(clicked()), MainWindow, SLOT(changeDisplay()));
		QObject::connect(radioButton_5, SIGNAL(clicked()), MainWindow, SLOT(changeDisplay()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\345\233\276\345\203\217", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "\350\243\201\345\211\252\345\233\276\345\203\217", nullptr));//裁剪图像
        pushButton_3->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\345\233\276\345\203\217", nullptr));//保存图像
        pushButton_4->setText(QApplication::translate("MainWindow", "\347\211\271\345\276\201\345\214\271\351\205\215", nullptr));//特征匹配
        pushButton_5->setText(QApplication::translate("MainWindow", "\345\233\276\345\203\217\346\213\274\346\216\245", nullptr));//图像拼接
        pushButton_6->setText(QApplication::translate("MainWindow", "\344\270\200\351\224\256\346\213\274\346\216\245", nullptr));//一件拼接
        pushButton_7->setText(QApplication::translate("MainWindow", "\345\217\226\346\266\210\351\200\211\346\241\206", nullptr));//取消裁剪
        pushButton_8->setText(QApplication::translate("MainWindow", "\347\241\256\350\256\244\350\243\201\345\211\252", nullptr));//确认裁剪
        radioButton->setText(QApplication::translate("MainWindow", "\345\267\246\345\233\276", nullptr));
        radioButton_2->setText(QApplication::translate("MainWindow", "\345\217\263\345\233\276", nullptr));
        radioButton_3->setText(QApplication::translate("MainWindow", "\350\243\201\345\211\252\345\233\276", nullptr));
        radioButton_4->setText(QApplication::translate("MainWindow", "\347\211\271\345\276\201\345\214\271\351\205\215\345\233\276", nullptr));
        radioButton_5->setText(QApplication::translate("MainWindow", "\346\213\274\346\216\245\345\233\276", nullptr));
        label->setText(QApplication::translate("MainWindow", "\346\217\220\347\244\272\357\274\232\347\202\271\345\207\273\346\211\223\345\274\200\345\233\276\345\203\217\350\276\223\345\205\245\345\267\246\345\233\276......", nullptr));
		pushButton_2->setDisabled(true);
		pushButton_4->setDisabled(true);
		pushButton_5->setDisabled(true);
		pushButton_6->setDisabled(true);
		pushButton_7->setDisabled(true);
		pushButton_8->setDisabled(true);
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
