#ifndef CXMLPARSER_H
#define CXMLPARSER_H

#include <QDomNamedNodeMap>
#include <QMap>

class CStation;
class CSoil;
typedef QVector<CStation* > Stations;
typedef QVector<CSoil* > Soils;
typedef QMap<QString, QString> Layer;

/* Map where key=identifier(Soil, Layer, Station, etc.) and value is another map where key=attribute name
 * and value=attribute value */
typedef QMap<QString, QDomNamedNodeMap > AttrTemplate;

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
    
    AttrTemplate* parseTemplateWDB();
    void parseTemplateSDB();
};

#endif // CXMLPARSER_H
