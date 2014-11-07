//
//  CLaunchWindow.cpp
//  XMLEditor
//
//  Created by Jourdan West on 11/7/14.
//
//

#include "CLaunchWindow.h"
#include "ui_launch.h"
#include "CMainWindow.h"

CLaunchWindow::CLaunchWindow(QWidget *parent): ui(new Ui::LaunchForm) {
    ui->setupUi(this);
    
    makeConnections();
}


/* Brief:
 */
void CLaunchWindow::makeConnections() {
    connect(ui->pushButtonOpen, SIGNAL(clicked(bool)), this, SLOT(onOpen()));
}


/*Brief:
 */
void CLaunchWindow::onOpen() {
    CMainWindow* window = new CMainWindow();
    window->show();
    
    
    // Since we have opened a window, we don't need to see the launch window anymore.
    //this->hide();
    
}

/* Brief:
 */
CLaunchWindow::~CLaunchWindow()
{
}
