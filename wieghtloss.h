#ifndef WIEGHTLOSS_H
#define WIEGHTLOSS_H

#include <QDialog>

namespace Ui {
class wieghtloss;
}

class wieghtloss : public QDialog
{
    Q_OBJECT

public:
    explicit wieghtloss(QWidget *parent = nullptr);
    ~wieghtloss();

private slots:
    void on_pushButton_clicked();

    void on_backb_clicked();

private:
    Ui::wieghtloss *ui;
};

#endif // WIEGHTLOSS_H
