#ifndef CXMLPARSER_H
#define CXMLPARSER_H

#include <vector>

class CStation;

/* Brief: This class handles the parsing of all XML files */
class CXMLParser
{
public:
    CXMLParser();

    void parseXDB(/*QFile* file*/);
    void parseSDB(/*QFile* file*/);
    void parseWDB(QVector<CStation*>* stations);
    void parseCDB(/*QFile* file*/);

    void parseWeatherData(CStation*, QString s);
    void printThis(QMap<QPair<QString, QString>, QVector<QString>* > w);

};

#endif // CXMLPARSER_H
