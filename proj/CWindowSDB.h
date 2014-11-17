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
    void onSoilChanged(QString id);
    void onFileSave();
    
    
private:
    QString mFilename;
    void buildMenuBar();
    void buildMacMenuBar();
    void makeConnections();
    void clearLineEdits();
    void disableLineEdits();
    void enableLineEdits();
    void saveXML(QString filename);

    
    //
    // GUI Elements
    //
    Ui::SDB* ui;
    
    QMenuBar* macMenuBar;
    QAction* mFileSave;
    QAction* mFileOpen;
    QAction* mFileExit;
};

#endif /* defined(__XMLEditor__CWindowSDB__) */
