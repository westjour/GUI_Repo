#include "CDailyWeatherView.h"

CDailyWeatherView::CDailyWeatherView(QWidget *parent) :
    QTableView(parent)
{
    setAlternatingRowColors(true);
}
