#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"

Dialog *dial;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dial=new Dialog();
    connect(ui->strat_c,SIGNAL(clicked()),this,SLOT(showDialog()));
    connect(ui->action,SIGNAL(triggered()),this,SLOT(showDialog()));
    connect(ui->action_close,SIGNAL(triggered()),this,SLOT(close()));
    connect(ui->action_close,SIGNAL(triggered()),dial,SLOT(close()));
    connect(ui->strat_c_2,SIGNAL(clicked()),this,SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete dial;
}

void MainWindow::showDialog(){
    dial->show();
}
