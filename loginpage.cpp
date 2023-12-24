#include "loginpage.h"
#include "ui_loginpage.h"
#include<QtSql>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QMessageBox>
#include<bmipage.h>
#include <mainwindow.h>
#include "state.h"
#include "qdebug.h"
#include<qcryptographichash.h>


loginpage::loginpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginpage)
{
    ui->setupUi(this);
}

loginpage::~loginpage()
{
    delete ui;
}

void loginpage::on_pushButton_clicked()
{
    QSqlDatabase database; // Creating a QSqlDatabase object to connect to the MySQL database.
    database=QSqlDatabase::addDatabase("QMYSQL","MyConnection"); //Setting up the database parameters for connection
    database.setHostName("localhost");
    database.setUserName("root");
    database.setPassword("");
    database.setDatabaseName("fitbit");

    QString username=ui->usernamelogin->text(); //extracting the username and password entered by user on loginpage.
    QString password=ui->passwordlogin->text();

    if (database.open()) {
        QSqlQuery qry(QSqlDatabase::database("MyConnection"));
        qry.prepare("SELECT username, password FROM fitbitusers WHERE username = :username");
        qry.bindValue(":username", username);

        if (!qry.exec())
        {
            QMessageBox::warning(this, "Fail", "Query Failed To Execute");
        } else {
            while (qry.next()) {
                QString usernameFromDatabase = qry.value(0).toString();
                QString hashedPasswordFromDatabase = qry.value(1).toString(); // Assuming the hashed password is stored as a hexadecimal string

                // Hash the entered password using MD5
                QByteArray hashedEnteredPassword = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Md5);

                // Compare hashed passwords
                if (usernameFromDatabase == username && hashedPasswordFromDatabase == hashedEnteredPassword.toHex())
                {
                    // Passwords match
                    QMessageBox::information(this, "Success", "Login Successful");
                    hide();
                    bmipage bmi;
                    bmi.setModal(true);
                    bmi.exec();
                    break;
                } else
                {
                    // Passwords do not match
                    QMessageBox::warning(this, "Error", "Incorrect username or password");
                }
            }
        }
        database.close();
    } else
    {
        QMessageBox::warning(this, "Fail", "Database Connection Failed");}
}

void loginpage::on_signupbutton_clicked()
{
    hide();
    MainWindow *nig = new MainWindow();
    nig->show();
}

