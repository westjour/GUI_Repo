#ifndef CDAILYWEATHERMODEL_H
#define CDAILYWEATHERMODEL_H

#include <QAbstractTableModel>

class CStation;

/* Brief:
 */
class CDailyWeatherModel : public QAbstractTableModel
{
    Q_OBJECT
    
public:
    enum COL_HEADERS {
        YEAR=0, DOY, SRAD, TMAX, TMIN, RAIN,
        DEWP, WIND, PAR, numColHeaders
    };
    
    explicit CDailyWeatherModel(QObject *parent = 0);
    void setStations(QVector<CStation* > st){ mStations = st; }
    void setYear(int y){ mYear = y; }
    int getYear(){ return mYear; }
    
    //
    // The following functions are required for an editable table
    //
    int	rowCount ( const QModelIndex & parent = QModelIndex() ) const;
    int columnCount( const QModelIndex & parent = QModelIndex() ) const;
    QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const;
    Qt::ItemFlags flags ( const QModelIndex & index ) const;
    QVariant headerData ( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;
    bool setData( const QModelIndex & index, const QVariant & value, int role = Qt::EditRole );

    
private:
        QVector<CStation* > mStations;
    
        // Current year being shown in the Weather Year combobox
        unsigned mYear;

signals:

public slots:

};

#endif // CDAILYWEATHERMODEL_H
