#include "wieghtmaintain.h"
#include "ui_wieghtmaintain.h"
#include "mainmenu.h"

wieghtmaintain::wieghtmaintain(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::wieghtmaintain)
{
    ui->setupUi(this);
}

wieghtmaintain::~wieghtmaintain()
{
    delete ui;
}

void wieghtmaintain::on_backb_clicked()
{
    hide();
    mainmenu mn;
    mn.setModal(true);
    mn.exec();
}

