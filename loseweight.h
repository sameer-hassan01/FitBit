#ifndef LOSEWEIGHT_H
#define LOSEWEIGHT_H

#include <QDialog>

namespace Ui {
class loseweight;
}

class loseweight : public QDialog
{
    Q_OBJECT

public:
    explicit loseweight(QWidget *parent = nullptr);
    ~loseweight();

private slots:
    void on_backb_clicked();

private:
    Ui::loseweight *ui;
};

#endif // LOSEWEIGHT_H
