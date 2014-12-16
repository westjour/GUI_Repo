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
#include <QDomNamedNodeMap>

class CTableView;
class QComboBox;
class QLineEdit;
class CStation;

/* Map where key=identifier(Soil, Layer, Station, etc.) and value is another map where key=attribute name
 * and value=attribute value */
typedef QMap<QString, QDomNamedNodeMap > AttrTemplate;

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
    void clearLineEdits();
    void disableLineEdits();
    void enableLineEdits();

    // Map of WDB template values
    AttrTemplate* mAttrTemplate;
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
