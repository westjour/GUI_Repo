//
//  CSoilLayerModel.h
//  XMLEditor
//
//  Created by Jourdan West on 11/14/14.
//
//

#ifndef __XMLEditor__CSoilLayerModel__
#define __XMLEditor__CSoilLayerModel__

#include <QAbstractTableModel>

class CSoil;

/* Brief:
 */
class CSoilLayerModel : public QAbstractTableModel
{
    Q_OBJECT
    
public:
    enum COL_HEADERS {
        YEAR=0, DOY, SRAD, TMAX, TMIN, RAIN,
        DEWP, WIND, PAR, numColHeaders
    };
    
    explicit CSoilLayerModel(QObject *parent = 0);
    void update();
    void setSoils(QVector<CSoil* >* soils){ mSoils = soils; }
    CSoil* findSoil(QString id);
    
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
    QVector<CSoil* >* mSoils;
    
    // Soil selected in the "Choose Soil" dropdown box
    CSoil* mSoil;
    
signals:
    
    public slots:
    
};

#endif /* defined(__XMLEditor__CSoilLayerModel__) */
