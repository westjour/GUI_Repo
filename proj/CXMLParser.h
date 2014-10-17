#ifndef CXMLPARSER_H
#define CXMLPARSER_H

class CStation;
typedef QVector<CStation* > Stations;


/* Brief: This class handles the parsing of all XML files */
class CXMLParser
{
public:
    CXMLParser();

    Stations* parseXDB(/*QFile* file*/);
    Stations* parseSDB(/*QFile* file*/);
    Stations* parseWDB();
    Stations* parseCDB(/*QFile* file*/);

    void parseWeatherData(CStation*, QString s);
};

#endif // CXMLPARSER_H
