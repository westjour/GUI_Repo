//
//  CWindowSDB.h
//  XMLEditor
//
//  Created by Jourdan West 9/12/14.
//
//

#ifndef __XMLEditor__CWindowWDB__
#define __XMLEditor__CWindowWDB__

#include <QMainWindow>

class CTableView;
class QComboBox;
class QLineEdit;
class CStation;

/* Forward declaration this class so that we can use it as a
member variable. It is actually defined in ui_mainWindow.h */
namespace Ui {
    class WDB;
}

class CWindowWDB : public QMainWindow
{
    Q_OBJECT

public:
    explicit CWindowWDB(QWidget *parent = 0, QString filename="NULL");
    ~CWindowWDB();

    void clearStationLineEdits();
    //void setFilename(QString filename){mFilename = filename;}

public slots:
    void stationIndexChanged(QString text);
    void yearIndexChanged(QString text);
    void onFileSave();
    void onFileOpen();
    void onStationDataChanged(QString field);

private:
    void buildMenuBar();
    void buildMacMenuBar();
    void saveXML();
    void makeConnections();
    void disableStationDataLineEdits();
    void enableStationDataLineEdits();
    
    QString mFilename;
    
    //
    // GUI Elements
    //
    Ui::WDB* ui;
    
    QMenuBar* macMenuBar;
    QAction* mFileSave;
    QAction* mFileOpen;
    QAction* mFileExit;
};

#endif /* defined(__XMLEditor__CWindowWDB__) */
