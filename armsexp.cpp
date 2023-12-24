#include "armsexp.h"
#include "ui_armsexp.h"
#include "state.h"
#include "mainmenu.h"

#include <QTimer>
#include <QTime>
#include <QLCDNumber>
#include <QPushButton>
#include <QDebug>


armsexp::armsexp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::armsexp)
{
    ui->setupUi(this);
    movie=new QMovie("D:/FITBIT3.0/FITBIT/KB-Pcurl.gif");
    if (!movie->isValid()) {
        // Handle error gracefully (e.g., display an error message)
        qDebug() << "Error loading GIF: images/KB-Pcurl.gif";
        return;
    }

    label = new QLabel(this);
    label->setMovie(movie);
    // GIF positioning and scaling:
    label->setGeometry(180, 60,600,338);

    // Connect movie finished signal to restart playback
    connect(movie, &QMovie::finished, this, &armsexp::onMovieFinished);

    // Start the animation
    movie->start();
    m_remainingTime = 0;
}

armsexp::~armsexp()
{
    movie->stop();
    delete ui;
}
void armsexp::onMovieFinished()
{
    movie->start(); // Restart the GIF when it finishes
}


void armsexp::on_madb_clicked()
{
    ::__arms = true;
}


void armsexp::on_startimerb_clicked()
{
    qDebug() << "Button clicked";
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &armsexp::updateTimer);
    timer->start(1000); // Emit timeout signal every second
    qDebug() << "Timer started";

    m_remainingTime = 30; // Set initial remaining time to 30 seconds
    ui->lcdNumber->display(m_remainingTime);
}

void armsexp::updateTimer()
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


void armsexp::on_pushButton_clicked()
{
    hide();
    mainmenu mm;
    mm.setModal(true);
    mm.exec();
}

