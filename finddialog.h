#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include "finddialog.h"
#include "ui_finddialog.h"
#include <QDebug>
#include <QDialog>
#include <QCloseEvent>

namespace Ui {
class FindDialog;
}

class FindDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FindDialog(QWidget *parent = 0);
    ~FindDialog();

signals:
        void sendKeyword(QString keyword);
        void sendNextButtonSignal(QString keyword);
        void sendDialogEndSignal();


private slots:
    void on_findButton_clicked();

    void on_nextButton_clicked();

private:
    Ui::FindDialog *ui;

private:

public:
    void closeEvent(QCloseEvent *event);

};

#endif // FINDDIALOG_H



