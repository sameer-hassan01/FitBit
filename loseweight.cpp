#include "loseweight.h"
#include "ui_loseweight.h"
#include "mainmenu.h"

loseweight::loseweight(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::loseweight)
{
    ui->setupUi(this);
}

loseweight::~loseweight()
{
    delete ui;
}

void loseweight::on_backb_clicked()
{
    hide();
    mainmenu mn;
    mn.setModal(true);
    mn.exec();
}

