#include "exparms.h"
#include "ui_exparms.h"
#include<workoutpage.h>
#include<armsbeginner.h>
#include<armsinter.h>
#include<armsexp.h>
#include "mainmenu.h"
exparms::exparms(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::exparms)
{
    ui->setupUi(this);
}

exparms::~exparms()
{
    delete ui;
}

void exparms::on_backA_clicked()
{
    hide();
    mainmenu a;
    a.setModal(true);
    a.exec();
}


void exparms::on_begA_clicked()
{
    hide();
    armsbeginner ab;
    ab.setModal(true);
    ab.exec();
}


void exparms::on_intA_clicked()
{
    hide();
    armsinter ai;
    ai.setModal(true);
    ai.exec();
}


void exparms::on_expA_clicked()
{
    hide();
    armsexp ae;
    ae.setModal(true);
    ae.exec();
}

