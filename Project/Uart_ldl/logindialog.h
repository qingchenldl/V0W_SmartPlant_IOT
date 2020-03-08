#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QSqlTableModel>
#include<QLabel>
#include<QLineEdit>
#include<QHBoxLayout>
#include<QPushButton>
#include<QMessageBox>
#include<QDebug>
class loginDialog : public QDialog
{
    Q_OBJECT
public:
    explicit loginDialog(QWidget *parent = 0);
    QString GetName();
    QString GetPwd();
signals:
public slots:
    void login_clicked();

private:
    QLabel *label_Name;
    QLabel *label_Pwd;
    QLineEdit *line_Name;
    QLineEdit *line_Pwd;
    QPushButton *btn_Login;
    QPushButton *btn_Cancle;
    QString name;
    QString pwd;
    QSqlTableModel *model;
    QSqlDatabase  db;
};
#endif // LOGINDIALOG_H
