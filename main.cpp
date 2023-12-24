#include "mainwindow.h"

#include <QApplication>
#include<QScreen>
#include<QFile>
#include<QIODevice>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowFlags(w.windowFlags() & ~Qt ::WindowMaximizeButtonHint & ~Qt::WindowMinimizeButtonHint);

    QScreen *screen=QGuiApplication::primaryScreen();
    int screenWidth=1280;
    int screenHeight=720;
    QRect screenGeometry= screen->geometry();
    screenGeometry.setWidth(screenWidth);
    screenGeometry.setHeight(screenHeight);
    w.setGeometry(screenGeometry);
    w.show();
    return a.exec();
}

