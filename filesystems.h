#ifndef FILESYSTEMS_H
#define FILESYSTEMS_H

#include <QObject>
#include<QMap>
#include<QDebug>
#include<QFile>
#include<QDataStream>

struct Checklist
{
    int day;
    bool workout;
    bool diet;
    bool water;
    bool sleep;
    bool run;
};

struct Workout
{
    int day;
    bool chest;
    bool arms;
    bool shoulders;
    bool legs;
};
class filesystems : public QObject
{
    Q_OBJECT
public:
    explicit filesystems(QObject *parent = nullptr);


signals:

private:


public slots:
    void serialize_c(const Checklist &checklist);
    Checklist* deserialize_c();
    void serialize_w(const Workout &workout);
    Workout* deserialize_w();

};

#endif // FILESYSTEMS_H
