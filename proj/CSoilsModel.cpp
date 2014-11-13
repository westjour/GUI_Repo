//
//  CSoilsModel.cpp
//  XMLEditor
//
//  Created by Jourdan West on 11/10/14.
//
//

#include "CSoilsModel.h"

/* Brief: TODO description
 * Parameter: parent, TODO description
 *
 * Note: When implementing a table based model, rowCount() should return 0 when the parent is valid.
 */
int CSoilsModel::rowCount( const QModelIndex & parent ) const
{
    if (parent.isValid())
        return 0;
    return 15;
}


/* Brief: Force the model to update
 */
void CSoilsModel::update()
{
    beginResetModel();
    endResetModel();
}


/* Brief: TODO description
 * Parameter: parent, TODO description
 *
 * Note: When implementing a table based model, columnCount() should return 0 when the parent is valid.
 */
int CSoilsModel::columnCount( const QModelIndex & parent ) const
{
    if (parent.isValid())
        return 0;
    return CSoilsModel::numColHeaders;
}


/* Brief: TODO description
 * Parameter: index, TODO description
 * Parameter: role, TODO description
 *
 * Note: This function is called
 */
QVariant CSoilsModel::data( const QModelIndex & index, int role ) const
{
    //int column = index.column();
    //int row = index.row();
    
    //qDebug("from inside Data(), row:%i, col:%i, role=%i, counter=%i", row, column, role, counter);
    
    if (role == Qt::DisplayRole || role == Qt::EditRole)
    {
    }
    
    else if (role == Qt::TextAlignmentRole)
        return QVariant(Qt::AlignCenter);
    else
        return QVariant();
}


/* Brief: TODO description
 * Parameter: index, TODO description
 */
Qt::ItemFlags CSoilsModel::flags( const QModelIndex & index ) const
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
QVariant CSoilsModel::headerData( int section, Qt::Orientation orientation, int role ) const
{
    if (role == Qt::DisplayRole)
    {
        // Place label on horizontal header sections
        if (orientation == Qt::Horizontal)
        {
            switch(section) {
                case CSoilsModel::SLDESC:
                    return QVariant("SlDesc");
                case CSoilsModel::SLSOUR:
                    return QVariant("Slsour");
                case CSoilsModel::SLTX:
                    return QVariant("Sltx");
                case CSoilsModel::SLDP:
                    return QVariant("Sldp");
                case CSoilsModel::SSITE:
                    return QVariant("SSite");
                case CSoilsModel::SCOUNT:
                    return QVariant("SCount");
                case CSoilsModel::SLAT:
                    return QVariant("SLat");
                case CSoilsModel::SLONG:
                    return QVariant("SLong");
                case CSoilsModel::TACON:
                    return QVariant("Tacon");
                case CSoilsModel::SCOM:
                    return QVariant("Scom");
                case CSoilsModel::SALB:
                    return QVariant("Salb");
                case CSoilsModel::U:
                    return QVariant("U");
                case CSoilsModel::SWCON:
                    return QVariant("SWCON");
                case CSoilsModel::CN2:
                    return QVariant("CN2");
                case CSoilsModel::SLNF:
                    return QVariant("Slnf");
                case CSoilsModel::SLPF:
                    return QVariant("Slpf");
                case CSoilsModel::SMHB:
                    return QVariant("Smhb");
                case CSoilsModel::SMPX:
                    return QVariant("Smpx");
                case CSoilsModel::SMKE:
                    return QVariant("Smke");
                case CSoilsModel::PONDMAX:
                    return QVariant("PondMax");
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
bool CSoilsModel::setData( const QModelIndex & index, const QVariant & value, int role )
{
    if (index.isValid() && role == Qt::EditRole) {
        emit dataChanged(index, index);
        return true;
    }
    
    return false;
}

