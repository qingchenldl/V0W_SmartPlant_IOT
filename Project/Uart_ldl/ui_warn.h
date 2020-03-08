/********************************************************************************
** Form generated from reading UI file 'warn.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WARN_H
#define UI_WARN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Warn
{
public:

    void setupUi(QDialog *Warn)
    {
        if (Warn->objectName().isEmpty())
            Warn->setObjectName(QStringLiteral("Warn"));
        Warn->resize(353, 93);
        Warn->setStyleSheet(QStringLiteral(""));

        retranslateUi(Warn);

        QMetaObject::connectSlotsByName(Warn);
    } // setupUi

    void retranslateUi(QDialog *Warn)
    {
        Warn->setWindowTitle(QApplication::translate("Warn", "\350\255\246\345\221\212", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Warn: public Ui_Warn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WARN_H
