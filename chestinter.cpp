#include "chestinter.h"
#include "ui_chestinter.h"
#include "mainmenu.h"
#include "state.h"

#include <QTimer>
#include <QTime>
#include <QLCDNumber>
#include <QPushButton>
#include <QDebug>

chestinter::chestinter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chestinter)
{

        ui->setupUi(this);

        // Load GIF using QMovie with error handling
        movie = new QMovie("D:/FITBIT3.0/FITBIT/bpchest.gif");
        if (!movie->isValid()) {
            // Handle error gracefully (e.g., display an error message)
            qDebug() << "Error loading GIF: images/bpchest.gif";
            return;
        }

        label = new QLabel(this);
        label->setMovie(movie);
        // GIF positioning and scaling:
        label->setGeometry(180, 60,600,338);

        // Connect movie finished signal to restart playback
        connect(movie, &QMovie::finished, this, &chestinter::onMovieFinished);

        // Start the animation
        movie->start();

        m_remainingTime = 0;
}

chestinter::~chestinter()
{
    // Stop the animation before deleting movie object
    movie->stop();
    delete ui;
}

void chestinter::onMovieFinished()
{
    movie->start(); // Restart the GIF when it finishes
}

void chestinter::on_back_clicked()
{
    hide();
    mainmenu mm;
    mm.setModal(true);
    mm.exec();

}

void chestinter::on_startimerb_clicked()
{
    qDebug() << "Button clicked";
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &chestinter::updateTimer);
    timer->start(1000); // Emit timeout signal every second
    qDebug() << "Timer started";

    m_remainingTime = 30; // Set initial remaining time to 30 seconds
    ui->lcdTimer->display(m_remainingTime);
}

void chestinter::updateTimer()
{
    m_remainingTime--;
    ui->lcdTimer->display(m_remainingTime);

    if (m_remainingTime == 0) {
        // Timer has finished, perform any necessary actions here
        // ...

        // Stop the timer
        sender()->deleteLater(); // Delete the timer object
    }
}


void chestinter::on_madb_clicked()
{
    ::__chest = true;
}

