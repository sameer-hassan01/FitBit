#include "shoulderexpert.h"
#include "ui_shoulderexpert.h"
#include "state.h"
#include "mainmenu.h"

#include <QTimer>
#include <QTime>
#include <QLCDNumber>
#include <QPushButton>
#include <QDebug>


shoulderexpert::shoulderexpert(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::shoulderexpert)
{
    ui->setupUi(this);
    movie=new QMovie("D:/FITBIT3.0/FITBIT/lraise.gif");
    if (!movie->isValid()) {
        // Handle error gracefully (e.g., display an error message)
        qDebug() << "Error loading GIF: images/lraise.gif";
        return;
    }

    label = new QLabel(this);
    label->setMovie(movie);
    // GIF positioning and scaling:
    label->setGeometry(180, 60,600,338);

    // Connect movie finished signal to restart playback
    connect(movie, &QMovie::finished, this, &shoulderexpert::onMovieFinished);

    // Start the animation
    movie->start();
    m_remainingTime = 0;
}

shoulderexpert::~shoulderexpert()
{
    movie->stop();
    delete ui;
}
void shoulderexpert::onMovieFinished()
{
    movie->start(); // Restart the GIF when it finishes
}

void shoulderexpert::on_madb_clicked()
{
    ::__shoulders = true;
}


void shoulderexpert::on_backbutton_clicked()
{
    hide();
    mainmenu mn;
    mn.setModal(true);
    mn.exec();
}


void shoulderexpert::on_satrtimerb_clicked()
{
    qDebug() << "Button clicked";
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &shoulderexpert::updateTimer);
    timer->start(1000); // Emit timeout signal every second
    qDebug() << "Timer started";

    m_remainingTime = 30; // Set initial remaining time to 30 seconds
    ui->lcdNumber->display(m_remainingTime);
}

void shoulderexpert::updateTimer()
{
    m_remainingTime--;
    ui->lcdNumber->display(m_remainingTime);

    if (m_remainingTime == 0) {
        // Timer has finished, perform any necessary actions here
        // ...

        // Stop the timer
        sender()->deleteLater(); // Delete the timer object
    }
}

