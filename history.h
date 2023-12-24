#ifndef HISTORY_H
#define HISTORY_H

#include <QDialog>

namespace Ui {
class history;
}

class history : public QDialog
{
    Q_OBJECT

public:
    explicit history(QWidget *parent = nullptr);
    ~history();

private slots:
    void on_textBrowser_textChanged();

    void on_update_clicked();

    void on_menubutton_clicked();

private:
    Ui::history *ui;
};

#endif // HISTORY_H
