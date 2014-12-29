#include <QApplication>
#include "CLaunchWindow.h"
#include "CWindowSDB.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CLaunchWindow launchWindow;
    //CWindowSDB launchWindow;
    launchWindow.show();
    return a.exec();
}
