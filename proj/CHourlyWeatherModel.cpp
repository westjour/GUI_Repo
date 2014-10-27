//
//  CHourlyWeatherModel.cpp
//  XMLEditor
//
//  Created by Jourdan West on 10/20/14.
//
//

#include "CHourlyWeatherModel.h"

/*CHourlyWeatherModel::CHourlyWeatherModel(QObject *parent) :
QAbstractTableModel(parent)
{
}*/


/* Brief: TODO description
 * Parameter: parent, TODO description
 *
 * Note: When implementing a table based model, rowCount() should return 0 when the parent is valid.
 */
int CHourlyWeatherModel::rowCount( const QModelIndex & parent ) const
{
    if (parent.isValid())
        return 0;
    return 1;
}


/* Brief: TODO description
 * Parameter: parent, TODO description
 *
 * Note: When implementing a table based model, columnCount() should return 0 when the parent is valid.
 */
int CHourlyWeatherModel::columnCount( const QModelIndex & parent ) const
{
    if (parent.isValid())
        return 0;
    return 1;
}


/* Brief: TODO description
 * Parameter: index, TODO description
 * Parameter: role, TODO description
 *
 * Note: This function is called
 */
QVariant CHourlyWeatherModel::data( const QModelIndex & index, int role ) const
{
    int column = index.column();
    int row = index.row();
    
    //qDebug("from inside Data(), row:%i, col:%i, role=%i, counter=%i", row, column, role, counter);
    
    if (role == Qt::DisplayRole || role == Qt::EditRole)
        return QVariant("X");
    
    else if (role == Qt::TextAlignmentRole)
        return QVariant(Qt::AlignCenter);
    else
        return QVariant();
}


/* Brief: TODO description
 * Parameter: index, TODO description
 */
Qt::ItemFlags CHourlyWeatherModel::flags( const QModelIndex & index ) const
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
QVariant CHourlyWeatherModel::headerData( int section, Qt::Orientation orientation, int role ) const
{
    /*counter++;
     qDebug("from inside headerData(), role=%i, counter=%i", role, counter);*/
    
    if (role == Qt::DisplayRole)
    {
        // Place label on horizontal header sections
        if (orientation == Qt::Horizontal)
        {
            if (section == CHourlyWeatherModel::YEAR)
                return QVariant("Year");
            else if (section == CHourlyWeatherModel::DOY)
                return QVariant("DOY");
            else if (section == CHourlyWeatherModel::HR)
                return QVariant("Hr");
            else if (section == CHourlyWeatherModel::HR_PRECIP)
                return QVariant("HrPrecip");
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
bool CHourlyWeatherModel::setData( const QModelIndex & index, const QVariant & value, int role )
{
    if (index.isValid() && role == Qt::EditRole)
    {
        emit dataChanged(index, index);
        return true;
    }
    else
        return false;
}

