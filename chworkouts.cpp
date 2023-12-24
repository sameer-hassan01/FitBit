#include "chworkouts.h"
#include "ui_chworkouts.h"

chworkouts::chworkouts(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chworkouts)
{
    ui->setupUi(this);
}

chworkouts::~chworkouts()
{
    delete ui;
}
