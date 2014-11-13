//
//  CSoilsModel.h
//  XMLEditor
//
//  Created by Jourdan West on 11/10/14.
//
//

#ifndef __XMLEditor__CSoilsModel__
#define __XMLEditor__CSoilsModel__

#include <QAbstractTableModel>

class CSoil;

/* Brief:
 */
class CSoilsModel : public QAbstractTableModel
{
    Q_OBJECT
    
public:
    enum COL_HEADERS {
        SLDESC=0, SLSOUR, SLTX, SLDP, SSITE, SCOUNT, SLAT, SLONG, TACON,
        SCOM, SALB, U, SWCON, CN2, SLNF, SLPF, SMHB, SMPX, SMKE, PONDMAX,
        numColHeaders
    };
    
    //
    // The following functions are required for an editable table
    //
    int rowCount ( const QModelIndex & parent = QModelIndex() ) const;
    int columnCount( const QModelIndex & parent = QModelIndex() ) const;
    QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const;
    Qt::ItemFlags flags ( const QModelIndex & index ) const;
    QVariant headerData ( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;
    bool setData( const QModelIndex & index, const QVariant & value, int role = Qt::EditRole );
    
    
private:
    void update();
    QVector<CSoil* >* mSoils;

signals:
    
public slots:
    
};

#endif /* defined(__XMLEditor__CSoilsModel__) */
