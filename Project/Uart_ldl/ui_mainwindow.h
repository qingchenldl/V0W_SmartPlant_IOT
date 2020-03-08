/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "qwt_plot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QComboBox *PortBox;
    QComboBox *Plant_varieties;
    QLabel *label_6;
    QComboBox *Model_selection;
    QPushButton *OpenSerialButton;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QPushButton *SendButton;
    QLCDNumber *LcdTemp;
    QLineEdit *TemplineEdit;
    QLineEdit *TemplineEdit_2;
    QLCDNumber *LcdHumi;
    QLineEdit *TemplineEdit_3;
    QLCDNumber *LcdLight;
    QPushButton *BntMotor_2;
    QLineEdit *TemplineEdit_4;
    QLineEdit *TemplineEdit_5;
    QLineEdit *lineEdit;
    QwtPlot *qwtPlot;
    QLabel *label_3;
    QwtPlot *qwtPlot_2;
    QwtPlot *qwtPlot_3;
    QSlider *PwmSlider;
    QLineEdit *PwmLineEdit;
    QLabel *label_7;
    QPushButton *ColdButton;
    QPushButton *WindBotton;
    QPushButton *WetButton;
    QPushButton *HotButton;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(844, 503);
        MainWindow->setStyleSheet(QStringLiteral("background-image: url(:/image/back.png);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 52, 54, 20));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 90, 71, 21));
        PortBox = new QComboBox(centralWidget);
        PortBox->setObjectName(QStringLiteral("PortBox"));
        PortBox->setGeometry(QRect(70, 50, 69, 22));
        Plant_varieties = new QComboBox(centralWidget);
        Plant_varieties->addItem(QString());
        Plant_varieties->addItem(QString());
        Plant_varieties->setObjectName(QStringLiteral("Plant_varieties"));
        Plant_varieties->setGeometry(QRect(70, 90, 69, 22));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 130, 61, 16));
        Model_selection = new QComboBox(centralWidget);
        Model_selection->addItem(QString());
        Model_selection->addItem(QString());
        Model_selection->setObjectName(QStringLiteral("Model_selection"));
        Model_selection->setGeometry(QRect(70, 130, 69, 22));
        OpenSerialButton = new QPushButton(centralWidget);
        OpenSerialButton->setObjectName(QStringLiteral("OpenSerialButton"));
        OpenSerialButton->setGeometry(QRect(20, 10, 111, 31));
        OpenSerialButton->setStyleSheet(QLatin1String("QPushButton#OpenSerialButton\n"
"{\n"
"    border-image: url(:/image/button.png);\n"
"}\n"
"\n"
"\n"
"QPushButton#OpenSerialButton:pressed\n"
"{\n"
"  \n"
"	border-image: url(:/image/button1.png);\n"
"}"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(229, 40, 301, 31));
        textEdit_2 = new QTextEdit(centralWidget);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(229, 0, 301, 31));
        SendButton = new QPushButton(centralWidget);
        SendButton->setObjectName(QStringLiteral("SendButton"));
        SendButton->setGeometry(QRect(550, 20, 31, 31));
        SendButton->setStyleSheet(QStringLiteral(""));
        LcdTemp = new QLCDNumber(centralWidget);
        LcdTemp->setObjectName(QStringLiteral("LcdTemp"));
        LcdTemp->setGeometry(QRect(70, 420, 111, 41));
        TemplineEdit = new QLineEdit(centralWidget);
        TemplineEdit->setObjectName(QStringLiteral("TemplineEdit"));
        TemplineEdit->setGeometry(QRect(12, 420, 61, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(12);
        TemplineEdit->setFont(font);
        TemplineEdit_2 = new QLineEdit(centralWidget);
        TemplineEdit_2->setObjectName(QStringLiteral("TemplineEdit_2"));
        TemplineEdit_2->setGeometry(QRect(320, 420, 61, 41));
        TemplineEdit_2->setFont(font);
        LcdHumi = new QLCDNumber(centralWidget);
        LcdHumi->setObjectName(QStringLiteral("LcdHumi"));
        LcdHumi->setGeometry(QRect(380, 420, 111, 41));
        TemplineEdit_3 = new QLineEdit(centralWidget);
        TemplineEdit_3->setObjectName(QStringLiteral("TemplineEdit_3"));
        TemplineEdit_3->setGeometry(QRect(630, 420, 61, 41));
        TemplineEdit_3->setFont(font);
        LcdLight = new QLCDNumber(centralWidget);
        LcdLight->setObjectName(QStringLiteral("LcdLight"));
        LcdLight->setGeometry(QRect(690, 420, 111, 41));
        BntMotor_2 = new QPushButton(centralWidget);
        BntMotor_2->setObjectName(QStringLiteral("BntMotor_2"));
        BntMotor_2->setGeometry(QRect(700, 130, 111, 31));
        BntMotor_2->setStyleSheet(QLatin1String("QPushButton#BntMotor_2\n"
"{\n"
"    border-image: url(:/image/button.png);\n"
"}\n"
"\n"
"\n"
"QPushButton#BntMotor_2:pressed\n"
"{\n"
"  \n"
"	border-image: url(:/image/button1.png);\n"
"}"));
        TemplineEdit_4 = new QLineEdit(centralWidget);
        TemplineEdit_4->setObjectName(QStringLiteral("TemplineEdit_4"));
        TemplineEdit_4->setGeometry(QRect(180, 420, 31, 41));
        TemplineEdit_4->setFont(font);
        TemplineEdit_5 = new QLineEdit(centralWidget);
        TemplineEdit_5->setObjectName(QStringLiteral("TemplineEdit_5"));
        TemplineEdit_5->setGeometry(QRect(490, 420, 31, 41));
        QFont font1;
        font1.setFamily(QStringLiteral("Consolas"));
        font1.setPointSize(12);
        TemplineEdit_5->setFont(font1);
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(800, 420, 31, 41));
        lineEdit->setFont(font1);
        qwtPlot = new QwtPlot(centralWidget);
        qwtPlot->setObjectName(QStringLiteral("qwtPlot"));
        qwtPlot->setGeometry(QRect(570, 200, 251, 201));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 160, 221, 31));
        label_3->setStyleSheet(QString::fromUtf8("QLabel#label_3{\n"
"     border-image: url(:/image/button.png);\n"
"     border-style: outset; /*\350\276\271\346\241\206\346\240\267\345\274\217*/\n"
"     border-width: 4px;  /*\350\276\271\346\241\206\345\256\275\345\272\246\344\270\2724\345\203\217\347\264\240*/\n"
"     border-radius: 10px; /*\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204*/\n"
"     border-color: rgba(255, 225, 255, 30);/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"     font: bold 14px \"\345\217\266\346\240\271\345\217\213\346\257\233\347\254\224\350\241\214\344\271\2462.0\347\211\210\";/*\345\255\227\344\275\223*/\n"
"     color:rgba(0, 0, 0, 100);/*\345\255\227\344\275\223\351\242\234\350\211\262*/\n"
"}"));
        qwtPlot_2 = new QwtPlot(centralWidget);
        qwtPlot_2->setObjectName(QStringLiteral("qwtPlot_2"));
        qwtPlot_2->setEnabled(true);
        qwtPlot_2->setGeometry(QRect(290, 200, 251, 201));
        qwtPlot_3 = new QwtPlot(centralWidget);
        qwtPlot_3->setObjectName(QStringLiteral("qwtPlot_3"));
        qwtPlot_3->setGeometry(QRect(10, 200, 241, 201));
        PwmSlider = new QSlider(centralWidget);
        PwmSlider->setObjectName(QStringLiteral("PwmSlider"));
        PwmSlider->setGeometry(QRect(730, 97, 101, 22));
        PwmSlider->setOrientation(Qt::Horizontal);
        PwmLineEdit = new QLineEdit(centralWidget);
        PwmLineEdit->setObjectName(QStringLiteral("PwmLineEdit"));
        PwmLineEdit->setEnabled(true);
        PwmLineEdit->setGeometry(QRect(700, 95, 25, 25));
        PwmLineEdit->setMinimumSize(QSize(25, 25));
        PwmLineEdit->setFont(font1);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(640, 95, 51, 31));
        label_7->setMinimumSize(QSize(2, 2));
        ColdButton = new QPushButton(centralWidget);
        ColdButton->setObjectName(QStringLiteral("ColdButton"));
        ColdButton->setGeometry(QRect(625, 45, 61, 21));
        ColdButton->setStyleSheet(QLatin1String("QPushButton#ColdButton\n"
"{\n"
"    border-image: url(:/image/button.png);\n"
"}\n"
"\n"
"\n"
"QPushButton#ColdButton:pressed\n"
"{\n"
"  \n"
"	border-image: url(:/image/button1.png);\n"
"}"));
        WindBotton = new QPushButton(centralWidget);
        WindBotton->setObjectName(QStringLiteral("WindBotton"));
        WindBotton->setGeometry(QRect(692, 46, 61, 20));
        WindBotton->setStyleSheet(QLatin1String("QPushButton#WindBotton\n"
"{\n"
"    border-image: url(:/image/button.png);\n"
"}\n"
"\n"
"\n"
"QPushButton#WindBotton:pressed\n"
"{\n"
"  \n"
"	border-image: url(:/image/button1.png);\n"
"}"));
        WetButton = new QPushButton(centralWidget);
        WetButton->setObjectName(QStringLiteral("WetButton"));
        WetButton->setGeometry(QRect(692, 3, 61, 21));
        WetButton->setStyleSheet(QLatin1String("QPushButton#WetButton\n"
"{\n"
"    border-image: url(:/image/button.png);\n"
"}\n"
"\n"
"\n"
"QPushButton#WetButton:pressed\n"
"{\n"
"  \n"
"	border-image: url(:/image/button1.png);\n"
"}"));
        HotButton = new QPushButton(centralWidget);
        HotButton->setObjectName(QStringLiteral("HotButton"));
        HotButton->setGeometry(QRect(625, 3, 61, 21));
        HotButton->setStyleSheet(QLatin1String("QPushButton#HotButton\n"
"{\n"
"    border-image: url(:/image/button.png);\n"
"}\n"
"\n"
"\n"
"QPushButton#HotButton:pressed\n"
"{\n"
"  \n"
"	border-image: url(:/image/button1.png);\n"
"}"));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        Plant_varieties->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\346\244\215\347\211\251\345\267\245\345\216\202", nullptr));
        label->setText(QApplication::translate("MainWindow", "\344\270\262\345\217\243", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\346\244\215\347\211\251\345\223\201\347\247\215", nullptr));
        Plant_varieties->setItemText(0, QApplication::translate("MainWindow", "\347\216\253\347\221\260", nullptr));
        Plant_varieties->setItemText(1, QApplication::translate("MainWindow", "\351\246\231\350\217\207", nullptr));

        label_6->setText(QApplication::translate("MainWindow", "\346\250\241\345\274\217\351\200\211\346\213\251", nullptr));
        Model_selection->setItemText(0, QApplication::translate("MainWindow", "\350\207\252\345\212\250", nullptr));
        Model_selection->setItemText(1, QApplication::translate("MainWindow", "\346\211\213\345\212\250", nullptr));

        OpenSerialButton->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        SendButton->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
        TemplineEdit->setText(QApplication::translate("MainWindow", "\346\270\251\345\272\246", nullptr));
        TemplineEdit_2->setText(QApplication::translate("MainWindow", "\346\271\277\345\272\246", nullptr));
        TemplineEdit_3->setText(QApplication::translate("MainWindow", "\345\205\211\347\205\247", nullptr));
        BntMotor_2->setText(QApplication::translate("MainWindow", "\346\227\245\345\277\227", nullptr));
        TemplineEdit_4->setText(QApplication::translate("MainWindow", "\342\204\203", nullptr));
        TemplineEdit_5->setText(QApplication::translate("MainWindow", "%", nullptr));
        lineEdit->setText(QApplication::translate("MainWindow", "lx", nullptr));
        label_3->setText(QString());
        label_7->setText(QApplication::translate("MainWindow", "\350\260\203\350\212\202\345\205\211\347\205\247", nullptr));
        ColdButton->setText(QApplication::translate("MainWindow", "\345\210\266\345\206\267", nullptr));
        WindBotton->setText(QApplication::translate("MainWindow", "\351\200\232\351\243\216", nullptr));
        WetButton->setText(QApplication::translate("MainWindow", "\345\212\240\346\271\277", nullptr));
        HotButton->setText(QApplication::translate("MainWindow", "\345\212\240\347\203\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
