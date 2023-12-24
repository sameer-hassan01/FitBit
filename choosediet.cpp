#include "choosediet.h"
#include "ui_choosediet.h"
#include "mainmenu.h"
#include "history.h"
#include "bmipage.h"
#include "loginpage.h"
#include "wieghtgain.h"
#include "loseweight.h"
#include "wieghtmaintain.h"

choosediet::choosediet(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::choosediet)
{
    ui->setupUi(this);
}

choosediet::~choosediet()
{
    delete ui;
}

void choosediet::on_backbutton_clicked()
{
    hide();
    mainmenu mm;
    mm.setModal(true);
    mm.exec();
}


void choosediet::on_checkbmi_clicked()
{
    hide();
    bmipage bp;
    bp.setModal(true);
    bp.exec();
}


void choosediet::on_history_clicked()
{
    hide();
    history HIS;
    HIS.setModal(true);
    HIS.exec();
}


void choosediet::on_history_2_clicked()
{
    hide();
    loginpage lp;
    lp.setModal(true);
    lp.exec();
}


void choosediet::on_diet1b_clicked()
{
    hide();
    wieghtgain wg;
    wg.setModal(true);
    wg.exec();
}


void choosediet::on_diet2b_clicked()
{
    hide();
    wieghtmaintain wl;
    wl.setModal(true);
    wl.exec();
}


void choosediet::on_diet3b_clicked()
{
    hide();
    loseweight wm;
    wm.setModal(true);
    wm.exec();
}

