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

class CWindowSDB : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit CWindowSDB(QWidget *parent = 0, QString filename="NULL");
    ~CWindowSDB();
    
public slots:
    
    
private:
    QString mFilename;
};

#endif /* defined(__XMLEditor__CWindowSDB__) */
