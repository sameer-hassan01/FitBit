#ifndef ARMSINTER_H
#define ARMSINTER_H

#include <QDialog>
#include <QMovie>
#include<QLabel>

namespace Ui {
class armsinter;
}

class armsinter : public QDialog
{
    Q_OBJECT

public:
    explicit armsinter(QWidget *parent = nullptr);
    ~armsinter();

private:
    Ui::armsinter *ui;
    QMovie *movie;
    QLabel *label;
    int m_remainingTime;

private slots:
    void onMovieFinished();
    void on_madb_clicked();
    void on_startimerb_clicked();
    void on_backbutton_clicked();
    void updateTimer();
};

#endif // ARMSINTER_H
