#include "warn.h"

warn::warn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::warn)
{
    ui->setupUi(this);
}

warn::~warn()
{
    delete ui;
}
