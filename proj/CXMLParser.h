#ifndef CXMLPARSER_H
#define CXMLPARSER_H

class CStation;
class CSoil;
typedef QVector<CStation* > Stations;
typedef QVector<CSoil* > Soils;
typedef QMap<QString, QString> Layer;
typedef QMap<QString, QString> AttrMap;
//typedef QMap<QString, QMap> Template

// Defines a key in the weather map. The first element is year and second is DOY
typedef QPair<QString, QString> Pair;

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
    
    AttrMap* parseTemplateWDB();
    void parseTemplateSDB();
};

#endif // CXMLPARSER_H
