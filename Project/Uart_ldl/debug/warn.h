#ifndef TEMP_WARN_H
#define TEMP_WARN_H

#include <QDialog>

namespace Ui {
class warn;
}

class warn : public QDialog
{
    Q_OBJECT

public:
    explicit warn(QWidget *parent = 0);
    ~warn();

private:
    Ui::warn *ui;
};

#endif // TEMP_WARN_H
