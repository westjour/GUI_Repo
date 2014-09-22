#ifndef CSTATION_H
#define CSTATION_H

#include <map>
#include <QString>
#include <QVector>

/* Brief: Represents one station in the XML */
class CStation
{


private:


public:
    /* Brief:
     */
    struct StormIntensity
    {
        // Attributes of <Storm_Intensity>, there are none as of 9/18/14
        std::map<QString, QString> mAttributes;
    };

    /* Brief:
     */
    struct HourlyRainfall
    {
        // Attributes of <Hourly_Rainfall>, there are none as of 9/18/14
        std::map<QString, QString> mAttributes;
    };

    /* Brief: This structure represents a single weather day (i.e.,
     * one line of the Daily Weather data section)
     */
    struct WeatherDay
    {
        // These are the values parsed from the WDB xml weather data section
        QVector<QString> values;
    };

    /* Brief:
     */
    struct DailyWeather
    {
        void printWeather()
        {
            QVector<WeatherDay*>::const_iterator citer;
            for(citer=mWeather.begin(); citer!=mWeather.end();citer++)
            {
                WeatherDay* wd = *citer;
                for(int k=0; k!=wd->values.size(); k++)
                    qDebug("value[%i]=%s", k, wd->values[k].toUtf8().constData());
            }
        }

       QVector<WeatherDay*> mWeather; //TODO rename 'mDays'

        // Attributes of <Weather>, there are none as of 9/18/14
        std::map<QString, QString> mAttributes;
    };

    CStation();

    std::map<QString, QString>& getAttributes(){return mAttributes;}
    StormIntensity* getStormIntensity(){return mStormIntensity;}
    HourlyRainfall* getHourlyRainFall(){return mHourlyRainfall;}
    DailyWeather* getDailyWeather(){return mDailyWeather;}

    // Station's XML attributes
    std::map<QString, QString> mAttributes;

    StormIntensity* mStormIntensity;

    HourlyRainfall* mHourlyRainfall;

    DailyWeather* mDailyWeather;
};

#endif // CSTATION_H
