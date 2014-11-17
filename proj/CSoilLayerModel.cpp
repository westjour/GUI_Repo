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
    // Find corresponding soil
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
    
    if(mSoil != NULL) {
        return mSoil->getLayers()->size();
    }
    else
        return 0;
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
    
    if (role == Qt::DisplayRole || role == Qt::EditRole)
    {
        if (mSoil == NULL)
            return QVariant("n/a");
        
        // Valid soil selected
        else {
            QVector<Layer*>* layers = mSoil->getLayers();
            Layer* layer = layers->at(row);
            QString key;
            
            switch(column) {
                case CSoilLayerModel::MH:
                    key = "MH"; break;
                case CSoilLayerModel::ZLYR:
                    key = "ZLYR"; break;
                case CSoilLayerModel::LL:
                    key = "LL"; break;
                case CSoilLayerModel::DUL:
                    key = "DUL"; break;
                case CSoilLayerModel::SAT:
                    key = "SAT"; break;
                case CSoilLayerModel::SHF:
                    key = "SHF"; break;
                case CSoilLayerModel::SWCN:
                    key = "SWCN"; break;
                case CSoilLayerModel::BD:
                    key = "BD"; break;
                case CSoilLayerModel::OC:
                    key = "OC"; break;
                case CSoilLayerModel::Clay:
                    key = "Clay"; break;
                case CSoilLayerModel::Silt:
                    key = "Silt"; break;
                case CSoilLayerModel::Stones:
                    key = "Stones"; break;
                case CSoilLayerModel::TotN:
                    key = "TotN"; break;
                case CSoilLayerModel::pH:
                    key = "pH"; break;
                case CSoilLayerModel::pHKcl:
                    key = "pHKcl"; break;
                case CSoilLayerModel::CEC:
                    key = "CEC"; break;
                case CSoilLayerModel::CaCo:
                    key = "CaCo"; break;
                case CSoilLayerModel::KsMtrx:
                    key = "KsMtrx"; break;
                case CSoilLayerModel::SBioDepF:
                    key = "SBioDepF"; break;
                case CSoilLayerModel::TotP:
                    key = "TotP"; break;
                case CSoilLayerModel::P_ActIno:
                    key = "P_ActIno"; break;
                case CSoilLayerModel::P_SloIno:
                    key = "P_SloIno"; break;
                case CSoilLayerModel::P_Labile:
                    key = "P_Labile"; break;
            }

            // Find item in weather map with key
            Layer::const_iterator iter = layer->find(key);
            
            if(iter == layer->end())
                return QVariant("n/a");
            
            return QVariant(iter.value());
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
                case CSoilLayerModel::MH:
                    return QVariant("MH");
                case CSoilLayerModel::ZLYR:
                    return QVariant("ZLYR");
                case CSoilLayerModel::LL:
                    return QVariant("LL");
                case CSoilLayerModel::DUL:
                    return QVariant("DUL");
                case CSoilLayerModel::SAT:
                    return QVariant("SAT");
                case CSoilLayerModel::SHF:
                    return QVariant("SHF");
                case CSoilLayerModel::SWCN:
                    return QVariant("SWCN");
                case CSoilLayerModel::BD:
                    return QVariant("BD");
                case CSoilLayerModel::OC:
                    return QVariant("OC");
                case CSoilLayerModel::Clay:
                    return QVariant("Clay");
                case CSoilLayerModel::Silt:
                    return QVariant("Silt");
                case CSoilLayerModel::Stones:
                    return QVariant("Stones");
                case CSoilLayerModel::TotN:
                    return QVariant("TotN");
                case CSoilLayerModel::pH:
                    return QVariant("pH");
                case CSoilLayerModel::pHKcl:
                    return QVariant("pHKcl");
                case CSoilLayerModel::CEC:
                    return QVariant("CEC");
                case CSoilLayerModel::CaCo:
                    return QVariant("CaCo");
                case CSoilLayerModel::KsMtrx:
                    return QVariant("KsMtrx");
                case CSoilLayerModel::SBioDepF:
                    return QVariant("SBioDepF");
                case CSoilLayerModel::TotP:
                    return QVariant("TotP");
                case CSoilLayerModel::P_ActIno:
                    return QVariant("P_ActIno");
                case CSoilLayerModel::P_SloIno:
                    return QVariant("P_SloIno");
                case CSoilLayerModel::P_Labile:
                    return QVariant("P_Labile");
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
    
    QVector<Layer*>* layers = mSoil->getLayers();
    Layer* layer = layers->at(row);
    
    QString key;
    switch(column) {
        case CSoilLayerModel::MH:
            key = "MH"; break;
        case CSoilLayerModel::ZLYR:
            key = "ZLYR"; break;
        case CSoilLayerModel::LL:
            key = "LL"; break;
        case CSoilLayerModel::DUL:
            key = "DUL"; break;
        case CSoilLayerModel::SAT:
            key = "SAT"; break;
        case CSoilLayerModel::SHF:
            key = "SHF"; break;
        case CSoilLayerModel::SWCN:
            key = "SWCN"; break;
        case CSoilLayerModel::BD:
            key = "BD"; break;
        case CSoilLayerModel::OC:
            key = "OC"; break;
        case CSoilLayerModel::Clay:
            key = "Clay"; break;
        case CSoilLayerModel::Silt:
            key = "Silt"; break;
        case CSoilLayerModel::Stones:
            key = "Stones"; break;
        case CSoilLayerModel::TotN:
            key = "TotN"; break;
        case CSoilLayerModel::pH:
            key = "pH"; break;
        case CSoilLayerModel::pHKcl:
            key = "pHKcl"; break;
        case CSoilLayerModel::CEC:
            key = "CEC"; break;
        case CSoilLayerModel::CaCo:
            key = "CaCo"; break;
        case CSoilLayerModel::KsMtrx:
            key = "KsMtrx"; break;
        case CSoilLayerModel::SBioDepF:
            key = "SBioDepF"; break;
        case CSoilLayerModel::TotP:
            key = "TotP"; break;
        case CSoilLayerModel::P_ActIno:
            key = "P_ActIno"; break;
        case CSoilLayerModel::P_SloIno:
            key = "P_SloIno"; break;
        case CSoilLayerModel::P_Labile:
            key = "P_Labile"; break;
    }

    // Find item in Layer map with this key
     Layer::iterator iter = layer->find(key);
    
    if (index.isValid() && role == Qt::EditRole)
    {
        *iter = value.toString();
        emit dataChanged(index, index);
        return true;
    }
    
    return false;
}


