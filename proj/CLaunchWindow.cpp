//
//  CLaunchWindow.cpp
//  XMLEditor
//
//  Created by Jourdan West on 11/7/14.
//
//

#include <QFileDialog>

#include "CLaunchWindow.h"
#include "ui_launch.h"
#include "CWindowWDB.h"
#include "CWindowSDB.h"

CLaunchWindow::CLaunchWindow(QWidget *parent): ui(new Ui::LaunchForm) {
    ui->setupUi(this);
    
    makeConnections();
}


/* Brief:
 */
void CLaunchWindow::makeConnections() {
    connect(ui->pushButtonOpen, SIGNAL(clicked(bool)), this, SLOT(onOpen()));
}


/*Brief: Automatically called when user clicks the Open button
 */
void CLaunchWindow::onOpen() {
    QString dir = "../../xml/";
    
    #ifdef Q_OS_MAC

    // This is necessary on MAC to get the file dialog to have correct default directory
    QString dummyFile = "dummyFile.txt";

    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), dir+dummyFile, tr("XML Files (*.xml)"));

    #endif


    #ifndef Q_OS_MAC

    QString defaultDir = "C:\\Users\\Jourdan\\Desktop\\GUI_Repo-master\\xml";
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), defaultDir, tr("XML Files (*.xml)"));

    #endif

    // User didn't select a file
    if(fileName == NULL)
        return;
    
    if(fileName.contains("sdb")) {
        qDebug("SDB file:%s", fileName.toUtf8().constData());
        CWindowSDB* window = new CWindowSDB(0, fileName);
        window->show();
    }
    else if (fileName.contains("wdb")) {
        qDebug("WDB file:%s", fileName.toUtf8().constData());
        CWindowWDB* window = new CWindowWDB(0, fileName);
        window->show();
    }
    
    
    
    
    // Since we have opened a window, we don't need to see the launch window anymore.
    this->hide();
}

/* Brief:
 */
CLaunchWindow::~CLaunchWindow()
{
}
