#ifndef LEGSBEGINNER_H
#define LEGSBEGINNER_H

#include <QDialog>
#include <QMovie>
#include<QLabel>
namespace Ui {
class legsbeginner;
}

class legsbeginner : public QDialog
{
    Q_OBJECT

public:
    explicit legsbeginner(QWidget *parent = nullptr);
    ~legsbeginner();

private:
    Ui::legsbeginner *ui;
    QMovie *movie;
    QLabel *label;
    int m_remainingTime;

private slots:
    void onMovieFinished();
    void on_pushButton_clicked();
    void on_madb_clicked();
    void on_startimerb_clicked();
    void updateTimer();
};

#endif // LEGSBEGINNER_H
