#ifndef WARN_H
#define WARN_H

#include <QDialog>

namespace Ui {
class Warn;
}

class Warn : public QDialog
{
    Q_OBJECT

public:
    explicit Warn(QWidget *parent = 0);
    ~Warn();

private:
    Ui::Warn *ui;
};

#endif // WARN_H
