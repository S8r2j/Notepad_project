#ifndef ABOUT_ME_H
#define ABOUT_ME_H

#include <QDialog>
#include "QFile"
#include "QMessageBox"

namespace Ui {
class about_me;
}

class about_me : public QDialog
{
    Q_OBJECT

public:
    explicit about_me(QWidget *parent = nullptr);
    ~about_me();

private:
    Ui::about_me *ui;
};

#endif // ABOUT_ME_H
