#include "checklist.h"
#include "ui_checklist.h"
#include "bmipage.h"
#include "history.h"
#include "filesystems.h"
#include "state.h"

QString __username;
bool __shoulders;
bool __arms;
bool __chest;
bool __legs;

checklist::checklist(QWidget *parent)
    : QDialog(parent)

    , ui(new Ui::checklist)
{
    ui->setupUi(this);
}

checklist::~checklist()
{
    delete ui;
}

//- making boolean operators for checklist textfile.
bool sleep = false;
bool water = false;
bool workout = false;
bool diet = false;
bool run = false;



void checklist::on_sleepcheck_toggled(bool checked)
{
    sleep = true;
}

void checklist::on_workoutcheck_toggled(bool checked)
{
    workout = true;
}

void checklist::on_dietcheck_toggled(bool checked)
{
    diet = true;
}

void checklist::on_watercheck_toggled(bool checked)
{
    water = true;
}

void checklist::on_runcheck_toggled(bool checked)
{
    run = true;
}



void checklist::on_checkbmibutton_clicked()
{
    hide();
    bmipage Bmipage;
    Bmipage.setModal(true);
    Bmipage.exec();
}


void checklist::on_historybutton_clicked()
{
    hide();
    history History;
    History.setModal(true);
    History.exec();
}



filesystems fs; // Create an instance of the filesystems class


//connect(endDayButton, &QPushButton::clicked, this, &YourClass::enddaybuttonClicked);
int daycounter = 1;
void checklist::on_enddaybutton_clicked()
{
    daycounter++;

    // Construct a Checklist object:
    Checklist checklist;
    //checklist.user = ::__username; // Replace with actual username
    checklist.day = daycounter; // Adjust for the current day
    checklist.workout = workout;
    checklist.diet = diet;
    checklist.water = water;
    checklist.sleep = sleep;
    checklist.run = run;

    // Serialize the Checklist to the file:
    fs.serialize_c(checklist);

    //construct a workout object:
    Workout workout;
    workout.day = daycounter;
    workout.shoulders = ::__shoulders;
    workout.arms = ::__arms;
    workout.chest = ::__chest;
    workout.legs = ::__legs;

    //serialize the workout txt file
    fs.serialize_w(workout);

    //unchecking all the checkboxes for new day
    ui->workoutcheck->setChecked(false);
    ui->dietcheck->setChecked(false);
    ui->watercheck->setChecked(false);
    ui->runcheck->setChecked(false);
    ui->sleepcheck->setChecked(false);
    sleep,workout,diet,water,run,__chest,__shoulders,__legs,__arms = false;


}
