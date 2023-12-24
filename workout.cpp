#include "workout.h"


workout::workout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::workout)
{
    ui->setupUi(this);
}

workout::~workout()
{
    delete ui;
}

void workout::on_checkBox_stateChanged(int arg1)
{

}

