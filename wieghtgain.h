#ifndef WIEGHTGAIN_H
#define WIEGHTGAIN_H

#include <QDialog>

namespace Ui {
class wieghtgain;
}

class wieghtgain : public QDialog
{
    Q_OBJECT

public:
    explicit wieghtgain(QWidget *parent = nullptr);
    ~wieghtgain();

private slots:
    void on_pushButton_clicked();

private:
    Ui::wieghtgain *ui;
};

#endif // WIEGHTGAIN_H
