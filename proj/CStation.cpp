#include "CStation.h"

CStation::CStation()
{
    mStormIntensity = new CStation::StormIntensity();
    mDailyWeather = new CStation::DailyWeather();
    mHourlyRainfall = new CStation::HourlyRainfall();
}
