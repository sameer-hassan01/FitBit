#ifndef ARMSEXP_H
#define ARMSEXP_H

#include <QDialog>
#include <QMovie>
#include<QLabel>
namespace Ui {
class armsexp;
}

class armsexp : public QDialog
{
    Q_OBJECT

public:
    explicit armsexp(QWidget *parent = nullptr);
    ~armsexp();

private:
    Ui::armsexp *ui;
    QMovie *movie;
    QLabel *label;
    int m_remainingTime;

private slots:
    void onMovieFinished();
    void on_madb_clicked();
    void on_startimerb_clicked();
    void on_backbutton_clicked();
    void updateTimer();
    void on_pushButton_clicked();
};

#endif // ARMSEXP_H
