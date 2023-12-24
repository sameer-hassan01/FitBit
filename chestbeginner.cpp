#include "chestbeginner.h"
#include "ui_chestbeginner.h"
#include "mainmenu.h"
#include "state.h"
#include <QTimer>
#include <QLCDNumber>

chestbeginner::chestbeginner(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chestbeginner)
{
    ui->setupUi(this);

    // Load GIF using QMovie with error handling
    movie = new QMovie("D:/FITBIT3.0/FITBIT/dbchest.gif");
    if (!movie->isValid()) {
        // Handle error gracefully (e.g., display an error message)
        qDebug() << "Error loading GIF: images/dbchest.gif";
        return;
    }

    label = new QLabel(this);
    label->setMovie(movie);
    // GIF positioning and scaling:
    label->setGeometry(180, 60,500,500);

    // Connect movie finished signal to restart playback
    connect(movie, &QMovie::finished, this, &chestbeginner::onMovieFinished);

    // Start the animation
    movie->start();
    m_remainingTime = 0;
}

chestbeginner::~chestbeginner()
{
    // Stop the animation before deleting movie object
    movie->stop();
    delete ui;
}

void chestbeginner::onMovieFinished()
{
    movie->start(); // Restart the GIF when it finishes
}

void chestbeginner::on_backbutton_clicked()
{
    hide();
    mainmenu mm;
    mm.setModal(true);
    mm.exec();
}


void chestbeginner::on_startimerb_clicked()
{
    qDebug() << "Button clicked";
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &chestbeginner::updateTimer);
    timer->start(1000); // Emit timeout signal every second
    qDebug() << "Timer started";

    m_remainingTime = 30; // Set initial remaining time to 30 seconds
    ui->lcdNumber->display(m_remainingTime);
}

void chestbeginner::updateTimer()
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
