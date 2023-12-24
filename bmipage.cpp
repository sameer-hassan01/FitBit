#include "bmipage.h"
#include "ui_bmipage.h"
#include <QLabel>
#include <QApplication>
#include <cmath>
#include<QString>
#include<mainmenu.h>

bmipage::bmipage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bmipage)
{
    ui->setupUi(this);
    ui->heightinput->setPlaceholderText("Enter your height in cm.");
    ui->weightinput->setPlaceholderText("Enter your weight in kg.");
}

bmipage::~bmipage()
{
    delete ui;
}

double calculateBmi(double weight, double height) {                     //function to calculate bmi
    if (weight <= 0 || height <= 0) {
        return -1; // Handle invalid input
    }
    return weight / pow(height / 100, 2);                             //function returns the value of bmi
}

void bmipage::on_bmisubmit_clicked()
{
    // Get user input
    double weight = ui->weightinput->text().toDouble();
    double height = ui->heightinput->text().toDouble();                // user input fields to input height and weight for bmi calculation

    // Calculate BMI
    double bmi = calculateBmi(weight, height);                 //bmi function call
    // QString b=to_string(bmi);
    QString b = QString::number(bmi, 'f', 3);
    //QMessageBox::information(this,"BMI",b);
    if (bmi < 18.5) {                                                                                    // conditionals used for different ranges of bmi values for underweight, good weight, over weight and obese.
        QMessageBox::information(nullptr, "BMI", QString("Your BMI: %1\nTime to grab a bite.").arg(b));
    } else if (bmi >= 18.5 && bmi < 25.0) {
        QMessageBox::information(nullptr, "BMI", QString("Your BMI: %1\nYou are in the Normal Weight range.").arg(b));
    } else if (bmi >= 25.0 && bmi < 30.0) {
        QMessageBox::information(nullptr, "BMI", QString("Your BMI: %1\nYou are in the Overweight range.").arg(b));
    } else {
        QMessageBox::information(nullptr, "BMI", QString("Your BMI: %1\nYou are in the Obese range.").arg(b));
    }


    hide();
    mainmenu mm;                                               // after bmi calculation and display program proceeds to the mainmenu of the application.
    mm.setModal(true);
    mm.exec();
}

