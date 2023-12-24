#include "chestexp.h"
#include "ui_chestexp.h"
#include "mainmenu.h"
#include "state.h"
#include <QTimer>
#include <QLCDNumber>


chestexp::chestexp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chestexp)
{
    ui->setupUi(this);
    // Load GIF using QMovie with error handling
    movie = new QMovie("D:/FITBIT3.0/FITBIT/cfly.gif");
    if (!movie->isValid()) {
        // Handle error gracefully (e.g., display an error message)
        qDebug() << "Error loading GIF: images/cfly.gif";
        return;
    }

    label = new QLabel(this);
    label->setMovie(movie);
    // GIF positioning and scaling:
    label->setGeometry(180, 60,600,338);

    // Connect movie finished signal to restart playback
    connect(movie, &QMovie::finished, this, &chestexp::onMovieFinished);

    // Start the animation
    movie->start();
    m_remainingTime = 0;
}

chestexp::~chestexp()
{
    // Stop the animation before deleting movie object
    movie->stop();
    delete ui;
}
void chestexp::onMovieFinished()
{
    movie->start(); // Restart the GIF when it finishes
}

void chestexp::on_madb_clicked()
{
    ::__chest = true;
}


void chestexp::on_backbutton_clicked()
{
    hide();
    mainmenu mm;
    mm.setModal(true);
    mm.exec();
}


void chestexp::on_startimerb_clicked()
{
        qDebug() << "Button clicked";
        QTimer *timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &chestexp::updateTimer);
        timer->start(1000); // Emit timeout signal every second
        qDebug() << "Timer started";

        m_remainingTime = 30; // Set initial remaining time to 30 seconds
        ui->lcdNumber->display(m_remainingTime);
}

void chestexp::updateTimer()
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

