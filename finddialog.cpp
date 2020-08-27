#include "finddialog.h"
#include "ui_finddialog.h"

FindDialog::FindDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindDialog)
{
    ui->setupUi(this);
}

FindDialog::~FindDialog()
{
    delete ui;
}

void FindDialog::on_findButton_clicked()
{
    QString keyword = ui->lineEdit->text();

    connect(this,SIGNAL(sendKeyword(QString)),parent(),SLOT(receiveKeyword(QString)));

    emit sendKeyword(keyword);

}

void FindDialog::on_nextButton_clicked()
{
    QString keyword = ui->lineEdit->text();

    connect(this,SIGNAL(sendNextButtonSignal(QString)),parent(),SLOT(receiveNextButtonSignal(QString)));

    emit sendNextButtonSignal(keyword);

    disconnect(this, 0, 0, 0);
}

void FindDialog::closeEvent(QCloseEvent *event)
{
    connect(this,SIGNAL(sendDialogEndSignal()),parent(),SLOT(receiveDialogEndSignal()));
    emit sendDialogEndSignal();
    disconnect(this,0,0,0);

    QDialog::closeEvent(event);
}
