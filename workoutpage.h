#ifndef WORKOUTPAGE_H
#define WORKOUTPAGE_H

#include <QDialog>

namespace Ui {
class workoutpage;
}

class workoutpage : public QDialog
{
    Q_OBJECT

public:
    explicit workoutpage(QWidget *parent = nullptr);
    ~workoutpage();

private slots:


    void on_arm_clicked();

    void on_chest_clicked();

    void on_legs_clicked();

    void on_shoulders_clicked();

    void on_Backbutton_clicked();

private:
    Ui::workoutpage *ui;
};

#endif // WORKOUTPAGE_H
