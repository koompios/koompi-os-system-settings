#include "systemsettings.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SystemSettings w;
    w.show();
    return a.exec();
}
