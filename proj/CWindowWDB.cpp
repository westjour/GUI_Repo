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

#include "CMainWindow.h"
#include "ui_mainwindow.h"
#include "CXMLParser.h"
#include "CStation.h"
#include "CTableView.h"
#include "CDailyWeatherModel.h"

CMainWindow::CMainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setFixedSize(1000,1000);
    setWindowTitle("WEATHER");
    
    //
    // Parse XML
    //
    CXMLParser parser;
    QVector<CStation* >* stations = parser.parseWDB();
    
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
    QGridLayout* mainLayout = new QGridLayout();
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
}


/* Brief: Build menu bar for MAC OS
 */
void CMainWindow::buildMacMenuBar()
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
    connect(mFileOpen, SIGNAL(triggered (bool)), this, SLOT(onFileOpen()));
    connect(mFileExit, SIGNAL(triggered (bool)), this, SLOT(close()));
    
    
    //
    // Set up signal mapping for Station Data line edits
    //
    QSignalMapper *signalMapper = new QSignalMapper(this);
    
    connect(mStatNameLineEdit, SIGNAL(textChanged(QString)), signalMapper, SLOT(map()));
    connect(mStatIDLineEdit, SIGNAL(textChanged(QString)), signalMapper, SLOT(map()));
    connect(mPlaceNameLineEdit, SIGNAL(textChanged(QString)), signalMapper, SLOT(map()));
    connect(mLatLineEdit, SIGNAL(textChanged(QString)), signalMapper, SLOT(map()));
    connect(mLongLineEdit, SIGNAL(textChanged(QString)), signalMapper, SLOT(map()));
    connect(mElevLineEdit, SIGNAL(textChanged(QString)), signalMapper, SLOT(map()));
    connect(mTavLineEdit, SIGNAL(textChanged(QString)), signalMapper, SLOT(map()));
    connect(mAmpLineEdit, SIGNAL(textChanged(QString)), signalMapper, SLOT(map()));
    connect(mTmhtLineEdit, SIGNAL(textChanged(QString)), signalMapper, SLOT(map()));
    connect(mWmhtLineEdit, SIGNAL(textChanged(QString)), signalMapper, SLOT(map()));

    signalMapper->setMapping(mStatNameLineEdit, ("Station_Name"));
    signalMapper->setMapping(mStatIDLineEdit, ("StationID"));
    signalMapper->setMapping(mPlaceNameLineEdit, ("Place_Name"));
    signalMapper->setMapping(mLatLineEdit, ("Lat"));
    signalMapper->setMapping(mLongLineEdit, ("Long"));
    signalMapper->setMapping(mElevLineEdit, ("Elev"));
    signalMapper->setMapping(mTavLineEdit, ("Tav"));
    signalMapper->setMapping(mAmpLineEdit, ("Amp"));
    signalMapper->setMapping(mTmhtLineEdit, ("Tmht"));
    signalMapper->setMapping(mWmhtLineEdit, ("Wmht"));
    
    connect(signalMapper, SIGNAL(mapped(QString)), this, SLOT(onStationDataChanged(QString)));
}


/* Brief: Slot called when the Weather Year combobox is changed
 * Param: text, text that the 'Year' combobox contains after it is changed
 */
void CMainWindow::yearIndexChanged(QString text)
{
    CDailyWeatherModel* model = (CDailyWeatherModel*)mDailyWeatherView->model();
    model->setYear(text.toInt());
    model->update();
}


/* Brief: Automatically called when a station line edit text is changed
 * Param: field, field that was modified (i.e. Tmht, Wmht, etc.)
 */
void CMainWindow::onStationDataChanged(QString field)
{
    // Find the current station
    CDailyWeatherModel* model = (CDailyWeatherModel*)mDailyWeatherView->model();
    
    QString text = mStationCombobox->currentText();
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
        
        if(field == "Wmht") { lineEdit = mWmhtLineEdit ;}
        else if(field == "Tmht") { lineEdit = mTmhtLineEdit ;}
        else if(field == "Station_Name") { lineEdit = mStatNameLineEdit ;}
        else if(field == "StationID") { lineEdit = mStatIDLineEdit ;}
        else if(field == "Place_Name") { lineEdit = mPlaceNameLineEdit ;}
        else if(field == "Lat") { lineEdit = mLatLineEdit ;}
        else if(field == "Long") { lineEdit = mLongLineEdit ;}
        else if(field == "Elev") { lineEdit = mElevLineEdit ;}
        else if(field == "Tav") { lineEdit = mTavLineEdit ;}
        else if(field == "Amp") { lineEdit = mAmpLineEdit ;}
        
        // Update Station Attr
        (*attrs)[field] = lineEdit->text();
    }
}


/* Brief: Disable the station line edits for editing
 */
void CMainWindow::disableStationDataLineEdits()
{
    mStatNameLineEdit->setEnabled(false);
    mStatNameLineEdit->setEnabled(false);
    mStatIDLineEdit->setEnabled(false);
    mPlaceNameLineEdit->setEnabled(false);
    mLatLineEdit->setEnabled(false);
    mLongLineEdit->setEnabled(false);
    mElevLineEdit->setEnabled(false);
    mTavLineEdit->setEnabled(false);
    mAmpLineEdit->setEnabled(false);
    mTmhtLineEdit->setEnabled(false);
    mWmhtLineEdit->setEnabled(false);
}


/* Brief: Enable the station line edits for editing
 */
void CMainWindow::enableStationDataLineEdits()
{
    mStatNameLineEdit->setEnabled(true);
    mStatNameLineEdit->setEnabled(true);
    mStatIDLineEdit->setEnabled(true);
    mPlaceNameLineEdit->setEnabled(true);
    mLatLineEdit->setEnabled(true);
    mLongLineEdit->setEnabled(true);
    mElevLineEdit->setEnabled(true);
    mTavLineEdit->setEnabled(true);
    mAmpLineEdit->setEnabled(true);
    mTmhtLineEdit->setEnabled(true);
    mWmhtLineEdit->setEnabled(true);
}


/* Brief: Slot called when the 'Station' combobox is changed
 * Param: text, text that the 'Station' combobox contains after change
 */
void CMainWindow::stationIndexChanged(QString text)
{
    CDailyWeatherModel* model = (CDailyWeatherModel*)mDailyWeatherView->model();
    CStation* station = NULL;
    
    if( text.split("-").length() >= 2 ) {
        QString id = text.split("-")[0];
        QString name = text.split("-")[1];
        station = model->findStation(id, name);
    }

    // Update Station info line edits
    if (station == NULL) { // Station was changed to 'None'
        clearStationLineEdits();
        disableStationDataLineEdits();
    }
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
        
        enableStationDataLineEdits();
    }
    
    // Change the station being shown in the Daily Weather table
    model->setStation(station);
    model->update();
}


/* Brief: Delete text in the station line edits
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


/* Brief: Automatically called when user selects File->Open
 */
void CMainWindow::onFileOpen()
{
    QString dir = "../../xml/";
    
    // This is necessary on MAC to get the file dialog to have correct default directory
    QString dummyFile = "dummyFile.txt";
    
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), dir+dummyFile, tr("XML Files (*.xml)"));
    
    // User didn't select a file
    if(fileName == NULL)
        return;
    
    qDebug("file to open:%s", fileName.toUtf8().constData());
}


/* Brief: Automatically called when user selects File->Save
 */
void CMainWindow::onFileSave()
{
    saveXML();
}