#ifndef CHESTBEGINNER_H
#define CHESTBEGINNER_H

#include <QDialog>
#include <QLabel>
#include <QMovie>

namespace Ui {
class chestbeginner;
}

class chestbeginner : public QDialog
{
    Q_OBJECT

public:
    explicit chestbeginner(QWidget *parent = nullptr);
    ~chestbeginner();

private:
    Ui::chestbeginner *ui;
    QMovie *movie;
    QLabel *label;
    int m_remainingTime;

private slots:
    void onMovieFinished();
    void on_madb_clicked();
    void on_backbutton_clicked();
    void on_startimerb_clicked();
    void updateTimer();
};

#endif // CHESTBEGINNER_H
