#ifndef CHOOSEDIET_H
#define CHOOSEDIET_H

#include <QDialog>

namespace Ui {
class choosediet;
}

class choosediet : public QDialog
{
    Q_OBJECT

public:
    explicit choosediet(QWidget *parent = nullptr);
    ~choosediet();

private slots:
    void on_backbutton_clicked();

    void on_checkbmi_clicked();

    void on_history_clicked();

    void on_history_2_clicked();

    void on_diet1b_clicked();

    void on_diet2b_clicked();

    void on_diet3b_clicked();

private:
    Ui::choosediet *ui;
};

#endif // CHOOSEDIET_H
