#ifndef SHOULDEREXPERT_H
#define SHOULDEREXPERT_H

#include <QDialog>
#include<QMovie>
#include<QLabel>

namespace Ui {
class shoulderexpert;
}

class shoulderexpert : public QDialog
{
    Q_OBJECT

public:
    explicit shoulderexpert(QWidget *parent = nullptr);
    ~shoulderexpert();


private:
    Ui::shoulderexpert *ui;
    QMovie *movie;
    QLabel *label;
    int m_remainingTime;

private slots:
    void onMovieFinished();
    void on_madb_clicked();
    void on_backbutton_clicked();
    void on_satrtimerb_clicked();
    void updateTimer();
};


#endif // SHOULDEREXPERT_H
