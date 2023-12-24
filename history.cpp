#include "history.h"
#include "ui_history.h"
#include "filesystems.h"
#include <iostream>
#include "mainmenu.h"
#include <QDebug>
using namespace std;

history::history(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::history)
{
    ui->setupUi(this);
}

history::~history()
{
    delete ui;
}


void history::on_update_clicked()
{
    qDebug() << "button clicked";
    filesystems fs;

    //rading workout
    Workout* worklist;
    worklist = fs.deserialize_w();
    ui->textBrowser->setText("workout History: \n");
    for(int i = 0; i <50 && worklist[i].day !=0  ; i++)
    {
        ui->textBrowser->append("Day: ");
        QString qtString = QString::number(worklist[i].day);
        ui->textBrowser->append(qtString);
        ui->textBrowser->append("\n");

        if (worklist[i].shoulders == true)
        {
            ui->textBrowser->append("shoulder workout completed! \n");
        }
        else
        {
            ui->textBrowser->append("shoulder workout not completed :(\n");
        }
        if (worklist[i].arms == true)
        {
            ui->textBrowser->append("arms workout completed! \n");
        }
        else
        {
            ui->textBrowser->append("arms workout not completed :( \n");
        }
        if (worklist[i].chest == true)
        {
            ui->textBrowser->append("chest workout completed! \n");
        }
        else
        {
            ui->textBrowser->append("chest workout not completed :(\n");
        }
        if (worklist[i].legs == true)
        {
            ui->textBrowser->append("legs workout completed! \n");
        }
        else
        {
            ui->textBrowser->append("legs workout not completed :(\n");
        }
    }
    qDebug() << "workout";

    //reading checklist
    ui->textBrowser->append("Checklist History:\n");
    Checklist* readlist;
    readlist = fs.deserialize_c();

    ui->textBrowser->append("Day: ");
    for(int i = 0; i <50 && readlist[i].day !=0  ; i++)
    {

    QString qtString = QString::number(readlist[i].day);
    ui->textBrowser->append(qtString);
    ui->textBrowser->append("\n");

    if (readlist[i].workout == true)
    {
        ui->textBrowser->append("Workout completed!\n");
    }
    else
    {
        ui->textBrowser->append("Workout not completed :(\n");
    }
    if (readlist[i].sleep == true)
    {
        ui->textBrowser->append("Sleep completed! \n");
    }
    else
    {
        ui->textBrowser->append("Sleep not completed :( \n");
    }
    if (readlist[i].diet == true)
    {
        ui->textBrowser->append("diet followed! \n");
    }
    else
    {
        ui->textBrowser->append("Diet not followed :(\n");
    }
    if (readlist[i].water == true)
    {
        ui->textBrowser->append("Water Drank! \n");
    }
    else
    {
        ui->textBrowser->append("Water not Drank :(\n");
    }
    if (readlist[i].run == true)
    {
        ui->textBrowser->append("run Completed! \n");
    }
    else
    {
        ui->textBrowser->append("run not completed :(\n");
    }
    }
   qDebug()<< "checklist";
}


void history::on_menubutton_clicked()
{
    hide();
    mainmenu mm;
    mm.setModal(true);
    mm.exec();
}

