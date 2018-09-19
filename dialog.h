#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <vector>
using namespace std;

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    QString out;
    double pl;
    int act;
    bool wait;



private slots:
void show_n();
int read_n();
void cls_1();
int cls();
void show_2();
void sqr_t();

double plus();
double min();
double umn();
double del();



private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
