#include "legsexpert.h"
#include "ui_legsexpert.h"
#include <workoutpage.h>
#include "state.h"
#include "mainmenu.h"

#include <QTimer>
#include <QTime>
#include <QLCDNumber>
#include <QPushButton>
#include <QDebug>

legsexpert::legsexpert(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::legsexpert)
{
    ui->setupUi(this);

    movie=new QMovie("D:/FITBIT3.0/FITBIT/BBsquat.gif");
    if (!movie->isValid()) {
        // Handle error gracefully (e.g., display an error message)
        qDebug() << "Error loading GIF: images/BBsquat.gif";
        return;
    }

    label = new QLabel(this);
    label->setMovie(movie);
    // GIF positioning and scaling:
    label->setGeometry(180, 60,600,338);

    // Connect movie finished signal to restart playback
    connect(movie, &QMovie::finished, this, &legsexpert::onMovieFinished);

    // Start the animation
    movie->start();
    m_remainingTime = 0;
}

legsexpert::~legsexpert()
{
    movie->stop();
    delete ui;
}
void legsexpert::onMovieFinished()
{
    movie->start(); // Restart the GIF when it finishes
}

void legsexpert::on_pushButton_clicked()
{
    hide();
    workoutpage bb;
    bb.setModal(true);
    bb.exec();
}


void legsexpert::on_madb_clicked()
{
    ::__legs = true;
}


void legsexpert::on_startimerb_clicked()
{
    qDebug() << "Button clicked";
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &legsexpert::updateTimer);
    timer->start(1000); // Emit timeout signal every second
    qDebug() << "Timer started";

    m_remainingTime = 30; // Set initial remaining time to 30 seconds
    ui->lcdNumber->display(m_remainingTime);
}

void legsexpert::updateTimer()
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

