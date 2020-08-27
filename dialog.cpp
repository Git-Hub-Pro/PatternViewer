#include "dialog.h"
#include "ui_dialogorigin.h"

DialogOrigin::DialogOrigin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogOrigin)
{
    ui->setupUi(this);
}

DialogOrigin::~DialogOrigin()
{
    delete ui;
}
