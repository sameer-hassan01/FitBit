#ifndef EXPLEGS_H
#define EXPLEGS_H

#include <QDialog>

namespace Ui {
class explegs;
}

class explegs : public QDialog
{
    Q_OBJECT

public:
    explicit explegs(QWidget *parent = nullptr);
    ~explegs();

private slots:
    void on_backL_clicked();

    void on_begL_clicked();

    void on_intL_clicked();

    void on_expL_clicked();

private:
    Ui::explegs *ui;
};

#endif // EXPLEGS_H
