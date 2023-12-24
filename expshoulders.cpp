#include "expshoulders.h"
#include "ui_expshoulders.h"
#include<workoutpage.h>
#include<shoulderbeginner.h>
#include<shoulderint.h>
#include<shoulderexpert.h>
#include"mainmenu.h"
expshoulders::expshoulders(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::expshoulders)
{
    ui->setupUi(this);
}

expshoulders::~expshoulders()
{
    delete ui;
}

void expshoulders::on_backSh_clicked()
{
    hide();
    mainmenu s;
    s.setModal(true);
    s.exec();
}


void expshoulders::on_begSh_clicked()
{
    hide();
    shoulderbeginner sb;
    sb.setModal(true);
    sb.exec();
}


void expshoulders::on_intSh_clicked()
{
    hide();
    shoulderint si;
    si.setModal(true);
    si.exec();
}


void expshoulders::on_expSh_clicked()
{
    hide();
    shoulderexpert se;
    se.setModal(true);
    se.exec();
}

