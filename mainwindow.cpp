#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include<QLabel>
#include<loginpage.h>
#include<QRegularExpression>
#include<qcryptographichash.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Signup Page");
    ui->username_2->setPlaceholderText("Enter Your Username");
    ui->password_2->setPlaceholderText("Enter Your Password");
    ui->email_2->setPlaceholderText("Enter Your Email");
    ui->phone_2->setPlaceholderText("Enter Your Phone");


}

MainWindow::~MainWindow()
{
    delete ui;
}

const QRegularExpression& getEmailRegex()
{
    static const QRegularExpression regex(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})"); //making constant check function to validate the correct format of email during user registration.
    return regex;
}

const QRegularExpression& getPhoneRegex()
{
    static const QRegularExpression regex(R"(\d{11})");  //making constant check function to validate the correct format of phone number during user registration.
    return regex;
}

void MainWindow::on_register_2_clicked()
{
    //Connecting to MYSQL database

    database=QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("localhost");
    database.setUserName("root");
    database.setPassword("");
    database.setDatabaseName("fitbit");

    if(database.open())
    {
        // Retrieving input

        QString username=ui->username_2->text();
        QString password=ui->password_2->text();
        QString email=ui->email_2->text();
        QString phone=ui->phone_2->text();

        //Checking if user has filled all the required fields for signup
        if (ui->username_2->text().isEmpty() ||
            ui->password_2->text().isEmpty() ||
            ui->email_2->text().isEmpty() ||
            ui->phone_2->text().isEmpty())
        {
            QMessageBox::warning(this, "Error", "Please fill in all required fields.");
            database.close();
            return;
        }
        // Validate email format using a static QRegularExpression object
        if (!getEmailRegex().match(email).hasMatch())
        {
            QMessageBox::warning(this, "Error", "Invalid email format.");
            database.close();
            return;
        }

        // Validate phone number format using a static QRegularExpression object
        if (!getPhoneRegex().match(phone).hasMatch())
        {
            QMessageBox::warning(this, "Error", "Invalid phone number format.");
            database.close();
            return;
        }

        QByteArray hashedPassword=QCryptographicHash::hash(password.toUtf8(),QCryptographicHash::Md5);

        // Inserting our input data into the database using sql query

        QSqlQuery qry;
        qry.prepare("Insert Into fitbitusers(username,password,email,phone)" "Values(:username,:password,:email,:phone)" );
        qry.bindValue(":username",username);
        qry.bindValue(":password",QString(hashedPassword.toHex()));
        qry.bindValue(":email",email);
        qry.bindValue(":phone",phone);



        // If Signup Successful
        if(qry.exec())
        {
            QMessageBox::information(this,"Success","SignUp Successful");
            hide();
            loginpage lp;
            lp.setModal(true);
            lp.exec();
        }
        else
        {
            QMessageBox::information(this,"Failed","SignUp Failed");
        }
    }
    else
    {
        QMessageBox::information(this,"Not Connected","Database is not connected");}
}


void MainWindow::on_pushButton_clicked()
{
    hide();
    loginpage lp;
    lp.setModal(true);
    lp.exec();
}

