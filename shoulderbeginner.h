#ifndef SHOULDERBEGINNER_H
#define SHOULDERBEGINNER_H

#include <QDialog>
#include<QMovie>
#include<QLabel>
namespace Ui {
class shoulderbeginner;
}

class shoulderbeginner : public QDialog
{
    Q_OBJECT

public:
    explicit shoulderbeginner(QWidget *parent = nullptr);
    ~shoulderbeginner();

private:
    Ui::shoulderbeginner *ui;
    QMovie *movie;
    QLabel *label;
    int m_remainingTime;

private slots:
    void onMovieFinished();
    void on_backbutton_clicked();
    void on_madb_clicked();
    void on_pushButton_clicked();
    void updateTimer();
};

#endif // SHOULDERBEGINNER_H
