//
//  CSoil.h
//  XMLEditor
//
//  Created by Jourdan West on 11/14/14.
//
//

#ifndef __XMLEditor__CSoil__
#define __XMLEditor__CSoil__

#include <QString>
#include <QVector>
#include <QMap>
typedef QMap<QString, QString> AttrMap;
typedef QMap<QString, QString> Layer;

/* Brief: Represents one soil in the SDB XML */
class CSoil
{
    
public:
    CSoil();
    AttrMap* getSoilAttrs(){return mSoilAttr;}
    QVector<Layer*>* getLayers(){return &mLayers;}
    
private:
    // Station's XML attributes
    AttrMap* mSoilAttr;

    QVector<Layer*> mLayers;
    
};

#endif /* defined(__XMLEditor__CSoil__) */
