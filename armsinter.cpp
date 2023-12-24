#include "armsinter.h"
#include "ui_armsinter.h"
#include "state.h"
#include "workoutpage.h"

#include <QTimer>
#include <QLCDNumber>

armsinter::armsinter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::armsinter)
{
    ui->setupUi(this);

    movie=new QMovie("D:/FITBIT3.0/FITBIT/sbcurl.gif");
    if (!movie->isValid()) {
        // Handle error gracefully (e.g., display an error message)
        qDebug() << "Error loading GIF: images/sbcurl.gif";
        return;
    }

    label = new QLabel(this);
    label->setMovie(movie);
    // GIF positioning and scaling:
    label->setGeometry(180, 60,600,338);

    // Connect movie finished signal to restart playback
    connect(movie, &QMovie::finished, this, &armsinter::onMovieFinished);

    // Start the animation
    movie->start();
    m_remainingTime = 0;
}

armsinter::~armsinter()
{
    movie->stop();
    delete ui;
}
void armsinter::onMovieFinished()
{
    movie->start(); // Restart the GIF when it finishes
}

void armsinter::on_madb_clicked()
{
    ::__arms = true;
}

void armsinter::on_backbutton_clicked()
{
    hide();
    workoutpage wp;
    wp.setModal(true);
    wp.exec();
}

void armsinter::on_startimerb_clicked()
{
    qDebug() << "Button clicked";
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &armsinter::updateTimer);
    timer->start(1000); // Emit timeout signal every second
    qDebug() << "Timer started";

    m_remainingTime = 30; // Set initial remaining time to 30 seconds
    ui->lcdNumber->display(m_remainingTime);


}
void armsinter::updateTimer()
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

