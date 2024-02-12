#include "mainsence.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Mainsence w;
    w.show();
    return a.exec();
}
