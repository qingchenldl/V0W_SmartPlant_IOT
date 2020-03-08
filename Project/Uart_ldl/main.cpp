#include "mainwindow.h"
#include <QApplication>
#include <QCoreApplication>
#include <QtSql/QtSql>
#include <error.h>
#include <QDateTime>
#include<QMessageBox>
#include "logindialog.h"
QSqlQuery sql_query;

static bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("plant_d");
    if (!db.open()) {
        QMessageBox::critical(0, qApp->tr("Cannot open database"),
            qApp->tr("Unable to establish a database connection.\n"
                     "This example needs SQLite support. Please read "
                     "the Qt SQL driver documentation for information how "
                     "to build it.\n\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
        return false;
    }
    return true;
}
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    if(!createConnection())
        {
            return 1;
        }
        loginDialog l;
        QString Name;
        QString Pwd;
        if(l.exec()==QDialog::Accepted)
        {
            Name = l.GetName();
            Pwd = l.GetPwd();
            MainWindow w(Name, Pwd);
            w.show();
            return a.exec();
        }else
        {
            return 0;
        }
}
