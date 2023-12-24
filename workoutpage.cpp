#include "workoutpage.h"
#include "ui_workoutpage.h"
#include<QFile>
#include<QIODevice>
#include<mainmenu.h>
#include<exparms.h>
#include<expchest.h>
#include<explegs.h>
#include<expshoulders.h>

workoutpage::workoutpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::workoutpage)
{
    ui->setupUi(this);
}

workoutpage::~workoutpage()
{
    delete ui;
}




//Going to select experience page by selecting the bodypart for workout:



void workoutpage::on_arm_clicked()
{
    hide();
    exparms arms;
    arms.setModal(true);
    arms.exec();
}


void workoutpage::on_chest_clicked()
{
    hide();
    expchest chest;
    chest.setModal(true);
    chest.exec();
}


void workoutpage::on_legs_clicked()
{
    hide();
    explegs l;
    l.setModal(true);
    l.exec();
}


void workoutpage::on_shoulders_clicked()
{
    hide();
    expshoulders sh;
    sh.setModal(true);
    sh.exec();
}


void workoutpage::on_Backbutton_clicked()
{
    hide();
    mainmenu sh;
    sh.setModal(true);
    sh.exec();
}

