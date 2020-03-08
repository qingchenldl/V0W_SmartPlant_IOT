#include "dialog.h"
#include "ui_dialog.h"
#include <QLabel>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    u(new Ui::Dialog)
{


    u->setupUi(this);
    X = new QSqlTableModel(this);
    X->setTable("plant_data");
   // model.setFilter("Time > 20 and Time < 25");
    X->select();
    qDebug()<<X->rowCount();

    u->tableView_1->setModel(X);
    u->tableView_1->resizeColumnsToContents();
    u->tableView_1->setEditTriggers(QAbstractItemView::NoEditTriggers);

    my_Timer = new QTimer(this);
    my_Timer->setSingleShot(true);
    connect(my_Timer, &QTimer::timeout, this, [=](){this->close();});
}

Dialog::~Dialog()
{
    if(my_Timer != Q_NULLPTR)
        my_Timer->deleteLater();
    delete u;
}

void Dialog::startTimer(){
    //计时器设置为3秒
    my_Timer->start(3000);
}

void Dialog::on_dateTimeEdit_dateTimeChanged(const QDateTime &dateTime)
{
        QString d;
        d= dateTime.toString("yyyy-MM-dd");
        qDebug()<<d;
        X->setFilter(QObject::tr("Date = '%1'").arg(d));
        X->select();
        qDebug()<<X->rowCount();
        u->tableView_1->setModel(X);
        u->tableView_1->resizeColumnsToContents();
        u->tableView_1->setEditTriggers(QAbstractItemView::NoEditTriggers);

}
