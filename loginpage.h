#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QDialog>
#include<QtSql>
#include<QSqlDatabase>
#include <QSqlQuery>



namespace Ui {
class loginpage;
}

class loginpage : public QDialog
{
    Q_OBJECT

public:
    explicit loginpage(QWidget *parent = nullptr);
    ~loginpage();

private slots:
    void on_pushButton_clicked();


    void on_signupbutton_clicked();

private:
    Ui::loginpage *ui;

};

#endif // LOGINPAGE_H
