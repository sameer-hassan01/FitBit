#include "armsbeginner.h"
#include "ui_armsbeginner.h"
#include "workoutpage.h"
#include <QTimer>
#include <QLCDNumber>
#include "state.h"

armsbeginner::armsbeginner(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::armsbeginner)
{
    ui->setupUi(this);

    // Load GIF using QMovie with error handling
    movie = new QMovie("D:/FITBIT3.0/FITBIT/hamcurl.gif");
    if (!movie->isValid()) {
        // Handle error gracefully (e.g., display an error message)
        qDebug() << "Error loading GIF: images/hamcurl.gif";
        return;
    }

    label = new QLabel(this);
    label->setMovie(movie);
    // GIF positioning and scaling:
    label->setGeometry(180, 60,600,338);

    // Connect movie finished signal to restart playback
    connect(movie, &QMovie::finished, this, &armsbeginner::onMovieFinished);

    // Start the animation
    movie->start();
    m_remainingTime = 0;
}

armsbeginner::~armsbeginner()
{
    movie->stop();
    delete ui;
}
void armsbeginner::onMovieFinished()
{
    movie->start(); // Restart the GIF when it finishes
}

void armsbeginner::on_backbutton_clicked()
{
    hide();
    workoutpage wp;
    wp.setModal(true);
    wp.exec();
}


;

void armsbeginner::on_startimerb_clicked()
{
    qDebug() << "Button clicked";
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &armsbeginner::updateTimer);
    timer->start(1000); // Emit timeout signal every second
    qDebug() << "Timer started";

    m_remainingTime = 30; // Set initial remaining time to 30 seconds
    ui->lcdTimer->display(m_remainingTime);
}
void armsbeginner::updateTimer()
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


void armsbeginner::on_madb_clicked()
{
    ::__arms = true;
}

