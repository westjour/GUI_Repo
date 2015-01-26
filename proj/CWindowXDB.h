//
//  CWindowXDB.h
//  XMLEditor
//
//  Created by Jourdan West on 1/26/15.
//
//

#ifndef XMLEditor_CWindowXDB_h
#define XMLEditor_CWindowXDB_h

#include <QMainWindow>

/* Forward declare this class so that we can use it as a
 member variable. It is actually defined in ui_xdb.h */
namespace Ui {
    class XDB;
}

class CWindowXDB : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit CWindowXDB(QWidget *parent = 0, QString filename="NULL");
    ~CWindowXDB();
    
    public slots:
    
private:
    /*QString mFilename;
    void buildMenuBar();
    void buildMacMenuBar();
    void makeConnections();
    void clearLineEdits();
    void disableLineEdits();
    void enableLineEdits();
    void saveXML(QString filename);*/
    
    
    //
    // GUI Elements
    //
    Ui::XDB* ui;
};


#endif
