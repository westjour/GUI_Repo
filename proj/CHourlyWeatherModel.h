//
//  CHourlyWeatherModel.h
//  XMLEditor
//
//  Created by Jourdan West on 10/20/14.
//
//

#ifndef __XMLEditor__CHourlyWeatherModel__
#define __XMLEditor__CHourlyWeatherModel__

#include <QAbstractTableModel>

/* Brief:
 */
class CHourlyWeatherModel : public QAbstractTableModel
{
    Q_OBJECT
    
public:
    enum COL_HEADERS {
        YEAR=0, DOY, HR, HR_PRECIP, numColHeaders
    };
    
    explicit CHourlyWeatherModel(QObject *parent = 0);

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
    
signals:
    
public slots:
    
};



#endif /* defined(__XMLEditor__CHourlyWeatherModel__) */
