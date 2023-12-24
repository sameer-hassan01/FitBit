#ifndef CHESTINTER_H
#define CHESTINTER_H

#include <QDialog>
#include <QLabel>
#include <QMovie>
namespace Ui {
class chestinter;
}

class chestinter : public QDialog
{
    Q_OBJECT

public:
    explicit chestinter(QWidget *parent = nullptr);
    ~chestinter();


private:
    Ui::chestinter *ui;
    QMovie *movie;
    QLabel *label;
    int m_remainingTime;
private slots:
    void onMovieFinished();
    void on_back_clicked();
    void on_startimerb_clicked();
    void updateTimer();
    void on_madb_clicked();
};

#endif // CHESTINTER_H
