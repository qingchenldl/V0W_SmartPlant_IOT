#include "logindialog.h"
#include"QSqlQuery"
#include <QSqlDatabase>
loginDialog::loginDialog(QWidget *parent) :
    QDialog(parent)
{
    label_Name = new QLabel(tr("登录名:"));
    label_Pwd = new QLabel(tr("密 码:"));
    line_Name = new QLineEdit();
    line_Pwd = new QLineEdit();
    btn_Login = new QPushButton(tr("确认"));
    btn_Cancle = new QPushButton(tr("取消"));

    line_Pwd->setEchoMode(QLineEdit::Password);
    label_Name->setMaximumWidth(40);
    label_Pwd->setMaximumWidth(40);
    line_Name->setMaximumWidth(100);
    line_Pwd->setMaximumWidth(100);
    QHBoxLayout *h1 = new QHBoxLayout();
    QHBoxLayout *h2 = new QHBoxLayout();
    QHBoxLayout *h3 = new QHBoxLayout();
    h1->addWidget(label_Name);
    h1->addWidget(line_Name);
    h2->addWidget(label_Pwd);
    h2->addWidget(line_Pwd);
    h3->addWidget(btn_Login);
    h3->addWidget(btn_Cancle);
    QVBoxLayout *v = new QVBoxLayout();
    v->addLayout(h1);
    v->addLayout(h2);
    v->addLayout(h3);
    this->setLayout(v);
    this->resize(200, 150);
    this->setMaximumSize(200, 150);
    connect(btn_Cancle, SIGNAL(clicked()), this, SLOT(close()));
    connect(btn_Login, SIGNAL(clicked()), this, SLOT(login_clicked()));
}

void loginDialog::login_clicked()
{
    name = line_Name->text();
    pwd = line_Pwd->text();
    qDebug()<<name;
    qDebug()<<pwd;

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName( "log.db");
    model = new QSqlTableModel(this);
    model->setTable("log");
    model->setFilter(QObject::tr("name = '%1' and pwd = '%2'").arg(name).arg(pwd));
    model->select();
    qDebug()<<model->rowCount();
    if(model->rowCount()==1)//查询到有一个结果
    {
        accept();//隐含窗口，并返回结果QDialg::Accepted
    }else
    {
        QMessageBox::warning(this, tr("warn"), tr("用户名或者密码不正确"));
        line_Name->clear();
        line_Pwd->clear();
        line_Name->setFocus();
    }
}
//返回登陆名
QString loginDialog::GetName()
{
    return name;
}
//返回密码
QString loginDialog::GetPwd()
{
    return pwd;
}
