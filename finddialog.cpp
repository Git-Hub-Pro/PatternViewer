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

    connect(this,SIGNAL(sendKeywordToMainWindow(QString)),parent(),SLOT(receiveKeywordFromFindDialog(QString)));
    emit sendKeywordToMainWindow(keyword);
    disconnect(this, 0, 0, 0);
}

void FindDialog::on_nextButton_clicked()
{
    QString keyword = ui->lineEdit->text();

    connect(this,SIGNAL(sendNextButtonSignalToMainWindow(QString)),parent(),SLOT(receiveNextButtonSignalFromFindDialog(QString)));

    emit sendNextButtonSignalToMainWindow(keyword);

    disconnect(this, 0, 0, 0);
}

void FindDialog::closeEvent(QCloseEvent *event)
{
    QString keyword = ui->lineEdit->text();

    if(keyword.length()==0)
        return;

    connect(this,SIGNAL(sendDialogEndSignalToMainWindow()),parent(),SLOT(receiveDialogEndSignalFromFindDialog()));
    emit sendDialogEndSignalToMainWindow();
    disconnect(this,0,0,0);

    QDialog::closeEvent(event);
}
