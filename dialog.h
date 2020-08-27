#ifndef DIALOGORIGIN_H
#define DIALOGORIGIN_H

#include <QDialog>

namespace Ui {
class DialogOrigin;
}

class DialogOrigin : public QDialog
{
    Q_OBJECT

public:
    explicit DialogOrigin(QWidget *parent = 0);
    ~DialogOrigin();

private:
    Ui::DialogOrigin *ui;
};

#endif // DIALOGORIGIN_H
