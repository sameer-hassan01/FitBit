#ifndef MAINMENU_H
#define MAINMENU_H

#include <QDialog>

namespace Ui {
class mainmenu;
}

class mainmenu : public QDialog
{
    Q_OBJECT

public:
    explicit mainmenu(QWidget *parent = nullptr);
    ~mainmenu();

private slots:
    void on_workouts_clicked();

    void on_dailyactivity_clicked();

    void on_signoutbutton_clicked();

    void on_checkbmibutton_clicked();

    void on_historybutton_clicked();

    void on_diets_clicked();

private:
    Ui::mainmenu *ui;
};

#endif // MAINMENU_H
