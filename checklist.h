#ifndef CHECKLIST_H
#define CHECKLIST_H

#include <QDialog>

namespace Ui {
class checklist;
}

class checklist : public QDialog
{
    Q_OBJECT

public:
    explicit checklist(QWidget *parent = nullptr);
    ~checklist();

private slots:
    void on_sleepcheck_toggled(bool checked);

    void on_workoutcheck_toggled(bool checked);

    void on_dietcheck_toggled(bool checked);

    void on_watercheck_toggled(bool checked);

    void on_runcheck_toggled(bool checked);

    void on_checkbmibutton_clicked();

    void on_historybutton_clicked();

    void on_enddaybutton_clicked();

private:
    Ui::checklist *ui;

};

#endif // CHECKLIST_H
