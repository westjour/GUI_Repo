//
//  CWindowSDB.cpp
//  XMLEditor
//
//  Created by Jourdan West on 11/10/14.
//
//

#include <QFile>
#include <QXmlStreamWriter>
#include <QVector>
#include <QFileDialog>

#include "CSoil.h"
#include "CSoilLayerModel.cpp"
#include "CXMLParser.h"
#include "CWindowSDB.h"
#include "ui_sdb.h"

CWindowSDB::CWindowSDB(QWidget *parent, QString filename): QMainWindow(parent), ui(new Ui::SDB){
    ui->setupUi(this);
    
    mFilename = filename;
    
    // Parse SDB XML
    CXMLParser parser;
    QVector<CSoil* >* soils = parser.parseSDB();
    
    // Set model onto view
    CSoilLayerModel* soilLayerModel = new CSoilLayerModel();
    soilLayerModel->setSoils(soils);
    ui->soilLayerView->setModel(soilLayerModel);
    
    //
    // Construct strings for Soil combobox
    //
    QVector<CSoil* >::const_iterator it = soils->begin();
    QStringList options = QStringList("None");
    for (; it!=soils->end(); ++it )
    {
        CSoil* soil = *it;
        AttrMap* attrs = soil->getSoilAttrs();
        QString s = attrs->value("SoilID");
        options.append(s);
    }
    
    ui->soilCombobox->setFixedSize(200, 30);
    ui->soilCombobox->addItems(options);
    
    // Create menus based on the operating system
    #ifdef Q_OS_MAC
    buildMacMenuBar();
    #endif

    #ifndef Q_OS_MAC
    buildMenuBar();
    #endif

    disableLineEdits();
    makeConnections();
}


/* Brief:
 */
void CWindowSDB::makeConnections()
{
    connect(ui->soilCombobox, SIGNAL(currentIndexChanged(QString)), this, SLOT(onSoilChanged(QString)));
    connect(mFileSave, SIGNAL(triggered (bool)), this, SLOT(onFileSave()));
    //connect(mFileOpen, SIGNAL(triggered (bool)), this, SLOT(onFileOpen()));
    connect(mFileExit, SIGNAL(triggered (bool)), this, SLOT(close()));
}

/* Brief: Build menu bar for any OS other than MAC
 */
void CWindowSDB::buildMenuBar()
{
}


/* Brief: Build menu bar for MAC OS
 */
void CWindowSDB::buildMacMenuBar()
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


/* Brief: Automatically called when Soil is changed in the dropdown
 * Param: id, id of Soil that dropdown was changed to
 */
void CWindowSDB::onSoilChanged(QString id)
{
    CSoil* soil = NULL;
    CSoilLayerModel* model = (CSoilLayerModel*)ui->soilLayerView->model();
    soil = model->findSoil(id);
    
    // Update Station info line edits
    if (soil == NULL) { // Soil was changed to 'None'
        clearLineEdits();
        disableLineEdits();
    }
    else
    {
        ui->sldescLineEdit->setText(soil->getSoilAttrs()->value("SlDesc"));
        ui->slsourLineEdit->setText(soil->getSoilAttrs()->value("Slsour"));
        ui->sltxLineEdit->setText(soil->getSoilAttrs()->value("Sltx"));
        ui->sldpLineEdit->setText(soil->getSoilAttrs()->value("Sldp"));
        ui->ssiteLineEdit->setText(soil->getSoilAttrs()->value("SSite"));
        ui->scountLineEdit->setText(soil->getSoilAttrs()->value("SCount"));
        ui->slatLineEdit->setText(soil->getSoilAttrs()->value("SLat"));
        ui->slongLineEdit->setText(soil->getSoilAttrs()->value("SLong"));
        ui->taconLineEdit->setText(soil->getSoilAttrs()->value("Tacon"));
        ui->scomLineEdit->setText(soil->getSoilAttrs()->value("Scom"));
        ui->salbLineEdit->setText(soil->getSoilAttrs()->value("Salb"));
        ui->uLineEdit->setText(soil->getSoilAttrs()->value("U"));
        ui->SWCONLineEdit->setText(soil->getSoilAttrs()->value("SWCON"));
        ui->CN2LineEdit->setText(soil->getSoilAttrs()->value("CN2"));
        ui->slnfLineEdit->setText(soil->getSoilAttrs()->value("Slnf"));
        ui->slpfLineEdit->setText(soil->getSoilAttrs()->value("Slpf"));
        ui->smhbLineEdit->setText(soil->getSoilAttrs()->value("Smhb"));
        ui->smpxLineEdit->setText(soil->getSoilAttrs()->value("Smpx"));
        ui->smkeLineEdit->setText(soil->getSoilAttrs()->value("Smke"));
        ui->pondMaxLineEdit->setText(soil->getSoilAttrs()->value("PondMax"));

        enableLineEdits();
    }
    
    // Change the soil being shown in the Soil Layer table
    model->setSoil(soil);
    model->update();
}


/* Brief: Destructor
 */
CWindowSDB::~CWindowSDB()
{
}


/* Brief: Delete text in the station line edits
 */
void CWindowSDB::clearLineEdits()
{
    ui->sldescLineEdit->clear();
    ui->slsourLineEdit->clear();
    ui->sltxLineEdit->clear();
    ui->sldpLineEdit->clear();
    ui->ssiteLineEdit->clear();
    ui->scountLineEdit->clear();
    ui->slatLineEdit->clear();
    ui->slongLineEdit->clear();
    ui->taconLineEdit->clear();
    ui->scomLineEdit->clear();
    ui->salbLineEdit->clear();
    ui->uLineEdit->clear();
    ui->SWCONLineEdit->clear();
    ui->CN2LineEdit->clear();
    ui->slnfLineEdit->clear();
    ui->slpfLineEdit->clear();
    ui->smhbLineEdit->clear();
    ui->smpxLineEdit->clear();
    ui->smkeLineEdit->clear();
    ui->pondMaxLineEdit->clear();
}


/* Brief: Disable the soil line edits for editing
 */
void CWindowSDB::disableLineEdits()
{
    ui->sldescLineEdit->setEnabled(false);
    ui->slsourLineEdit->setEnabled(false);
    ui->sltxLineEdit->setEnabled(false);
    ui->sldpLineEdit->setEnabled(false);
    ui->ssiteLineEdit->setEnabled(false);
    ui->scountLineEdit->setEnabled(false);
    ui->slatLineEdit->setEnabled(false);
    ui->slongLineEdit->setEnabled(false);
    ui->taconLineEdit->setEnabled(false);
    ui->scomLineEdit->setEnabled(false);
    ui->salbLineEdit->setEnabled(false);
    ui->uLineEdit->setEnabled(false);
    ui->SWCONLineEdit->setEnabled(false);
    ui->CN2LineEdit->setEnabled(false);
    ui->slnfLineEdit->setEnabled(false);
    ui->slpfLineEdit->setEnabled(false);
    ui->smhbLineEdit->setEnabled(false);
    ui->smpxLineEdit->setEnabled(false);
    ui->smkeLineEdit->setEnabled(false);
    ui->pondMaxLineEdit->setEnabled(false);
}


/* Brief: Enable the soil line edits for editing
 */
void CWindowSDB::enableLineEdits()
{
    ui->sldescLineEdit->setEnabled(true);
    ui->slsourLineEdit->setEnabled(true);
    ui->sltxLineEdit->setEnabled(true);
    ui->sldpLineEdit->setEnabled(true);
    ui->ssiteLineEdit->setEnabled(true);
    ui->scountLineEdit->setEnabled(true);
    ui->slatLineEdit->setEnabled(true);
    ui->slongLineEdit->setEnabled(true);
    ui->taconLineEdit->setEnabled(true);
    ui->scomLineEdit->setEnabled(true);
    ui->salbLineEdit->setEnabled(true);
    ui->uLineEdit->setEnabled(true);
    ui->SWCONLineEdit->setEnabled(true);
    ui->CN2LineEdit->setEnabled(true);
    ui->slnfLineEdit->setEnabled(true);
    ui->slpfLineEdit->setEnabled(true);
    ui->smhbLineEdit->setEnabled(true);
    ui->smpxLineEdit->setEnabled(true);
    ui->smkeLineEdit->setEnabled(true);
    ui->pondMaxLineEdit->setEnabled(true);
}


/* Brief: Creates an XML file and saves it to a directory
 */
void CWindowSDB::saveXML(QString filename) {
    qDebug("saving to file %s", filename.toUtf8().constData());
    QFile file(filename);
    file.open(QIODevice::WriteOnly);
    QXmlStreamWriter writer(&file);
    writer.setAutoFormatting(true);
    writer.writeStartDocument("1.0");
    writer.writeStartElement("SDB");
    writer.writeStartElement("Soils");
    
    CSoilLayerModel* model = (CSoilLayerModel*)ui->soilLayerView->model();
    QVector<CSoil* >* soils = model->getSoils();
    QVector<CSoil* >::const_iterator iter = soils->begin();
    
    for(;iter!=soils->end(); iter++)
    {
        writer.writeStartElement("Soil");
        CSoil* soil = *iter;
        AttrMap* soilAttrs = soil->getSoilAttrs();
        
        QString SoilID = soilAttrs->value("SoilID");
        QString SlDesc = soilAttrs->value("SlDesc");
        QString Slsour = soilAttrs->value("Slsour");
        QString Sltx = soilAttrs->value("Sltx");
        QString Sldp = soilAttrs->value("Sldp");
        QString SSite = soilAttrs->value("SSite");
        QString SCount = soilAttrs->value("SCount");
        QString SLat = soilAttrs->value("SLat");
        QString SLong = soilAttrs->value("SLong");
        QString Tacon = soilAttrs->value("Tacon");
        QString Scom = soilAttrs->value("Scom");
        QString Salb = soilAttrs->value("Salb");
        QString U = soilAttrs->value("U");
        QString SWCON = soilAttrs->value("SWCON");
        QString CN2 = soilAttrs->value("CN2");
        QString Slnf = soilAttrs->value("Slnf");
        QString Slpf = soilAttrs->value("Slpf");
        QString Smhb = soilAttrs->value("Smhb");
        QString Smpx = soilAttrs->value("Smpx");
        QString Smke = soilAttrs->value("Smke");
        QString PondMax = soilAttrs->value("PondMax");
        
        /*writer.writeAttribute("SoilID", SoilID);
        writer.writeAttribute("SlDesc", SlDesc);
        writer.writeAttribute("Slsour", Slsour);
        writer.writeAttribute("Sltx", Sltx);
        writer.writeAttribute("Sldp", Sldp);
        writer.writeAttribute("SSite", SSite);
        writer.writeAttribute("SCount", SCount);
        writer.writeAttribute("SLat", SLat);
        writer.writeAttribute("SLong", SLong);
        writer.writeAttribute("Tacon", Tacon);
        writer.writeAttribute("Scom", Scom);
        writer.writeAttribute("Scom", Scom);
        writer.writeAttribute("Scom", Scom);
        writer.writeAttribute("Scom", Scom);
        writer.writeAttribute("Scom", Scom);
        writer.writeAttribute("Scom", Scom);
        writer.writeAttribute("Scom", Scom);
        writer.writeAttribute("Scom", Scom);
        writer.writeAttribute("Scom", Scom);
        writer.writeAttribute("Scom", Scom);*/
    
        writer.writeEndElement();
    }
     /*   //
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
    writer.writeEndElement(); // end <Version_Control>*/
    
    writer.writeEndDocument();
    file.close();
    
}


/* Brief: Automatically called when user selects File->Save
 */
void CWindowSDB::onFileSave()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("XML (*.xml)"));
    
    if(!fileName.isNull())
        saveXML(fileName);
}
