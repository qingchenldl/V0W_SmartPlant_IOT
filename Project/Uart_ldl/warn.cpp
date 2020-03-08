#include "warn.h"
#include "ui_warn.h"

Warn::Warn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Warn)
{
    ui->setupUi(this);
}

Warn::~Warn()
{
    delete ui;
}
