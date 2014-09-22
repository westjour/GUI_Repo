#include<iostream>

#include <map>
#include <vector>

#include <QFile>
#include <QStringList>
#include <QDomNode>
#include <QDomDocument>
#include <QDomAttr>

#include "CXMLParser.h"
#include "CStation.h"

int UNICODE_NEWLINE = 10;
int UNICODE_CARRIAGERETURN = 13;
int UNICODE_COMMA = 44;

CXMLParser::CXMLParser() {}


/*
 * Brief: Parses WDB xml file
 * Parameter: stations
 */
void CXMLParser::parseWDB(QVector<CStation*>* stations)
{
    QFile file("/Users/westjour/Desktop/GUI_Repo/xml/SALUS_GY_USAM_RCP_60_03042014.wdb.xml");
    QDomDocument doc = QDomDocument();


    if (!file.open(QIODevice::ReadOnly))
         return;
    if (!doc.setContent(&file))
    {
         file.close();
         return;
    }
    file.close();

    // name of the current XML tag
    QString tagName;

    // This map will contain name, value pairs for <Stations> attributes
    std::map<QString, QString> stationAttrMap;

    // Attributes of <Weather>. To be used as columns in GUI
    QStringList weatherColumns;

    QDomElement root = doc.documentElement();
    QDomNode n = root.firstChildElement();
    qDebug("Element name:%s", root.tagName().toUtf8().constData());

    while(!n.isNull())
    {
        if (n.isElement())
        {
            QDomElement e = n.toElement();
            if (e.tagName() == "Stations" and e.hasChildNodes())
            {
                CStation* station = new CStation();
                
              //  CStation::HourlyRainfall* hr = station->getHourlyRainFall();
               
                //
                // Parse station attributes
                //
                QDomNamedNodeMap map = e.attributes();
                for(int j=0; j<map.count(); j++)
                {
                    QDomNode s = map.item(j);
                    if (s.nodeType() == QDomNode::AttributeNode)
                    {
                        QDomAttr attrNode = s.toAttr();
                        QString name = attrNode.name();
                        QString value = attrNode.value();

                        // Add attribute to the station's attribute map
                        station->getAttributes().insert(std::pair<QString, QString>(name, value));
                    }
                }


                //
                // Parse <Stations> child elements
                //
                for(int i=0; i<e.childNodes().length(); i++)
                {
                    QDomNode childNode = e.childNodes().at(i);
                    QDomElement childElem = childNode.toElement();

                    if(childElem.tagName() == "Storm_Intensity")
                        continue;
                    if(childElem.tagName() == "Hourly_Rainfall")
                        continue;
                    if(childElem.tagName() == "Weather")
                    {
                        //
                        // Parse station attributes
                        //
                        QDomNamedNodeMap map = childNode.attributes();
                        for(int j=0; j<map.count(); j++)
                        {
                            QDomNode s = map.item(j);
                            if (s.nodeType() == QDomNode::AttributeNode)
                            {
                                QDomAttr attrNode = s.toAttr();
                                QString name = attrNode.name();
                                QString value = attrNode.value();

                                // Add attribute to the weather's attribute map
                                // TODO - the following line causes an error.
                                //station->mDailyWeather->getAttributes().insert(std::pair<QString, QString>(name, value));
                            }
                        }

                        // Parse Weather Data
                        parseWeatherData(station, childElem.text());
                        
                    }
                }

                stations->push_back(station);
            } // end if, we have parsed <Stations> and its children

            n = n.nextSiblingElement();
        } // end "if element"
    } // end while, done parsing XML
}


/* Brief: Parse weather data section
 * Parameter: station, the station that the weather data belongs to
 * Parameter: s, string to parse
 *
 * Note: "s" is a string containing all text in the entire weather data section
 */
void CXMLParser::parseWeatherData( CStation* station, QString s )
{
    // Allocate space for an array with a manually added null-terminating char
    char a[s.length()+1];

    // Copy chars from source char array to dest char array
    strncpy(a, s.toUtf8().constData(), sizeof(a));

    // Append null-terminating character
    a[sizeof(a) - 1] = '\0';


    //
    // Parse characters
    //

    // Keeps track of where we are on a line of CSV
    int j = 0;

    // String representing a value on the line of CSV
    QString str = QString();

    CStation::WeatherDay* day = new CStation::WeatherDay();

    for(unsigned i=0; i<=sizeof(a)-1; i++)
    {
        //
        // Build strings from char array
        //

        QChar ch = a[i];
        
        // Ignore carriage return
        if (ch.unicode() == UNICODE_CARRIAGERETURN)
            continue;

        else
        {
            // Char is a newline at the front of the line, ignore it
            if (ch.unicode() == UNICODE_NEWLINE && j==0)
                continue;

            // Char is a newline at the end of the line, start new Weather day
            else if (ch.unicode() == UNICODE_NEWLINE && j!=0)
            {
                // When we reach a new line, there is still a value (from the previous
                // line) that has not been added to the list of values yet. So,
                // we do it now.
                day->values.push_back(str);

                // Add the day to the Station's Daily Weather
                station->getDailyWeather()->mWeather.push_back(day);
                
                // Create a new weather day since we are going to a new line
                day = new CStation::WeatherDay();

                // Reset j since we are going to a new line
                j = 0;
                
                // clear string
                str = QString();
                
                // Go to next char in Weather data
                continue;
            }

            // This is a comma, so start a new value
            else if (ch.unicode() == UNICODE_COMMA)
            {
                day->values.push_back(str);

                // clear string
                str = QString();
            }

            // Keep building the string
            else
                str.append(ch);
        }

        j++;
    }
}


/* Brief: Parses a XDB XML file
 */
void CXMLParser::parseXDB(/*QFile* file*/){}


/* Brief: Parses a SDB XML file
 */
void CXMLParser::parseSDB(/*QFile* file*/){}


/* Brief: Parses a CDB XML file
 */
void CXMLParser::parseCDB(/*QFile* file*/){}
