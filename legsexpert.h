#ifndef LEGSEXPERT_H
#define LEGSEXPERT_H

#include <QDialog>
#include <QMovie>
#include <QLabel>

namespace Ui {
class legsexpert;
}

class legsexpert : public QDialog
{
    Q_OBJECT

public:
    explicit legsexpert(QWidget *parent = nullptr);
    ~legsexpert();

private:
    Ui::legsexpert *ui;
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

#endif // LEGSEXPERT_H
