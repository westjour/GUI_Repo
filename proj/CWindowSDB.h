//
//  CWindowSDB.h
//  XMLEditor
//
//  Created by Jourdan West on 11/10/14.
//
//

#ifndef __XMLEditor__CWindowSDB__
#define __XMLEditor__CWindowSDB__

#include <QMainWindow>

/* Forward declaration this class so that we can use it as a
 member variable. It is actually defined in ui_mainWindow.h */
namespace Ui {
    class SDB;
}

class CWindowSDB : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit CWindowSDB(QWidget *parent = 0, QString filename="NULL");
    ~CWindowSDB();
    
public slots:
    
    
private:
    QString mFilename;
    
    //
    // GUI Elements
    //
    Ui::SDB* ui;
};

#endif /* defined(__XMLEditor__CWindowSDB__) */
