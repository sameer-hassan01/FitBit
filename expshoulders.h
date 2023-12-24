#ifndef EXPSHOULDERS_H
#define EXPSHOULDERS_H

#include <QDialog>

namespace Ui {
class expshoulders;
}

class expshoulders : public QDialog
{
    Q_OBJECT

public:
    explicit expshoulders(QWidget *parent = nullptr);
    ~expshoulders();

private slots:
    void on_backSh_clicked();

    void on_begSh_clicked();

    void on_intSh_clicked();

    void on_expSh_clicked();

private:
    Ui::expshoulders *ui;
};

#endif // EXPSHOULDERS_H
