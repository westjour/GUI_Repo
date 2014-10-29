#ifndef CDAILYWEATHERMODEL_H
#define CDAILYWEATHERMODEL_H

#include <QAbstractTableModel>

typedef QPair<QString, QString> Pair;
typedef QHash<Pair, QVector<QString>* > Hash;

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
    QVector<CStation* >* getStations(){return mStations;}
    void setStations(QVector<CStation* >* st){ mStations = st; }
    void setStation(CStation* station) {mStation=station;}
    void setYear(int y){ mYear = y; }
    int getYear(){ return mYear; }
    void update();
    CStation* findStation(QString statId, QString statName);
    
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
        QVector<CStation* >* mStations;
    
        // Station currently being shown in the Daily Weather table
        CStation* mStation;
    
        // Current year being shown in the Weather Year combobox
        unsigned mYear;

signals:

public slots:

};

#endif // CDAILYWEATHERMODEL_H
