#include "CMainWindow.h"
#include <QApplication>
#include "CLaunchWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CLaunchWindow launchWindow;
    launchWindow.show();
    //CMainWindow w;
    //w.show();
    return a.exec();
}
