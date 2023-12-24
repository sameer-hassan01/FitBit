#ifndef WORKOUT_H
#define WORKOUT_H

#include <QDialog>

namespace Ui {
class workout;
}

class workout : public QDialog
{
    Q_OBJECT

public:
    explicit workout(QWidget *parent = nullptr);
    ~workout();

private:
    Ui::workout *ui;
};

#endif // WORKOUT_H
