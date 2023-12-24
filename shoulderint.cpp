#include "shoulderint.h"
#include "ui_shoulderint.h"
#include "state.h"
#include "mainmenu.h"

#include <QTimer>
#include <QTime>
#include <QLCDNumber>
#include <QPushButton>
#include <QDebug>


shoulderint::shoulderint(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::shoulderint)
{
    ui->setupUi(this);
    movie=new QMovie("D:/FITBIT3.0/FITBIT/milpress.gif");
    if (!movie->isValid()) {
        // Handle error gracefully (e.g., display an error message)
        qDebug() << "Error loading GIF: images/milpress.gif";
        return;
    }

    label = new QLabel(this);
    label->setMovie(movie);
    // GIF positioning and scaling:
    label->setGeometry(180, 60,600,338);

    // Connect movie finished signal to restart playback
    connect(movie, &QMovie::finished, this, &shoulderint::onMovieFinished);

    // Start the animation
    movie->start();
    m_remainingTime = 0;
}

shoulderint::~shoulderint()
{
    movie->stop();
    delete ui;
}
void shoulderint::onMovieFinished()
{
    movie->start(); // Restart the GIF when it finishes
}

void shoulderint::on_madb_clicked()
{
    ::__shoulders=true;
}

void shoulderint::updateTimer()
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


void shoulderint::on_backbutton_clicked()
{
    hide();
    mainmenu mm;
    mm.setModal(true);
    mm.exec();
}


void shoulderint::on_startimerb_clicked()
{
    qDebug() << "Button clicked";
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &shoulderint::updateTimer);
    timer->start(1000); // Emit timeout signal every second
    qDebug() << "Timer started";

    m_remainingTime = 30; // Set initial remaining time to 30 seconds
    ui->lcdNumber->display(m_remainingTime);
}


