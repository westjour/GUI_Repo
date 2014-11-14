#ifndef CXMLPARSER_H
#define CXMLPARSER_H

class CStation;
class CSoil;
typedef QVector<CStation* > Stations;
typedef QVector<CSoil* > Soils;
typedef QMap<QString, QString> Layer;


/* Brief: This class handles the parsing of all XML files */
class CXMLParser
{
public:
    CXMLParser();

    Soils* parseSDB();
    Stations* parseWDB();
    void* parseXDB();
    void* parseCDB();

    void parseWeatherData(CStation*, QString s);
};

#endif // CXMLPARSER_H
