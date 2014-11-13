#include <QApplication>
#include "CLaunchWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CLaunchWindow launchWindow;
    launchWindow.show();
    return a.exec();
}
