#ifndef CSTATION_H
#define CSTATION_H

#include <QString>
#include <QVector>
#include <QHash>
#include <QMap>

typedef QHash<QPair<QString, QString>, QVector<QString>* > Hash;
typedef QMap<QString, QString> AttrMap;

/* Brief: Represents one station in the XML */
class CStation
{

public:
    CStation();

    AttrMap& getAttributes(){return mStatAttr;}
    Hash* getWeather(){return mWeather;}
    
private:
    // Station's XML attributes
    AttrMap mStatAttr;

    Hash* mWeather;
    AttrMap* mWeatherAttr;
    AttrMap* mStormIntAttr;
    AttrMap* mHrRainAttr;
};

#endif // CSTATION_H
