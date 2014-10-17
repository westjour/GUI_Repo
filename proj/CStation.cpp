#include "CStation.h"

CStation::CStation()
{
    mWeather = new Hash;
    mWeatherAttr = new AttrMap;
    mStormIntAttr = new AttrMap;
    mHrRainAttr = new AttrMap;
}
