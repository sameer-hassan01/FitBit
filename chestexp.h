#ifndef CHESTEXP_H
#define CHESTEXP_H

#include <QDialog>
#include<QMovie>
#include<QLabel>
namespace Ui {
class chestexp;
}

class chestexp : public QDialog
{
    Q_OBJECT

public:
    explicit chestexp(QWidget *parent = nullptr);
    ~chestexp();

private:
    Ui::chestexp *ui;
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

#endif // CHESTEXP_H
