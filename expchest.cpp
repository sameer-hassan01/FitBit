#include "expchest.h"
#include "ui_expchest.h"
#include<workoutpage.h>
#include<chestbeginner.h>
#include<chestinter.h>
#include<chestexp.h>
#include "mainmenu.h"

expchest::expchest(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::expchest)
{
    ui->setupUi(this);
}

expchest::~expchest()
{
    delete ui;
}

void expchest::on_backC_clicked()
{
    hide();
    mainmenu b;
    b.setModal(true);
    b.exec();
}


void expchest::on_begC_clicked()
{
    hide();
    chestbeginner cb;
    cb.setModal(true);
    cb.exec();
}


void expchest::on_intC_clicked()
{
    hide();
    chestinter ci;
    ci.setModal(true);
    ci.exec();
}


void expchest::on_expC_clicked()
{
    hide();
    chestexp ce;
    ce.setModal(true);
    ce.exec();
}

