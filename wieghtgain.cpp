#include "wieghtgain.h"
#include "ui_wieghtgain.h"
#include "mainmenu.h"

wieghtgain::wieghtgain(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::wieghtgain)
{
    ui->setupUi(this);
}

wieghtgain::~wieghtgain()
{
    delete ui;
}

void wieghtgain::on_pushButton_clicked()
{
    hide();
    mainmenu mn;
    mn.setModal(true);
    mn.exec();
}

