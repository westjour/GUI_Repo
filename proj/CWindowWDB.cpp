#include <QGridLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QFormLayout>
#include <QComboBox>
#include <QLineEdit>
#include <QGroupBox>
#include <QFile>
#include <QXmlStreamWriter>
#include <QSignalMapper>
#include <QFileDialog>

#include "CWindowWDB.h"
#include "ui_wdb.h"
#include "CXMLParser.h"
#include "CStation.h"
#include "CDailyWeatherModel.h"

CWindowWDB::CWindowWDB(QWidget *parent, QString filename) : QMainWindow(parent), ui(new Ui::WDB) {
    ui->setupUi(this);
    //setFixedSize(1000,1000);
    
    mFilename = filename;
    
    // Parse WDB XML
    CXMLParser parser;
    QVector<CStation* >* stations = parser.parseWDB();
    
    // Set model onto view
    CDailyWeatherModel* weatherModel = new CDailyWeatherModel();
    weatherModel->setStations(stations);
    ui->mDailyWeatherView->setModel(weatherModel);

  
    //
    // Construct strings for Station combobox
    //
    QVector<CStation* >::const_iterator it = stations->begin();
    QStringList options = QStringList("None");
    for (; it!=stations->end(); ++it )
    {
        CStation* station = *it;
        AttrMap* attrs = station->getStatAttrs();
        QString s = attrs->value("StationID") + '-' + attrs->value("Station_Name");
        options.append(s);
    }

    ui->mStationCombobox->setFixedSize(200, 30);
    ui->mStationCombobox->addItems(options);
  
   
    // Create menus based on the operating system
    #ifdef Q_OS_MAC
    buildMacMenuBar();
    #endif
    
    #ifndef Q_OS_MAC
    buildMenuBar();
    #endif
    
    makeConnections();
}


/* Brief: Build menu bar for any OS other than MAC
 */
void CWindowWDB::buildMenuBar()
{
}


/* Brief: Build menu bar for MAC OS
 */
void CWindowWDB::buildMacMenuBar()
{
    macMenuBar = new QMenuBar(0);
    QMenu* fileMenu = macMenuBar->addMenu("File");
    
    mFileSave = new QAction("Save", this);
    mFileExit = new QAction("Exit", this);
    mFileOpen = new QAction("Open", this);
    
    mFileSave->setMenuRole(QAction::NoRole);
    mFileExit->setMenuRole(QAction::NoRole);
    mFileOpen->setMenuRole(QAction::NoRole);

    fileMenu->addAction(mFileSave);
    fileMenu->addAction(mFileOpen);
    fileMenu->addAction(mFileExit);
    
    
    macMenuBar->addMenu(fileMenu);
    setMenuBar(macMenuBar);
}


/* Brief:
 */
CWindowWDB::~CWindowWDB()
{
    delete ui;
}


/* Brief:
 */
void CWindowWDB::makeConnections()
{
    connect(ui->mStationCombobox, SIGNAL(currentIndexChanged(QString)), this, SLOT(stationIndexChanged(QString)));
    connect(ui->mYearCombobox, SIGNAL(currentIndexChanged(QString)), this, SLOT(yearIndexChanged(QString)));
    
    connect(mFileSave, SIGNAL(triggered (bool)), this, SLOT(onFileSave()));
    connect(mFileOpen, SIGNAL(triggered (bool)), this, SLOT(onFileOpen()));
    connect(mFileExit, SIGNAL(triggered (bool)), this, SLOT(close()));
    
    
    //
    // Set up signal mapping for Station Data line edits
    //
    QSignalMapper *signalMapper = new QSignalMapper(this);
    
    connect(ui->mStatNameLineEdit, SIGNAL(textChanged(QString)), signalMapper, SLOT(map()));
    connect(ui->mPlaceNameLineEdit, SIGNAL(textChanged(QString)), signalMapper, SLOT(map()));
    connect(ui->mLatLineEdit, SIGNAL(textChanged(QString)), signalMapper, SLOT(map()));
    connect(ui->mLongLineEdit, SIGNAL(textChanged(QString)), signalMapper, SLOT(map()));
    connect(ui->mElevLineEdit, SIGNAL(textChanged(QString)), signalMapper, SLOT(map()));
    connect(ui->mTavLineEdit, SIGNAL(textChanged(QString)), signalMapper, SLOT(map()));
    connect(ui->mAmpLineEdit, SIGNAL(textChanged(QString)), signalMapper, SLOT(map()));
    connect(ui->mTmhtLineEdit, SIGNAL(textChanged(QString)), signalMapper, SLOT(map()));
    connect(ui->mWmhtLineEdit, SIGNAL(textChanged(QString)), signalMapper, SLOT(map()));

    signalMapper->setMapping(ui->mStatNameLineEdit, ("Station_Name"));
    signalMapper->setMapping(ui->mStatIDLineEdit, ("StationID"));
    signalMapper->setMapping(ui->mPlaceNameLineEdit, ("Place_Name"));
    signalMapper->setMapping(ui->mLatLineEdit, ("Lat"));
    signalMapper->setMapping(ui->mLongLineEdit, ("Long"));
    signalMapper->setMapping(ui->mElevLineEdit, ("Elev"));
    signalMapper->setMapping(ui->mTavLineEdit, ("Tav"));
    signalMapper->setMapping(ui->mAmpLineEdit, ("Amp"));
    signalMapper->setMapping(ui->mTmhtLineEdit, ("Tmht"));
    signalMapper->setMapping(ui->mWmhtLineEdit, ("Wmht"));
    
    connect(signalMapper, SIGNAL(mapped(QString)), this, SLOT(onStationDataChanged(QString)));
}


/* Brief: Slot called when the Weather Year combobox is changed
 * Param: text, text that the 'Year' combobox contains after it is changed
 */
void CWindowWDB::yearIndexChanged(QString text)
{
    CDailyWeatherModel* model = (CDailyWeatherModel*)ui->mDailyWeatherView->model();
    model->setYear(text.toInt());
    model->update();
}


/* Brief: Automatically called when a station line edit text is changed
 * Param: field, field that was modified (i.e. Tmht, Wmht, etc.)
 */
void CWindowWDB::onStationDataChanged(QString field)
{
    // Find the current station
    CDailyWeatherModel* model = (CDailyWeatherModel*)ui->mDailyWeatherView->model();
    
    QString text = ui->mStationCombobox->currentText();
    CStation* station = NULL;
    QString id, name;
    
    if( text.split("-").length() >= 2 ) {
        id = text.split("-")[0];
        name = text.split("-")[1];
        station = model->findStation(id, name);
    }

    if (station != NULL) {
        //
        // TODO modify 'field' so that it can be used as key into Station AttrMap
        //
        AttrMap* attrs = station->getStatAttrs();
        
        // This is the line edit to read text from after an edit. This depends on the field that
        // was modified.
        QLineEdit* lineEdit = NULL;
        
        if(field == "Wmht") { lineEdit = ui->mWmhtLineEdit ;}
        else if(field == "Tmht") { lineEdit = ui->mTmhtLineEdit ;}
        else if(field == "Station_Name") { lineEdit = ui->mStatNameLineEdit ;}
        else if(field == "StationID") { lineEdit = ui->mStatIDLineEdit ;}
        else if(field == "Place_Name") { lineEdit = ui->mPlaceNameLineEdit ;}
        else if(field == "Lat") { lineEdit = ui->mLatLineEdit ;}
        else if(field == "Long") { lineEdit = ui->mLongLineEdit ;}
        else if(field == "Elev") { lineEdit = ui->mElevLineEdit ;}
        else if(field == "Tav") { lineEdit = ui->mTavLineEdit ;}
        else if(field == "Amp") { lineEdit = ui->mAmpLineEdit ;}
        
        // Update Station Attr
        (*attrs)[field] = lineEdit->text();
    }
}


/* Brief: Disable the station line edits for editing
 */
void CWindowWDB::disableLineEdits()
{
    ui->mStatNameLineEdit->setEnabled(false);
    ui->mStatNameLineEdit->setEnabled(false);
    ui->mStatIDLineEdit->setEnabled(false);
    ui->mPlaceNameLineEdit->setEnabled(false);
    ui->mLatLineEdit->setEnabled(false);
    ui->mLongLineEdit->setEnabled(false);
    ui->mElevLineEdit->setEnabled(false);
    ui->mTavLineEdit->setEnabled(false);
    ui->mAmpLineEdit->setEnabled(false);
    ui->mTmhtLineEdit->setEnabled(false);
    ui->mWmhtLineEdit->setEnabled(false);
}


/* Brief: Enable the station line edits for editing
 */
void CWindowWDB::enableLineEdits()
{
    ui->mStatNameLineEdit->setEnabled(true);
    ui->mStatNameLineEdit->setEnabled(true);
    ui->mStatIDLineEdit->setEnabled(true);
    ui->mPlaceNameLineEdit->setEnabled(true);
    ui->mLatLineEdit->setEnabled(true);
    ui->mLongLineEdit->setEnabled(true);
    ui->mElevLineEdit->setEnabled(true);
    ui->mTavLineEdit->setEnabled(true);
    ui->mAmpLineEdit->setEnabled(true);
    ui->mTmhtLineEdit->setEnabled(true);
    ui->mWmhtLineEdit->setEnabled(true);
}


/* Brief: Slot called when the 'Station' combobox is changed
 * Param: text, text that the 'Station' combobox contains after change
 */
void CWindowWDB::stationIndexChanged(QString text)
{
    CDailyWeatherModel* model = (CDailyWeatherModel*)ui->mDailyWeatherView->model();
    CStation* station = NULL;
    
    if( text.split("-").length() >= 2 ) {
        QString id = text.split("-")[0];
        QString name = text.split("-")[1];
        station = model->findStation(id, name);
    }

    // Update Station info line edits
    if (station == NULL) { // Station was changed to 'None'
        clearLineEdits();
        disableLineEdits();
    }
    else
    {
        ui->mStatNameLineEdit->setText(station->getStatAttrs()->value("Station_Name"));
        ui->mStatIDLineEdit->setText(station->getStatAttrs()->value("StationID"));
        ui->mPlaceNameLineEdit->setText(station->getStatAttrs()->value("Place_Name"));
        ui->mLatLineEdit->setText(station->getStatAttrs()->value("Lat"));
        ui->mLongLineEdit->setText(station->getStatAttrs()->value("Long"));
        ui->mElevLineEdit->setText(station->getStatAttrs()->value("Elev"));
        ui->mTavLineEdit->setText(station->getStatAttrs()->value("Tav"));
        ui->mAmpLineEdit->setText(station->getStatAttrs()->value("Amp"));
        ui->mTmhtLineEdit->setText(station->getStatAttrs()->value("Tmht"));
        ui->mWmhtLineEdit->setText(station->getStatAttrs()->value("Wmht"));
        
        enableLineEdits();
    }
    
    // Change the station being shown in the Daily Weather table
    model->setStation(station);
    model->update();
}


/* Brief: Delete text in the station line edits
 */
void CWindowWDB::clearLineEdits()
{
    ui->mStatNameLineEdit->clear();
    ui->mStatIDLineEdit->clear();
    ui->mPlaceNameLineEdit->clear();
    ui->mLatLineEdit->clear();
    ui->mLongLineEdit->clear();
    ui->mElevLineEdit->clear();
    ui->mTavLineEdit->clear();
    ui->mAmpLineEdit->clear();
    ui->mTmhtLineEdit->clear();
    ui->mWmhtLineEdit->clear();
}


/* Brief: Creates an XML file and saves it to a directory
 */
void CWindowWDB::saveXML() {
    QFile file(mFilename);
    file.open(QIODevice::WriteOnly);
    QXmlStreamWriter writer(&file);
    writer.setAutoFormatting(true);
    writer.writeStartDocument("1.0");
    writer.writeStartElement("WDB");
    
    CDailyWeatherModel* model = (CDailyWeatherModel*)ui->mDailyWeatherView->model();
    QVector<CStation* >* stations = model->getStations();
    QVector<CStation* >::const_iterator iter = stations->begin();
    
    for(;iter!=stations->end(); iter++)
    {
        CStation* station = *iter;
        AttrMap* statAttrs = station->getStatAttrs();
        AttrMap* weatherAttrs = station->getWeatherAttrs();
        
        QString sName = statAttrs->value("Station_Name");
        QString sId = statAttrs->value("StationID");
        QString pName = statAttrs->value("Place_Name");
        QString lat = statAttrs->value("Lat");
        QString lon = statAttrs->value("Long");
        QString elev = statAttrs->value("Elev");
        QString tav = statAttrs->value("Tav");
        QString amp = statAttrs->value("Amp");
        QString tmht = statAttrs->value("Tmht");
        QString wmht = statAttrs->value("Wmht");
        
        writer.writeStartElement("Stations");
        writer.writeAttribute("StationID", sId);
        writer.writeAttribute("Station_Name", sName);
        writer.writeAttribute("Place_Name", pName);
        writer.writeAttribute("Lat", lat);
        writer.writeAttribute("Long", lon);
        writer.writeAttribute("Elev", elev);
        writer.writeAttribute("Tav", tav);
        writer.writeAttribute("Amp", amp);
        writer.writeAttribute("Tmht", tmht);
        writer.writeAttribute("Wmht", wmht);
        
        writer.writeStartElement("Storm_Intensity");
        writer.writeEndElement();
        writer.writeStartElement("Hourly_Rainfall");
        writer.writeEndElement();
        writer.writeStartElement("Weather");
        AttrMap::const_iterator iter = weatherAttrs->find("Columns");
        QString columns = *iter;
        writer.writeAttribute("Columns", columns);
        
        //
        // Write weather data
        //
        Hash* weather = station->getWeather();
        //Hash::const_iterator it = weather->begin();
        writer.writeCharacters("\n");
        Hash::const_iterator hashIter;
        QString stringToWrite;
        for(int yr=1979; yr<=2099; yr++) {
            for(int doy=1; doy<=365;doy++) {
                Pair pair(QString::number(yr), QString::number(doy));
                hashIter = weather->find(pair);
                
                if(hashIter!=weather->end()) {
                
                    QVector<QString>* const values = *hashIter;
                    stringToWrite = QString::number(yr) + ',' + QString::number(doy) + ',';
                 
                    for(int j=0; j<values->size(); j++) {
                        stringToWrite+= values->at(j);
                        
                        if (j != values->size()-1) // this is not the last item, so print a comma
                            stringToWrite += ',';
                    }
                    writer.writeCharacters(stringToWrite + '\n');
                }
            }
        }
        
        writer.writeEndElement(); // end <Weather>
        writer.writeEndElement(); // end <Station>
        
    }
    
     // Write version control xml
     writer.writeStartElement("Version_Control");
     writer.writeStartElement("Version");
     writer.writeAttribute("Number", "X");
     writer.writeStartElement("ReleaseDate");
     writer.writeEndElement();
     writer.writeStartElement("Notes");
     writer.writeEndElement();
     writer.writeEndElement(); // end <Version>
     writer.writeEndElement(); // end <Version_Control>

    writer.writeEndDocument();
    file.close();

}


/* Brief: Automatically called when user selects File->Open
 */
void CWindowWDB::onFileOpen()
{
    QString dir = "../../xml/";
    
    // This is necessary on MAC to get the file dialog to have correct default directory
    QString dummyFile = "dummyFile.txt";
    
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), dir+dummyFile, tr("XML Files (*.xml)"));
    
    // User didn't select a file
    if(fileName == NULL)
        return;
}


/* Brief: Automatically called when user selects File->Save
 */
void CWindowWDB::onFileSave()
{
    saveXML();
}