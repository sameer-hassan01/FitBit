#ifndef EXPCHEST_H
#define EXPCHEST_H

#include <QDialog>

namespace Ui {
class expchest;
}

class expchest : public QDialog
{
    Q_OBJECT

public:
    explicit expchest(QWidget *parent = nullptr);
    ~expchest();

private slots:
    void on_backC_clicked();

    void on_begC_clicked();

    void on_intC_clicked();

    void on_expC_clicked();

private:
    Ui::expchest *ui;
};

#endif // EXPCHEST_H
