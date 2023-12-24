#include "explegs.h"
#include "ui_explegs.h"
#include <workoutpage.h>
#include <legsbeginner.h>
#include <legsinter.h>
#include <legsexpert.h>
#include "mainmenu.h"
explegs::explegs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::explegs)
{
    ui->setupUi(this);
}

explegs::~explegs()
{
    delete ui;
}

void explegs::on_backL_clicked()
{
    hide();
    mainmenu l;
    l.setModal(true);
    l.exec();
}


void explegs::on_begL_clicked()
{
    hide();
    legsbeginner lb;
    lb.setModal(true);
    lb.exec();
}


void explegs::on_intL_clicked()
{
    hide();
    legsinter li;
    li.setModal(true);
    li.exec();
}


void explegs::on_expL_clicked()
{
    hide();
    legsexpert le;
    le.setModal(true);
    le.exec();
}

