#ifndef LEGSINTER_H
#define LEGSINTER_H

#include <QDialog>
#include <QMovie>
#include <QLabel>
namespace Ui {
class legsinter;
}

class legsinter : public QDialog
{
    Q_OBJECT

public:
    explicit legsinter(QWidget *parent = nullptr);
    ~legsinter();

private:
    Ui::legsinter *ui;
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

#endif // LEGSINTER_H
