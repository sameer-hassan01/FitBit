#ifndef EXPARMS_H
#define EXPARMS_H

#include <QDialog>

namespace Ui {
class exparms;
}

class exparms : public QDialog
{
    Q_OBJECT

public:
    explicit exparms(QWidget *parent = nullptr);
    ~exparms();

private slots:
    void on_backA_clicked();

    void on_begA_clicked();

    void on_intA_clicked();

    void on_expA_clicked();

private:
    Ui::exparms *ui;
};

#endif // EXPARMS_H
