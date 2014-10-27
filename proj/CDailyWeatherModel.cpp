#include "CDailyWeatherModel.h"
#include "CStation.h"

int DAYS_IN_YEAR = 365;

CDailyWeatherModel::CDailyWeatherModel(QObject *parent) :
    QAbstractTableModel(parent)
{
    mYear = 1979;
    mStation = NULL;
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
    return DAYS_IN_YEAR;
}


/* Brief: Force the model to update
 */
void CDailyWeatherModel::update()
{
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
 *
 * Note: This function is called
 */
QVariant CDailyWeatherModel::data( const QModelIndex & index, int role ) const
{
    int column = index.column();
    int row = index.row();

    //qDebug("from inside Data(), row:%i, col:%i, role=%i, counter=%i", row, column, role, counter);
    
    if (role == Qt::DisplayRole || role == Qt::EditRole)
    {
        if (mStation == NULL)
            return QVariant("n/a");
        
        if (column == CDailyWeatherModel::YEAR)
            return QVariant(mYear);
        else if (column == CDailyWeatherModel::DOY)
            return QVariant(row+1);
        else {
            // Note: Be sure to use pointer here! Else, the map will be returned by value. This means
            // that a copy of this huge map will be made whenever this function is called (whenever
            // the model needs to be updated or the table needs to be redraen - potentially many times.
            // This will lag the interface.
            Hash* hash = mStation->getWeather();
            
            QString yr = QString::number(mYear);
            QString doy = QString::number(row+1);
            Pair pair(yr, doy);
            
           
            // Find item in weather map with key
            Hash::const_iterator iter = hash->find(pair);
            
            // (Year, Day of Year) not found in weather data map for the current station
            if(iter == hash->end())
                return QVariant("n/a");
            
            return QVariant(iter.value()->at(column-2));
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
            
            switch(section) {
                case CDailyWeatherModel::YEAR:
                    return QVariant("Year");
                case CDailyWeatherModel::DOY:
                    return QVariant("DOY");
                case CDailyWeatherModel::SRAD:
                    return QVariant("SRAD");
                case CDailyWeatherModel::TMAX:
                    return QVariant("Tmax");
                case CDailyWeatherModel::TMIN:
                    return QVariant("Tmin");
                case CDailyWeatherModel::RAIN:
                    return QVariant("Rain");
                case CDailyWeatherModel::DEWP:
                    return QVariant("DewP");
                case CDailyWeatherModel::WIND:
                    return QVariant("Wind");
                case CDailyWeatherModel::PAR:
                    return QVariant("PAR");
            }
            
        }
        else // vertical headers
            return QVariant(int(section + 1));
    }

    else if ( role == Qt::TextAlignmentRole )
    {
        return QVariant(Qt::AlignCenter);
    }

    return QVariant();
}


/* Brief: TODO description
 * Parameter: index, TODO description
 * Parameter: value, TODO description
 * Parameter: role, TODO description
 */
bool CDailyWeatherModel::setData( const QModelIndex & index, const QVariant & value, int role )
{
    int column = index.column();
    int row = index.row();
    
    Hash* hash = mStation->getWeather();

    QString yr = QString::number(mYear);
    QString doy = QString::number(row+1);
    Pair pair(yr, doy);
    
    // Find item in weather map with key
    Hash::iterator iter = hash->find(pair);
    QVector<QString>* values = iter.value();
    
    if (index.isValid() && role == Qt::EditRole)
    {
        (*values)[column-2] = value.toString();
        emit dataChanged(index, index);
        return true;
    }
    
    return false;
}

