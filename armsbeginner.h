#ifndef ARMSBEGINNER_H
#define ARMSBEGINNER_H

#include <QDialog>
#include<QMovie>
#include<QLabel>

namespace Ui {
class armsbeginner;
}

class armsbeginner : public QDialog
{
    Q_OBJECT

public:
    explicit armsbeginner(QWidget *parent = nullptr);
    ~armsbeginner();


private:
    Ui::armsbeginner *ui;
    QMovie *movie;
    QLabel *label;
    int m_remainingTime;

private slots:
    void onMovieFinished();
    void on_backbutton_clicked();
    void on_startimerb_clicked();
    void on_madb_clicked();
    void updateTimer();
};

#endif // ARMSBEGINNER_H
