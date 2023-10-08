#include "registro.h"
#include <QApplication>
#include <QVector>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    registro w;
    w.show();

    return a.exec();
}
