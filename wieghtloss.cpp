#include "wieghtloss.h"
#include "mainmenu.h"
#include "ui_wieghtloss.h"

wieghtloss::wieghtloss(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::wieghtloss)
{
    ui->setupUi(this);
}

wieghtloss::~wieghtloss()
{
    delete ui;
}

void wieghtloss::on_backb_clicked()
{
    hide();
    mainmenu jh;
    jh.setModal(true);
    jh.exec();
}
