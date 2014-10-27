#include <QGridLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QFormLayout>
#include <QComboBox>
#include <QLineEdit>
#include <QGroupBox>
#include <QFile>
#include <QXmlStreamWriter>

#include "CMainWindow.h"
#include "ui_mainwindow.h"
#include "CXMLParser.h"
#include "CStation.h"
#include "CTableView.h"
#include "CDailyWeatherModel.h"

CMainWindow::CMainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(1000,1000);
    setWindowTitle("XML Editor");
    
    //
    // Parse XML
    //
    CXMLParser parser;
    QVector<CStation* >* stations = parser.parseWDB();
    /*QVector<CStation* >::const_iterator iter = stations->begin();
    for(;iter!=stations->end(); iter++) {
        CStation* station = *iter;
        Map* weatherMap = station->getWeather();
        
        Map::const_iterator mapIter = weatherMap->begin();
        weatherMap
        Map::const_iterator iter = hash->find(pair);
    }*/
    
    
    QGridLayout* mainLayout = new QGridLayout();

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

    //
    // Build 'Station Information' Form
    //
    mStationCombobox = new QComboBox();
    mStationCombobox->setFixedSize(200, 30);
    mStationCombobox->addItems(options);

    mStatNameLineEdit = new QLineEdit();
    mStatIDLineEdit = new QLineEdit();
    mPlaceNameLineEdit = new QLineEdit();
    mLatLineEdit = new QLineEdit();
    mLongLineEdit = new QLineEdit();
    mElevLineEdit = new QLineEdit();
    mTavLineEdit = new QLineEdit();
    mAmpLineEdit = new QLineEdit();
    mTmhtLineEdit = new QLineEdit();
    mWmhtLineEdit = new QLineEdit();

    QGroupBox *stationGroupBox = new QGroupBox("Station Information");
    QFormLayout* stationForm = new QFormLayout(stationGroupBox);
    stationForm->setFormAlignment(Qt::AlignLeft);
    stationForm->setLabelAlignment(Qt::AlignLeft);
    stationForm->addRow("Choose a Station:", mStationCombobox);
    stationForm->addRow("Station ID:", mStatIDLineEdit);
    stationForm->addRow("Station Name:", mStatNameLineEdit);
    stationForm->addRow("Place Name:", mPlaceNameLineEdit);
    stationForm->addRow("Lat:", mLatLineEdit);
    stationForm->addRow("Long:", mLongLineEdit);
    stationForm->addRow("Elev:", mElevLineEdit);
    stationForm->addRow("Tav:", mTavLineEdit);
    stationForm->addRow("Amp:", mAmpLineEdit);
    stationForm->addRow("Tmht:", mTmhtLineEdit);
    stationForm->addRow("Wmht:", mWmhtLineEdit);

    //
    // Daily Weather Group Box
    //
    QGroupBox *weatherGroupBox = new QGroupBox("Daily Weather");
    mDailyWeatherView = new CTableView();
    CDailyWeatherModel* weatherModel = new CDailyWeatherModel();
    weatherModel->setStations(stations);
    mDailyWeatherView->setModel(weatherModel);
    
    QFormLayout* weatherYearForm = new QFormLayout();
    weatherYearForm->setFormAlignment(Qt::AlignLeft);
    weatherYearForm->setLabelAlignment(Qt::AlignLeft);
    
    mYearCombobox = new QComboBox();
    mYearCombobox->setFixedSize(150, 30);
    
    // TO-DO: Don't assume all years present.
    for(int year=1979; year<2000; year++)
        mYearCombobox->addItem(QString::number(year));
    weatherYearForm->addRow("Choose Year:", mYearCombobox);
    
    QVBoxLayout* vlayout1 = new QVBoxLayout();
    vlayout1->addLayout(weatherYearForm);
    vlayout1->addWidget(mDailyWeatherView);
    
    weatherGroupBox->setLayout(vlayout1);

    /*
    //
    // Hourly Weather Group Box
    //
    QGroupBox *hrWeatherGroupBox = new QGroupBox("Hourly Weather");
    mHrWeatherView = new CTableView();
    //CDailyWeatherModel* weatherModel = new CDailyWeatherModel();
    //weatherModel->setStations(stations);
    //mDailyWeatherView->setModel(weatherModel);

    QVBoxLayout* vlayout2 = new QVBoxLayout();
    vlayout2->addWidget(mHrWeatherView);
    
    hrWeatherGroupBox->setLayout(vlayout2);
    */
    
    mainLayout->addWidget(stationGroupBox);
    mainLayout->addWidget(weatherGroupBox);
    //mainLayout->addWidget(hrWeatherGroupBox);
    
    // Create a default widget as the centeral widget and
    // apply the vertical layout to it.
    setCentralWidget(new QWidget());
    centralWidget()->setLayout(mainLayout);

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
void CMainWindow::buildMenuBar()
{
    qDebug("this is not a MAC OS");

}

/* Brief: Build menu bar for MAC OS
 */
void CMainWindow::buildMacMenuBar()
{
    qDebug("this is MAC OS");
    macMenuBar = new QMenuBar(0);
    QMenu* fileMenu = macMenuBar->addMenu("File"); //new QMenu("File", 0);
    
    mFileSave = new QAction("Save", this);
    mFileExit = new QAction("Exit", this);

    mFileSave->setMenuRole(QAction::NoRole);
    mFileExit->setMenuRole(QAction::NoRole);
    fileMenu->addAction(mFileSave);
    fileMenu->addAction(mFileExit);
    
    macMenuBar->addMenu(fileMenu);
    setMenuBar(macMenuBar);
}

/* Brief:
 */
CMainWindow::~CMainWindow()
{
    delete ui;
}

/* Brief:
 */
void CMainWindow::makeConnections()
{
    connect(mStationCombobox, SIGNAL(currentIndexChanged(QString)), this, SLOT(stationIndexChanged(QString)));
    connect(mYearCombobox, SIGNAL(currentIndexChanged(QString)), this, SLOT(yearIndexChanged(QString)));
    connect(mFileSave, SIGNAL(triggered (bool)), this, SLOT(onFileSave()));
    connect(mFileExit, SIGNAL(triggered (bool)), this, SLOT(close()));
}


/* Brief: Slot called when the Weather Year combobox is changed
 */
void CMainWindow::yearIndexChanged(QString text)
{
    CDailyWeatherModel* model = (CDailyWeatherModel*)mDailyWeatherView->model();
    
    qDebug("year:%i", text.toInt());
    model->setYear(text.toInt());
    
    model->update();
       
}


/* Brief: Slot called when the Station combobox is changed
 */
void CMainWindow::stationIndexChanged(QString text)
{
    CDailyWeatherModel* model = (CDailyWeatherModel*)mDailyWeatherView->model();
    QVector<CStation* >* stations = model->getStations();
    
    QString id;
    QString name;

    // Station which corresponds to the selected combobox option
    CStation* station = NULL;

    if (text.split("-").length() == 2)
    {
        id = text.split("-")[0];
        name = text.split("-")[1];

        // Find corresponding station
        QVector<CStation* >::const_iterator iter;
        for (iter = stations->begin(); iter != stations->end(); ++iter)
        {
            CStation* currStation = *iter;
            QString statID = currStation->getStatAttrs()->value("StationID");
            QString statName = currStation->getStatAttrs()->value("Station_Name");

            if(statID == id && statName == name)
            {
                station = currStation;
                break;
            }
        }
    }

    // Update Station info line edits
    if (station == NULL)
        clearStationLineEdits();
    else
    {
        mStatNameLineEdit->setText(station->getStatAttrs()->value("Station_Name"));
        mStatIDLineEdit->setText(station->getStatAttrs()->value("StationID"));
        mPlaceNameLineEdit->setText(station->getStatAttrs()->value("Place_Name"));
        mLatLineEdit->setText(station->getStatAttrs()->value("Lat"));
        mLongLineEdit->setText(station->getStatAttrs()->value("Long"));
        mElevLineEdit->setText(station->getStatAttrs()->value("Elev"));
        mTavLineEdit->setText(station->getStatAttrs()->value("Tav"));
        mAmpLineEdit->setText(station->getStatAttrs()->value("Amp"));
        mTmhtLineEdit->setText(station->getStatAttrs()->value("Tmht"));
        mWmhtLineEdit->setText(station->getStatAttrs()->value("Wmht"));
    }
    
    // Change the station being shown in the Daily Weather table
    model->setStation(station);
    model->update();
}


/* Brief:
 */
void CMainWindow::clearStationLineEdits()
{
    mStatNameLineEdit->clear();
    mStatIDLineEdit->clear();
    mPlaceNameLineEdit->clear();
    mLatLineEdit->clear();
    mLongLineEdit->clear();
    mElevLineEdit->clear();
    mTavLineEdit->clear();
    mAmpLineEdit->clear();
    mTmhtLineEdit->clear();
    mWmhtLineEdit->clear();
}


/* Brief: Creates an XML file and saves it to a directory
 */
void CMainWindow::saveXML() {
    QFile file("/Users/westjour/Desktop/GUI_Repo/xml/NEW_XML.xml");
    file.open(QIODevice::WriteOnly);
    QXmlStreamWriter writer(&file);
    writer.setAutoFormatting(true);
    writer.writeStartDocument("1.0");
    writer.writeStartElement("WDB");
    
    CDailyWeatherModel* model = (CDailyWeatherModel*)mDailyWeatherView->model();
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

/* Brief: Automatically called when user selects File->Save
 */
void CMainWindow::onFileSave()
{
    saveXML();
}