#include "iniwrite.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IniWrite w;
    w.show();

    return a.exec();
}
