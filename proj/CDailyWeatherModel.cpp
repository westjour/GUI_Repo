#include "CDailyWeatherModel.h"
#include "CStation.h"

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
int	CDailyWeatherModel::rowCount( const QModelIndex & parent ) const
{
    if (parent.isValid())
        return 0;
    return DAYS_IN_YEAR;
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
        // TODO - find chosen station, for now. just choose first
        //QVector<CStation::WeatherDay*> days = mStations[0]->mDailyWeather->mWeather;
        
        //QString val = days[row]->values[column];
        //return QVariant(val);
        return QVariant("abc");
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
