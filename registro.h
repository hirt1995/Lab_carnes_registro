#ifndef REGISTRO_H
#define REGISTRO_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QScrollBar>
#include <QDateTime>
namespace Ui {
class registro;
}

class registro : public QMainWindow
{
    Q_OBJECT

public:
    explicit registro(QWidget *parent = nullptr);
    ~registro();

    void setDatosLog(QString renglon);
    void setDatosLog2(QString renglon2);

private slots:
    void on_pushButton_clicked();
    //void	onTextChanged(QString a_strString);

private:
    Ui::registro *ui;
};

#endif // REGISTRO_H
