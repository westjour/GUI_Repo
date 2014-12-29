//
//  CLaunchWindow.h
//  XMLEditor
//
//  Created by Jourdan West on 11/7/14.
//
//

#ifndef __XMLEditor__CLaunchWindow__
#define __XMLEditor__CLaunchWindow__

#include <QWidget>

/* Forward declaration this class so that we can use it as a
 member variable. It is actually defined in ui_launch.h */
namespace Ui {
    class LaunchForm;
}

class CLaunchWindow : public QWidget
{
    Q_OBJECT
    
public:
    explicit CLaunchWindow (QWidget *parent = 0);
    ~CLaunchWindow();

private slots:
    void onOpen();
    void onNewSDB();
    void onNewWDB();
    
private:
    void makeConnections();
    
    //
    // GUI Elements
    //
    Ui::LaunchForm *ui;
};

#endif /* defined(__XMLEditor__CLaunchWindow__) */
