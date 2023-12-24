#include "filesystems.h"
#include "loginpage.h"
#include "state.h"
#include <QDebug>

filesystems::filesystems(QObject *parent)
    : QObject{parent}
{}

void filesystems::serialize_c(const Checklist &checklist)
{

    QFile file(::__username + "_c");
    if (!file.open(QIODevice::Append)) {
        qDebug() << "Error opening file for writing";
        return;
    }

    QDataStream out(&file);
    out << checklist.day;
    out << checklist.workout;
    out << checklist.diet;
    out << checklist.water;
    out << checklist.sleep;
    out << checklist.run;

    file.close();

}
void filesystems::serialize_w(const Workout &workout)
{

    QFile file(::__username + "_w");
    if (!file.open(QIODevice::Append)) {
        qDebug() << "Error opening file for writing";
        return;
    }

    QDataStream out(&file);
    out << workout.day;
    out << workout.chest;
    out << workout.arms;
    out << workout.chest;
    out << workout.legs;

    file.close();

}

Checklist* filesystems::deserialize_c()
{
    Checklist *checklist = new Checklist[50];

    QFile file(::__username + "_c");
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Error opening file for reading";
        return checklist; // Return an empty checklist on error
    }
    QDataStream in(&file);
    int i=0;
    while(!in.atEnd()){
        in >> checklist[i].day;
        in >> checklist[i].workout;
        in >> checklist[i].diet;
        in >> checklist[i].water;
        in >> checklist[i].sleep;
        in >> checklist[i].run;
        i++;
    }

    file.close();
    return checklist;
}
Workout* filesystems::deserialize_w()
{
    Workout *workout = new Workout[50];

    QFile file(::__username + "_w");
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Error opening file for reading";
        return workout; // Return an empty workout on error
    }

    int c = 0;
    QDataStream in(&file);
    while(!in.atEnd()){
    in >> workout[c].day;
    in >> workout[c].shoulders;
    in >> workout[c].arms;
    in >> workout[c].chest;
    in >> workout[c].legs;
    c++;
    }
    file.close();
    return workout;
}
