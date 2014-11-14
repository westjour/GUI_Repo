//
//  CWindowSDB.cpp
//  XMLEditor
//
//  Created by Jourdan West on 11/10/14.
//
//

#include<QVector>

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
    qDebug("done parsing SDB XML");
    CSoilLayerModel* soilModel = new CSoilLayerModel();
    soilModel->setSoils(soils);
    ui->soilLayerView->setModel(soilModel);
    
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
    
    makeConnections();
}


/* Brief:
 */
void CWindowSDB::makeConnections()
{
    connect(ui->soilCombobox, SIGNAL(currentIndexChanged(QString)), this, SLOT(onSoilChanged(QString)));
}

/* Brief: Automatically called when Soil is changed in the dropdown
 * Param: id, id of Soil that dropdown was changed to
 */
void CWindowSDB::onSoilChanged(QString id)
{
    qDebug("soil id:%s", id.toUtf8().constData());
    CSoil* soil = NULL;
    CSoilLayerModel* model = (CSoilLayerModel*)ui->soilLayerView->model();
    soil = model->findSoil(id);
    
    // Update Station info line edits
    if (soil == NULL) { // Soil was changed to 'None'
        //clearStationLineEdits();
        //disableStationDataLineEdits();
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

        //enableStationDataLineEdits();
    }
    
    // Change the soil being shown in the Soil Layer table
    model->setSoil(soil);
    model->update();
}


/* Brief:
 */
CWindowSDB::~CWindowSDB()
{
}