#ifndef ARMS_H
#define ARMS_H

#include <QDialog>

namespace Ui {
class arms;
}

class arms : public QDialog
{
    Q_OBJECT

public:
    explicit arms(QWidget *parent = nullptr);
    ~arms();

private:
    Ui::arms *ui;
};

#endif // ARMS_H
