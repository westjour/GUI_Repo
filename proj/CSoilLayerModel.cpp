//
//  CSoilLayerModel.cpp
//  XMLEditor
//
//  Created by Jourdan West on 11/14/14.
//
//

#include "CSoilLayerModel.h"
#include "CSoil.h"

CSoilLayerModel::CSoilLayerModel(QObject *parent) :QAbstractTableModel(parent)
{
    mSoil = NULL;
}



/* Brief: Find soil with matching SoilID
 * Param: id, SoilID to search for
 */
CSoil* CSoilLayerModel::findSoil(QString id)
{
    // Find corresponding station
    QVector<CSoil* >::const_iterator iter;
    for (iter = mSoils->begin(); iter != mSoils->end(); ++iter)
    {
        CSoil* currSoil = *iter;
        QString sID = currSoil->getSoilAttrs()->value("SoilID");
        
        if(id == sID)
            return currSoil;
    }
    
    return NULL;
}


/* Brief: TODO description
 * Parameter: parent, TODO description
 *
 * Note: When implementing a table based model, rowCount() should return 0 when the parent is valid.
 */
int CSoilLayerModel::rowCount( const QModelIndex & parent ) const
{
    if (parent.isValid())
        return 0;
    
    if(mSoil != NULL)
        return mSoil->getLayers().size();
}


/* Brief: Force the model to update
 */
void CSoilLayerModel::update()
{
    beginResetModel();
    endResetModel();
}


/* Brief: TODO description
 * Parameter: parent, TODO description
 *
 * Note: When implementing a table based model, columnCount() should return 0 when the parent is valid.
 */
int CSoilLayerModel::columnCount( const QModelIndex & parent ) const
{
    if (parent.isValid())
        return 0;
    return CSoilLayerModel::numColHeaders;
}


/* Brief: TODO description
 * Parameter: index, TODO description
 * Parameter: role, TODO description
 *
 * Note: This function is called
 */
QVariant CSoilLayerModel::data( const QModelIndex & index, int role ) const
{
    int column = index.column();
    int row = index.row();
    
    //qDebug("from inside Data(), row:%i, col:%i, role=%i, counter=%i", row, column, role, counter);
    
    if (role == Qt::DisplayRole || role == Qt::EditRole)
    {
        /*if (mStation == NULL)
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
         }*/
    }
    
    else if (role == Qt::TextAlignmentRole)
        return QVariant(Qt::AlignCenter);
    else
        return QVariant();
}


/* Brief: TODO description
 * Parameter: index, TODO description
 */
Qt::ItemFlags CSoilLayerModel::flags( const QModelIndex & index ) const
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
QVariant CSoilLayerModel::headerData( int section, Qt::Orientation orientation, int role ) const
{
    if (role == Qt::DisplayRole)
    {
        // Place label on horizontal header sections
        if (orientation == Qt::Horizontal)
        {
            
            switch(section) {
                case CSoilLayerModel::YEAR:
                    return QVariant("MH");
                case CSoilLayerModel::DOY:
                    return QVariant("DOY");
                case CSoilLayerModel::SRAD:
                    return QVariant("SRAD");
                case CSoilLayerModel::TMAX:
                    return QVariant("Tmax");
                case CSoilLayerModel::TMIN:
                    return QVariant("Tmin");
                case CSoilLayerModel::RAIN:
                    return QVariant("Rain");
                case CSoilLayerModel::DEWP:
                    return QVariant("DewP");
                case CSoilLayerModel::WIND:
                    return QVariant("Wind");
                case CSoilLayerModel::PAR:
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
bool CSoilLayerModel::setData( const QModelIndex & index, const QVariant & value, int role )
{
    int column = index.column();
    int row = index.row();
    
    /*Hash* hash = mStation->getWeather();
     
     QString yr = QString::number(mYear);
     QString doy = QString::number(row+1);
     Pair pair(yr, doy);
     
     // Find item in weather map with key
     Hash::iterator iter = hash->find(pair);
     QVector<QString>* values = iter.value();*/
    
    if (index.isValid() && role == Qt::EditRole)
    {
        //(*values)[column-2] = value.toString();
        emit dataChanged(index, index);
        return true;
    }
    
    return false;
}


