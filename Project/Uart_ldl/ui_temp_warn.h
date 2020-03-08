/********************************************************************************
** Form generated from reading UI file 'temp_warn.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEMP_WARN_H
#define UI_TEMP_WARN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_temp_warn
{
public:
    QLabel *label;

    void setupUi(QDialog *temp_warn)
    {
        if (temp_warn->objectName().isEmpty())
            temp_warn->setObjectName(QStringLiteral("temp_warn"));
        temp_warn->resize(294, 147);
        label = new QLabel(temp_warn);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 40, 191, 71));

        retranslateUi(temp_warn);

        QMetaObject::connectSlotsByName(temp_warn);
    } // setupUi

    void retranslateUi(QDialog *temp_warn)
    {
        temp_warn->setWindowTitle(QApplication::translate("temp_warn", "\350\255\246\346\212\245", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class temp_warn: public Ui_temp_warn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEMP_WARN_H
