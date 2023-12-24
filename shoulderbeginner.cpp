#include "shoulderbeginner.h"
#include "ui_shoulderbeginner.h"
#include "state.h"
#include "mainmenu.h"

#include <QTimer>
#include <QTime>
#include <QLCDNumber>
#include <QPushButton>
#include <QDebug>


shoulderbeginner::shoulderbeginner(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::shoulderbeginner)
{
    ui->setupUi(this);
    movie=new QMovie("D:/FITBIT3.0/FITBIT/shpress.gif");
    if (!movie->isValid()) {
        // Handle error gracefully (e.g., display an error message)
        qDebug() << "Error loading GIF: images/shpress.gif";
        return;
    }

    label = new QLabel(this);
    label->setMovie(movie);
    // GIF positioning and scaling:
    label->setGeometry(180, 60,600,338);

    // Connect movie finished signal to restart playback
    connect(movie, &QMovie::finished, this, &shoulderbeginner::onMovieFinished);

    // Start the animation
    movie->start();
    m_remainingTime = 0;
}

shoulderbeginner::~shoulderbeginner()
{
    movie->stop();
    delete ui;
}
void shoulderbeginner::onMovieFinished()
{
    movie->start(); // Restart the GIF when it finishes
}

void shoulderbeginner::on_backbutton_clicked()
{
    hide();
    mainmenu mm;
    mm.setModal(true);
    mm.exec();
}


void shoulderbeginner::on_madb_clicked()
{
    ::__shoulders=true;
}


void shoulderbeginner::on_pushButton_clicked()
{
    qDebug() << "Button clicked";
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &shoulderbeginner::updateTimer);
    timer->start(1000); // Emit timeout signal every second
    qDebug() << "Timer started";

    m_remainingTime = 30; // Set initial remaining time to 30 seconds
    ui->lcdNumber->display(m_remainingTime);
}

void shoulderbeginner::updateTimer()
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

