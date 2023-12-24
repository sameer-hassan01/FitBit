#ifndef BMIPAGE_H
#define BMIPAGE_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class bmipage;
}

class bmipage : public QDialog
{
    Q_OBJECT

public:
    explicit bmipage(QWidget *parent = nullptr);
    ~bmipage();

private slots:


    void on_bmisubmit_clicked();

private:
    Ui::bmipage *ui;
};

#endif // BMIPAGE_H
