#ifndef CSTATION_H
#define CSTATION_H

#include <QString>
#include <QVector>
#include <QMap>

/* Brief: Represents one station in the XML */
class CStation
{


private:


public:
    /* Brief:
     */
    struct StormIntensity
    {
        // Attributes of <Storm_Intensity>, there are none as of 9/26/14
        QMap<QString, QString> mAttributes;
    };

    /* Brief:
     */
    struct HourlyRainfall
    {
        // Attributes of <Hourly_Rainfall>, there are none as of 9/26/14
        QMap<QString, QString> mAttributes;
    };

    /* Brief:
     */
    struct DailyWeather
    {
        QMap<QPair<QString, QString>, QVector<QString> > mWeather;
        
        // Attributes of <Weather>, there are none as of 9/26/14
        QMap<QString, QString> mAttributes;
    };

    CStation();

    QMap<QString, QString>& getAttributes(){return mAttributes;}
    
    // Station's XML attributes
    QMap<QString, QString> mAttributes;

    StormIntensity* mStormIntensity;

    HourlyRainfall* mHourlyRainfall;
    
    DailyWeather* mDailyWeather;
};

#endif // CSTATION_H
