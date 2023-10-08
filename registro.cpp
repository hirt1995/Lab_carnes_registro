#include "registro.h"
#include "ui_registro.h"
#include <QVector>


registro::registro(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::registro)
{
    ui->setupUi(this);
}

registro::~registro()
{
    delete ui;
}

void registro::setDatosLog(QString renglon)
{
    QString contAnt;
    QString contAct;
//txt de registro
    QFile log("Logs/Embutidora_Data/embutidora.txt");
    //QFile log2("molino.txt");

    //LEER REGISTRO
    if(ui->radioEmb->isChecked()){
        if (log.open(QIODevice::ReadOnly)){
            QTextStream leer(&log);
            contAnt.append((leer.readAll()));
            log.close();
        }

        if (log.open(QIODevice::WriteOnly)){
            QTextStream escribir(&log);
            escribir<<contAnt;
            escribir<<renglon;
            log.close();
        }

        if (log.open(QIODevice::ReadOnly)){
            QTextStream leer(&log);
            contAct.append((leer.readAll()));
            log.close();
        }
        ui->textEdit_2->setPlainText(contAct);
        ui->textEdit_2->verticalScrollBar()->setValue(ui->textEdit_2->verticalScrollBar()->maximum());
    }



    if(ui->radioMolino->isChecked()){
        if (log2.open(QIODevice::ReadOnly)){
            QTextStream leer(&log2);
            contAnt.append((leer.readAll()));
            log2.close();
        }

        if (log2.open(QIODevice::WriteOnly)){
            QTextStream escribir(&log2);
            escribir<<contAnt;
            escribir<<renglon;
            log2.close();
        }

        if (log2.open(QIODevice::ReadOnly)){
            QTextStream leer(&log2);
            contAct.append((leer.readAll()));
            log2.close();
        }
        ui->textEdit_2->setPlainText(contAct);
        ui->textEdit_2->verticalScrollBar()->setValue(ui->textEdit_2->verticalScrollBar()->maximum());
    }
}

void registro::setDatosLog2(QString renglon2)
{
    QString varLubAnt;
    QString varLubAct;
    QString varMan;

//txt de varibales
    QFile Var("Logs/Embutidora_Data/Variables.txt");
    //LEER VARIABLES
    if(ui->CabanoBox->isChecked()){
        if(Var.open(QIODevice::ReadOnly)){
            QTextStream leer(&Var);
            varLubAnt.append((leer.readAll()));
            Var.close();
        }
        if (Var.open(QIODevice::WriteOnly)){
            QTextStream escribir(&Var);
            escribir<<varLubAnt;
            escribir<<varMan;
            escribir<<renglon2;
            Var.close();
        }
        if (Var.open(QIODevice::ReadOnly)){
            QTextStream leer(&Var);
            varLubAct.append((leer.readAll()));
            Var.close();
        }
    }
}

void registro::on_pushButton_clicked()
{
//EMBUTIDORA
    QFile log("Logs/Embutidora_Data/embutidora.txt");
    //FALTA MOLINO
    QFile Var("Logs/Embutidora_Data/Variables.txt");
    QString nuevodato;
    QString nuevodato_2;
    QVector<QString> Data;
    QString varLub;

    int Hembutidora=0;
    int AuxEmbutidora=0;
    QString auxembutidora;
    int Hmolino=0;
    int Hcutter=0;
    int Hhonro=0;
    int Hsierra=0;
    int Hempacadora=0;

    if(ui->radioEmb->isChecked() && ui->textEdit->document()->isEmpty()==false){

       if(ui->CabanoBox->isChecked()){

        AuxEmbutidora= AuxEmbutidora + Hembutidora;
        auxembutidora= QString::number(AuxEmbutidora);

        nuevodato.append(QDateTime::currentDateTime().toString("hh:mm:ss"));
        nuevodato.append(" ");
        nuevodato.append(ui->textEdit->toPlainText());
        nuevodato.append("\n");
        nuevodato.append(auxembutidora);
        nuevodato.append("\r""\n");
        setDatosLog(nuevodato);

            //problemas aca, no podemos sumar lo que pasa en el txt
        //borra los datos del txt pendiente de pensar si usar csv
        if (Var.open(QIODevice::WriteOnly)){
            QTextStream escribir(&Var);
            escribir<<"";
            Var.close();
        }
        //tratar de leer la linea ver que hacer con eso
        if(Var.open(QIODevice::ReadOnly)){
            QTextStream leer(&Var);
            varLub.append((leer.readLine()));
            Var.close();
        }

            //AuxEmbutidora= AuxEmbutidora+20;
            //auxembutidora =QString::number(AuxEmbutidora);
        int prueba = varLub.toInt();
            nuevodato_2.append(prueba);
            setDatosLog2(nuevodato_2);



     }else if(ui->radioEmb->isChecked() && ui->textEdit->document()->isEmpty()){
            ui->textEdit_2->setPlainText("");

       }
    }


//MOLINO(aun no esta listo)
    if(ui->radioMolino->isChecked() && ui->textEdit->document()->isEmpty()==false){
         nuevodato.append(QDateTime::currentDateTime().toString("hh:mm:ss"));
         nuevodato.append(" ");
         nuevodato.append(ui->textEdit->toPlainText());
         nuevodato.append("\r""\n");
         setDatosLog(nuevodato);
     }else if(ui->radioEmb->isChecked() && ui->textEdit->document()->isEmpty()){
        ui->textEdit_2->setPlainText("");
     }

        ui->textEdit->setPlainText("");

}

