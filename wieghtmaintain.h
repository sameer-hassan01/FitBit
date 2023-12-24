#ifndef WIEGHTMAINTAIN_H
#define WIEGHTMAINTAIN_H

#include <QDialog>

namespace Ui {
class wieghtmaintain;
}

class wieghtmaintain : public QDialog
{
    Q_OBJECT

public:
    explicit wieghtmaintain(QWidget *parent = nullptr);
    ~wieghtmaintain();

private slots:
    void on_backb_clicked();

private:
    Ui::wieghtmaintain *ui;
};

#endif // WIEGHTMAINTAIN_H
