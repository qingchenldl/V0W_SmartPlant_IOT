/********************************************************************************
** Form generated from reading UI file 'mainwindow_copy.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_COPY_H
#define UI_MAINWINDOW_COPY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

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
    QPushButton *BntMotor;
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
    QSlider *PwmSlider;
    QLabel *label_7;
    QPushButton *HotButton;
    QPushButton *ColdButton;
    QPushButton *WetButton;
    QPushButton *WindBotton;
    QLineEdit *PwmLineEdit;
    QLineEdit *SmokelineEdit;
    QLabel *label_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(763, 484);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 50, 54, 12));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 90, 71, 21));
        PortBox = new QComboBox(centralWidget);
        PortBox->setObjectName(QStringLiteral("PortBox"));
        PortBox->setGeometry(QRect(100, 50, 69, 22));
        Plant_varieties = new QComboBox(centralWidget);
        Plant_varieties->addItem(QString());
        Plant_varieties->addItem(QString());
        Plant_varieties->setObjectName(QStringLiteral("Plant_varieties"));
        Plant_varieties->setGeometry(QRect(100, 90, 69, 22));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 130, 61, 16));
        Model_selection = new QComboBox(centralWidget);
        Model_selection->addItem(QString());
        Model_selection->addItem(QString());
        Model_selection->setObjectName(QStringLiteral("Model_selection"));
        Model_selection->setGeometry(QRect(100, 130, 69, 22));
        OpenSerialButton = new QPushButton(centralWidget);
        OpenSerialButton->setObjectName(QStringLiteral("OpenSerialButton"));
        OpenSerialButton->setGeometry(QRect(100, 20, 71, 23));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(200, 30, 281, 291));
        textEdit_2 = new QTextEdit(centralWidget);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(200, 330, 161, 31));
        SendButton = new QPushButton(centralWidget);
        SendButton->setObjectName(QStringLiteral("SendButton"));
        SendButton->setGeometry(QRect(380, 330, 75, 31));
        BntMotor = new QPushButton(centralWidget);
        BntMotor->setObjectName(QStringLiteral("BntMotor"));
        BntMotor->setGeometry(QRect(550, 20, 71, 51));
        LcdTemp = new QLCDNumber(centralWidget);
        LcdTemp->setObjectName(QStringLiteral("LcdTemp"));
        LcdTemp->setGeometry(QRect(70, 370, 111, 41));
        TemplineEdit = new QLineEdit(centralWidget);
        TemplineEdit->setObjectName(QStringLiteral("TemplineEdit"));
        TemplineEdit->setGeometry(QRect(12, 370, 61, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(12);
        TemplineEdit->setFont(font);
        TemplineEdit_2 = new QLineEdit(centralWidget);
        TemplineEdit_2->setObjectName(QStringLiteral("TemplineEdit_2"));
        TemplineEdit_2->setGeometry(QRect(230, 370, 61, 41));
        TemplineEdit_2->setFont(font);
        LcdHumi = new QLCDNumber(centralWidget);
        LcdHumi->setObjectName(QStringLiteral("LcdHumi"));
        LcdHumi->setGeometry(QRect(290, 370, 111, 41));
        TemplineEdit_3 = new QLineEdit(centralWidget);
        TemplineEdit_3->setObjectName(QStringLiteral("TemplineEdit_3"));
        TemplineEdit_3->setGeometry(QRect(450, 370, 61, 41));
        TemplineEdit_3->setFont(font);
        LcdLight = new QLCDNumber(centralWidget);
        LcdLight->setObjectName(QStringLiteral("LcdLight"));
        LcdLight->setGeometry(QRect(510, 370, 111, 41));
        BntMotor_2 = new QPushButton(centralWidget);
        BntMotor_2->setObjectName(QStringLiteral("BntMotor_2"));
        BntMotor_2->setGeometry(QRect(100, 170, 75, 31));
        TemplineEdit_4 = new QLineEdit(centralWidget);
        TemplineEdit_4->setObjectName(QStringLiteral("TemplineEdit_4"));
        TemplineEdit_4->setGeometry(QRect(180, 370, 31, 41));
        TemplineEdit_4->setFont(font);
        TemplineEdit_5 = new QLineEdit(centralWidget);
        TemplineEdit_5->setObjectName(QStringLiteral("TemplineEdit_5"));
        TemplineEdit_5->setGeometry(QRect(400, 370, 31, 41));
        QFont font1;
        font1.setFamily(QStringLiteral("Consolas"));
        font1.setPointSize(12);
        TemplineEdit_5->setFont(font1);
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(620, 370, 31, 41));
        lineEdit->setFont(font1);
        PwmSlider = new QSlider(centralWidget);
        PwmSlider->setObjectName(QStringLiteral("PwmSlider"));
        PwmSlider->setGeometry(QRect(590, 330, 160, 22));
        PwmSlider->setOrientation(Qt::Horizontal);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(490, 330, 61, 16));
        HotButton = new QPushButton(centralWidget);
        HotButton->setObjectName(QStringLiteral("HotButton"));
        HotButton->setGeometry(QRect(550, 90, 71, 41));
        ColdButton = new QPushButton(centralWidget);
        ColdButton->setObjectName(QStringLiteral("ColdButton"));
        ColdButton->setGeometry(QRect(550, 150, 71, 41));
        WetButton = new QPushButton(centralWidget);
        WetButton->setObjectName(QStringLiteral("WetButton"));
        WetButton->setGeometry(QRect(550, 210, 71, 41));
        WindBotton = new QPushButton(centralWidget);
        WindBotton->setObjectName(QStringLiteral("WindBotton"));
        WindBotton->setGeometry(QRect(550, 270, 71, 41));
        PwmLineEdit = new QLineEdit(centralWidget);
        PwmLineEdit->setObjectName(QStringLiteral("PwmLineEdit"));
        PwmLineEdit->setGeometry(QRect(550, 320, 31, 31));
        PwmLineEdit->setFont(font1);
        SmokelineEdit = new QLineEdit(centralWidget);
        SmokelineEdit->setObjectName(QStringLiteral("SmokelineEdit"));
        SmokelineEdit->setGeometry(QRect(660, 90, 71, 21));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font2.setPointSize(10);
        SmokelineEdit->setFont(font2);
        SmokelineEdit->setDragEnabled(false);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(670, 70, 54, 12));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font3.setPointSize(10);
        label_3->setFont(font3);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 763, 23));
        MainWindow->setMenuBar(menuBar);
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
        BntMotor->setText(QApplication::translate("MainWindow", "\347\224\265\346\234\272\346\255\243\350\275\254", nullptr));
        TemplineEdit->setText(QApplication::translate("MainWindow", "\346\270\251\345\272\246", nullptr));
        TemplineEdit_2->setText(QApplication::translate("MainWindow", "\346\271\277\345\272\246", nullptr));
        TemplineEdit_3->setText(QApplication::translate("MainWindow", "\345\205\211\347\205\247", nullptr));
        BntMotor_2->setText(QApplication::translate("MainWindow", "\346\227\245\345\277\227", nullptr));
        TemplineEdit_4->setText(QApplication::translate("MainWindow", "\342\204\203", nullptr));
        TemplineEdit_5->setText(QApplication::translate("MainWindow", "%", nullptr));
        lineEdit->setText(QApplication::translate("MainWindow", "lx", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\350\260\203\350\212\202\345\205\211\347\205\247", nullptr));
        HotButton->setText(QApplication::translate("MainWindow", "\345\212\240\347\203\255", nullptr));
        ColdButton->setText(QApplication::translate("MainWindow", "\345\210\266\345\206\267", nullptr));
        WetButton->setText(QApplication::translate("MainWindow", "\345\212\240\346\271\277", nullptr));
        WindBotton->setText(QApplication::translate("MainWindow", "\351\200\232\351\243\216", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\347\203\237\351\233\276\346\243\200\346\265\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_COPY_H
