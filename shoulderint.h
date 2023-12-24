#ifndef SHOULDERINT_H
#define SHOULDERINT_H

#include <QDialog>
#include <QMovie>
#include <QLabel>

namespace Ui {
class shoulderint;
}

class shoulderint : public QDialog
{
    Q_OBJECT

public:
    explicit shoulderint(QWidget *parent = nullptr);
    ~shoulderint();


private:
    Ui::shoulderint *ui;
    QMovie *movie;
    QLabel *label;
    int m_remainingTime;

private slots:
    void onMovieFinished();
    void on_madb_clicked();
    void on_backbutton_clicked();
    void updateTimer();
    void on_startimerb_clicked();
};

#endif // SHOULDERINT_H
