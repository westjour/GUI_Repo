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
}

/* Brief:
 */
CWindowSDB::~CWindowSDB()
{
}