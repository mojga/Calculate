#include "dialog.h"
#include "ui_dialog.h"

#include <vector>
#include <math.h>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),pl(0),act(0),wait(false),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);


    connect(ui->pushButton_1,SIGNAL(released()),this,SLOT(show_n()));
    connect(ui->pushButton_2,SIGNAL(released()),this,SLOT(show_n()));
    connect(ui->pushButton_3,SIGNAL(released()),this,SLOT(show_n()));
    connect(ui->pushButton_4,SIGNAL(released()),this,SLOT(show_n()));
    connect(ui->pushButton_5,SIGNAL(released()),this,SLOT(show_n()));
    connect(ui->pushButton_6,SIGNAL(released()),this,SLOT(show_n()));
    connect(ui->pushButton_7,SIGNAL(released()),this,SLOT(show_n()));
    connect(ui->pushButton_8,SIGNAL(released()),this,SLOT(show_n()));
    connect(ui->pushButton_9,SIGNAL(released()),this,SLOT(show_n()));
    connect(ui->pushButton_10,SIGNAL(released()),this,SLOT(show_n()));
    connect(ui->pushButton_11,SIGNAL(released()),this,SLOT(show_n()));

    connect(ui->pushButton_19,SIGNAL(clicked()),this,SLOT(sqr_t()));     // sqrt


    connect(ui->pushButton_12,SIGNAL(released()),this,SLOT(plus())); //+

    connect(ui->pushButton_13,SIGNAL(released()),this,SLOT(min())); //-

    connect(ui->pushButton_14,SIGNAL(released()),this,SLOT(umn())); //*

    connect(ui->pushButton_15,SIGNAL(released()),this,SLOT(del())); // /


    connect(ui->pushButton_16,SIGNAL(released()),this,SLOT(read_n())); // =

    connect(ui->pushButton_17,SIGNAL(released()),this,SLOT(cls_1())); // c

    connect(ui->pushButton_18,SIGNAL(released()),this,SLOT(cls()));   // <-

}

Dialog::~Dialog()
{   pl=0;

    delete ui;
}

void Dialog::cls_1(){
    QString text =ui->Output->text();
    text.chop(1);
    ui->Output->setText(text);
    QString text_2=ui->output_2->text();
    text_2.chop(1);
    ui->output_2->setText(text_2);
}

int Dialog::cls(){
    ui->Output->setText("0");
    ui->output_2->clear();
    pl=0;
    act=0;
    return pl;
    return act;

}
void Dialog::show_n(){

    QPushButton *button =(QPushButton*)sender();
    if(ui->Output->text()=="0" && button->text()!="."){
        ui->Output->clear();
    }
    else if(button->text()=="." && ui->Output->text()==""){
        ui->Output->setText("0.");

    }
    if(wait==true){
        ui->Output->clear();
        wait=false;
    }
    if( wait==false ){

        ui->Output->insert(button->text());

        show_2();
    }
}

void Dialog::show_2(){

    QPushButton *button =(QPushButton*)sender();
    ui->output_2->insert(button->text());

}


int Dialog::read_n(){                                  // =
    while(wait!=true){
        double per=ui->Output->text().toDouble();
        if(act==1){
            pl+=per;

        }
        else if(act==2){
            pl-=per;
        }
        else if(act==3){
            pl*=per;
        }
        else if(act==4){
            pl=pl/per;
        }
        else if(act==0){
            pl=per;
        }
        QString str;
        str.setNum(pl);
        ui->Output->setText(str);
        ui->output_2->insert("=");
        ui->output_2->insert(str);
        pl=0;
        act=0;
        wait=true;
    }
    return pl;
    return act;

}

void Dialog::sqr_t(){
    double per=ui->Output->text().toDouble();
    ui->Output->clear();
    per=sqrt(per);
    QString str;
    str.setNum(per);
    ui->Output->setText(str);
    ui->output_2->insert("√=");
    ui->output_2->insert(str);
}



double Dialog::plus()
{                                                           //+
    QString txt=ui->output_2->text();
    if(txt.endsWith("+")!=true){
        ui->output_2->insert("+");
    }
    if(txt.endsWith("-")==true){
        txt.chop(1);
        ui->output_2->setText(txt);
        ui->output_2->insert("+");
    }
    if(txt.endsWith("*")==true){
        txt.chop(1);
        ui->output_2->setText(txt);
        ui->output_2->insert("+");
    }
    if(txt.endsWith("/")==true){
        txt.chop(1);
        ui->output_2->setText(txt);
        ui->output_2->insert("+");
    }
    if(txt.endsWith("=")==true){
        txt.chop(1);
        ui->output_2->setText(txt);
        ui->output_2->insert("+");
    }
    if(txt.endsWith("√")==true){
        txt.chop(1);
        ui->output_2->setText(txt);
        ui->output_2->insert("√");
    }
    if(ui->Output->text().isEmpty()==false){
        double per=ui->Output->text().toDouble();
        if(act==1){
            pl+=per;
        }
        else if(act==2){
            pl-=per;
        }
        else if(act==3){
            pl*=per;
        }
        else if(act==4){
            pl=pl/per;
        }
        else if(act==0){
            pl=per;
        }
        ui->Output->clear();
    }
    act=1;

    return act;
    return pl;

}


double Dialog::min()
{                                                                    //-
    QString txt=ui->output_2->text();
    if(txt.endsWith("-")!=true){
        ui->output_2->insert("-");
    }
    if(txt.endsWith("+")==true){
        txt.chop(1);
        ui->output_2->setText(txt);
        ui->output_2->insert("-");
    }
    if(txt.endsWith("*")==true){
        txt.chop(1);
        ui->output_2->setText(txt);
        ui->output_2->insert("-");
    }
    if(txt.endsWith("/")==true){
        txt.chop(1);
        ui->output_2->setText(txt);
        ui->output_2->insert("-");
    }
    if(txt.endsWith("=")==true){
        txt.chop(1);
        ui->output_2->setText(txt);
        ui->output_2->insert("-");
    }
    if(txt.endsWith("√")==true){
        txt.chop(1);
        ui->output_2->setText(txt);
        ui->output_2->insert("√");
    }
    if(ui->Output->text().isEmpty()==false){
        double per=ui->Output->text().toDouble();
        if(act==1){
            pl+=per;

        }
        else if(act==2){
            pl-=per;
        }
        else if(act==3){
            pl*=per;
        }
        else if(act==4){
            pl=pl/per;
        }
        else if(act==0){
            pl=per;
        }

        ui->Output->clear();
    }
    act=2;

    return act;
    return pl;

}



double Dialog::umn()
{                                                                    //*
    QString txt=ui->output_2->text();
    if(txt.endsWith("*")!=true){
        ui->output_2->insert("*");
    }
    if(txt.endsWith("+")==true){
        txt.chop(1);
        ui->output_2->setText(txt);
        ui->output_2->insert("*");
    }

    if(txt.endsWith("-")==true){
        txt.chop(1);
        ui->output_2->setText(txt);
        ui->output_2->insert("*");
    }

    if(txt.endsWith("/")==true){
        txt.chop(1);
        ui->output_2->setText(txt);
        ui->output_2->insert("*");
    }
    if(txt.endsWith("=")==true){
        txt.chop(1);
        ui->output_2->setText(txt);
        ui->output_2->insert("*");
    }
    if(txt.endsWith("√")==true){
        txt.chop(1);
        ui->output_2->setText(txt);
        ui->output_2->insert("√");
    }

    if(ui->Output->text().isEmpty()==false){
        double per=ui->Output->text().toDouble();
        if(act==1){
            pl+=per;
        }
        else if(act==2){
            pl-=per;
        }
        else if(act==3){
            pl*=per;
        }
        else if(act==4){
            pl=pl/per;
        }
        else if(act==0){
            pl=per;
        }

        ui->Output->clear();
    }
    act=3;

    return act;
    return pl;
}



double Dialog::del()
{                                                        //    /
    QString txt=ui->output_2->text();
    if(txt.endsWith("/")!=true){
        ui->output_2->insert("/");
    }
    if(txt.endsWith("+")==true){
        txt.chop(1);
        ui->output_2->setText(txt);
        ui->output_2->insert("/");
    }

    if(txt.endsWith("-")==true){
        txt.chop(1);
        ui->output_2->setText(txt);
        ui->output_2->insert("/");
    }
    if(txt.endsWith("*")==true){
        txt.chop(1);
        ui->output_2->setText(txt);
        ui->output_2->insert("/");
    }

    if(txt.endsWith("=")==true){
        txt.chop(1);
        ui->output_2->setText(txt);
        ui->output_2->insert("/");
    }
    if(txt.endsWith("√")==true){
        txt.chop(1);
        ui->output_2->setText(txt);
        ui->output_2->insert("√");
    }

    if(ui->Output->text().isEmpty()==false){
        double per=ui->Output->text().toDouble();
        if(act==1){
            pl+=per;
        }
        else if(act==2){
            pl-=per;
        }
        else if(act==3){
            pl*=per;
        }
        else if(act==4){
            pl=pl/per;
        }
        else if(act==0){
            pl=per;
        }
        ui->Output->clear();
    }
    act=4;

    return act;
    return pl;

}






