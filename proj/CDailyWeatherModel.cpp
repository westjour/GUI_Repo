#include "CDailyWeatherModel.h"
#include "CStation.h"
#include <algorithm>

int DAYS_IN_YEAR = 365;

CDailyWeatherModel::CDailyWeatherModel(QObject *parent) :
    QAbstractTableModel(parent)
{
    mYear = 1979;
}


/* Brief: TODO description
 * Parameter: parent, TODO description
 *
 * Note: When implementing a table based model, rowCount() should return 0 when the parent is valid.
 */
int CDailyWeatherModel::rowCount( const QModelIndex & parent ) const
{
    if (parent.isValid())
        return 0;
    return 3;//DAYS_IN_YEAR;
}


/* Brief: Force the model to update
 */
void CDailyWeatherModel::update()
{
    qDebug("inside CDailyWeatherModel::update");
    beginResetModel();
    endResetModel();
}


/* Brief: TODO description
 * Parameter: parent, TODO description
 *
 * Note: When implementing a table based model, columnCount() should return 0 when the parent is valid.
 */
int CDailyWeatherModel::columnCount( const QModelIndex & parent ) const
{
    if (parent.isValid())
        return 0;
    return CDailyWeatherModel::numColHeaders;
}


/* Brief: TODO description
 * Parameter: index, TODO description
 * Parameter: role, TODO description
 */
QVariant CDailyWeatherModel::data( const QModelIndex & index, int role ) const
{
    int column = index.column();
    int row = index.row();

    if (role == Qt::DisplayRole || role == Qt::EditRole)
    {
        if (column == CDailyWeatherModel::YEAR)
            return QVariant(mYear);
        else if (column == CDailyWeatherModel::DOY)
            return QVariant(row+1);
        else{
            // TODO - find correct station. for now, just use the first
            CStation* station = mStations[0];
            
            QMap<QPair<QString, QString>, QVector<QString> > weatherMap = station->mDailyWeather->mWeather;
            
            //qDebug("map size from inside model:%i", weatherMap.size());
            
            //QList<QPair<QString, QString> >::const_iterator citer = weatherMap.keys().begin();
            
            /*for(citer; citer!=weatherMap.keys().end(); citer++)
            {
                QPair<QString,QString> p = (*citer);
            }*/
            
            //QList<QPair<QString, QString> >::const_iterator citerEND = weatherMap.keys().end();
            //QPair<QString, QString> myPair = (*citer);
            
            /*if (row == 0 && column == 4)
            {
                if (weatherMap.contains(qMakePair(mYear, row+1)))
                    qDebug("map contains %i, day %i", mYear, row+1);
                else
                    qDebug("map doesn't contain %i, day %i", mYear, row+1);
            }*/
            
            return QVariant("abc");
            //return QVariant(value);
        }
    }

    else if (role == Qt::TextAlignmentRole)
        return QVariant(Qt::AlignCenter);
    else
        return QVariant();
}


/* Brief: TODO description
 * Parameter: index, TODO description
 */
Qt::ItemFlags CDailyWeatherModel::flags( const QModelIndex & index ) const
{
    Qt::ItemFlags defaultFlags = QAbstractItemModel::flags(index);

    if (index.isValid())
        // Return defaults flags AND the 'Editable' flag
        return Qt::ItemIsEditable | defaultFlags;
    else
        return defaultFlags;
}


/* Brief: TODO description
 * Parameter: section, TODO description
 * Parameter: orientation, TODO description
 * Parameter: role, TODO description
 */
QVariant CDailyWeatherModel::headerData( int section, Qt::Orientation orientation, int role ) const
{
    if (role == Qt::DisplayRole)
    {
        // Place label on horizontal header sections
        if (orientation == Qt::Horizontal)
        {
            if (section == CDailyWeatherModel::YEAR)
                    return QVariant("Year");
            else if (section == CDailyWeatherModel::DOY)
                    return QVariant("DOY");
            else if (section == CDailyWeatherModel::SRAD)
                    return QVariant("SRAD");
            else if (section == CDailyWeatherModel::TMAX)
                    return QVariant("Tmax");
            else if (section == CDailyWeatherModel::TMIN)
                    return QVariant("Tmin");
            else if (section == CDailyWeatherModel::RAIN)
                    return QVariant("Rain");
            else if (section == CDailyWeatherModel::DEWP)
                    return QVariant("DewP");
            else if (section == CDailyWeatherModel::WIND)
                    return QVariant("Wind");
            else if (section == CDailyWeatherModel::PAR)
                    return QVariant("PAR");
        }
        else
            return QVariant(int(section + 1));
    }

    else if ( role == Qt::TextAlignmentRole )
    {
        return QVariant(Qt::AlignCenter);
    }

    else
        return QVariant();
}


/* Brief: TODO description
 * Parameter: index, TODO description
 * Parameter: value, TODO description
 * Parameter: role, TODO description
 */
bool CDailyWeatherModel::setData( const QModelIndex & index, const QVariant & value, int role )
{
    if (index.isValid() && role == Qt::EditRole)
    {
        emit dataChanged(index, index);
        return true;
    }
    else
        return false;
}


/* Brief: Find the maximum and minimum Year values of the weather data.
 This is used to populate the year combobox box in the GUI
 */
QPair<int, int> getYearBounds()
{
 /* Note: this assumes that no year is skipped in the weather data. i could place a check to
  handle this but maybe its better to grab each year from the weather data and make
  a list */
    
}
