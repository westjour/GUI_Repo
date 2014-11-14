#ifndef CSTATION_H
#define CSTATION_H

#include <QString>
#include <QVector>
#include <QMap>
#include <QHash>

typedef QHash<QPair<QString, QString>, QVector<QString>* > Hash;
typedef QMap<QString, QString> AttrMap;

/* Brief: Represents one station in the WDB XML */
class CStation
{

public:
    CStation();

    AttrMap* getStatAttrs(){return mStatAttr;}
    AttrMap* getWeatherAttrs(){return mWeatherAttr;}
    Hash* getWeather(){return mWeather;}
    
private:
    // Station's XML attributes
    AttrMap* mStatAttr;

    // contains data in the Daily weather section of WDB XML
    Hash* mWeather;
    
    // Map of attributes in the <Weather> tag of WDB XML
    AttrMap* mWeatherAttr;
    
    // Map of attributes in the <Storm_Intensity> tag of WDB XML
    AttrMap* mStormIntAttr;
    
    // Map of attributes in the <Hourly_Rainfall> tag of WDB XML
    AttrMap* mHrRainAttr;
};

#endif // CSTATION_H
