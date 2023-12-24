#include "experience.h"
#include "ui_experience.h"
#include<workoutpage.h>
#include<QObject>


experience::experience(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::experience)
{
    ui->setupUi(this);
}

experience::~experience()
{
    delete ui;
}

void experience::on_back_clicked()
{
    hide();
    workoutpage wp;
    wp.setModal(true);
    wp.exec();
}





