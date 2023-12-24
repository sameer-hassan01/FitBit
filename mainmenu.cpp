#include "mainmenu.h"
#include "ui_mainmenu.h"
#include<workoutpage.h>
#include"checklist.h"
#include "loginpage.h"
#include "bmipage.h"
#include "history.h"
#include "choosediet.h"

mainmenu::mainmenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainmenu)
{
    ui->setupUi(this);
}

mainmenu::~mainmenu()
{
    delete ui;
}

void mainmenu::on_workouts_clicked()
{
    hide();
    workoutpage wp;
    wp.setModal(true);
    wp.exec();
}


void mainmenu::on_dailyactivity_clicked()
{
    hide();
    checklist cl;
    cl.setModal(true);
    cl.exec();
}


void mainmenu::on_signoutbutton_clicked()
{
    hide();
    loginpage lp;
    lp.setModal(true);
    lp.exec();
}


void mainmenu::on_checkbmibutton_clicked()
{
    hide();
    bmipage bp;
    bp.setModal(true);
    bp.exec();
}



void mainmenu::on_historybutton_clicked()
{
    hide();
    history hh;
    hh.setModal(true);
    hh.exec();
}


void mainmenu::on_diets_clicked()
{
    hide();
    choosediet cd;
    cd.setModal(true);
    cd.exec();
}

