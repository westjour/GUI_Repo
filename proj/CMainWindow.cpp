#include <QGridLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QFormLayout>
#include <QComboBox>
#include <QLineEdit>
#include <QGroupBox>

#include "CMainWindow.h"
#include "ui_mainwindow.h"
#include "CXMLParser.h"
#include "CStation.h"
#include "CDailyWeatherView.h"
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
    parser.parseWDB(&mStations);
    
    QGridLayout* mainLayout = new QGridLayout();

    //
    // Construct strings for Station combobox
    //
    QVector<CStation* >::const_iterator iter;
    QStringList options = QStringList("None");
    for ( iter = mStations.begin(); iter!=mStations.end(); ++iter )
    {
        CStation* station = *iter;
        std::map<QString, QString> attrMap = station->getAttributes();
        QString s = attrMap["StationID"] + '-' + attrMap["Station_Name"];
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
    mDailyWeatherView = new CDailyWeatherView();
    CDailyWeatherModel* weatherModel = new CDailyWeatherModel();
    weatherModel->setStations(mStations);
    mDailyWeatherView->setModel(weatherModel);
    
    
    //QAbstractItemModel* model = mDailyWeatherView->model();
    
    QFormLayout* weatherYearForm = new QFormLayout();
    weatherYearForm->setFormAlignment(Qt::AlignLeft);
    weatherYearForm->setLabelAlignment(Qt::AlignLeft);
    
    mYearCombobox = new QComboBox();
    mYearCombobox->setFixedSize(150, 30);
    
    // TO-DO Populate Weather year combobox
    for(int year=1979; year<2000; year++)
        mYearCombobox->addItem(QString::number(year));
    weatherYearForm->addRow("Choose Year:", mYearCombobox);
    
    QVBoxLayout* vlayout1 = new QVBoxLayout();
    vlayout1->addLayout(weatherYearForm);
    vlayout1->addWidget(mDailyWeatherView);
    
    weatherGroupBox->setLayout(vlayout1);

    mainLayout->addWidget(stationGroupBox);
    mainLayout->addWidget(weatherGroupBox);

    // Create a default widget as the centeral widget and
    // apply the vertical layout to it.
    setCentralWidget(new QWidget());
    centralWidget()->setLayout(mainLayout);

    makeConnections();
}


/* Brief:
 */
void CMainWindow::makeConnections()
{
    connect(mStationCombobox, SIGNAL(currentIndexChanged(QString)), this, SLOT(stationIndexChanged(QString)));
    connect(mYearCombobox, SIGNAL(currentIndexChanged(QString)), this, SLOT(yearIndexChanged(QString)));
    
}


/* Brief: Slot called when the Weather Year combobox is changed
 */
void CMainWindow::yearIndexChanged(QString text)
{
    CDailyWeatherModel* model = (CDailyWeatherModel*)mDailyWeatherView->model();
    
    model->setYear(text.toInt());
    
}


/* Brief: Slot called when the Station combobox is changed
 */
void CMainWindow::stationIndexChanged(QString text)
{
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
        for (iter = mStations.begin(); iter != mStations.end(); ++iter)
        {
            CStation* currStation = *iter;
            QString statID = currStation->getAttributes()["StationID"];
            QString statName = currStation->getAttributes()["Station_Name"];

            if(statID == id && statName == name)
            {
                station = currStation;
                break;
            }
        }
    }

    // If the station is found, update text in line edits
    if (station == NULL)
        clearStationLineEdits();
    else
    {
        mStatNameLineEdit->setText(station->getAttributes()["Station_Name"]);
        mStatIDLineEdit->setText(station->getAttributes()["StationID"]);
        mPlaceNameLineEdit->setText(station->getAttributes()["Place_Name"]);
        mLatLineEdit->setText(station->getAttributes()["Lat"]);
        mLongLineEdit->setText(station->getAttributes()["Long"]);
        mElevLineEdit->setText(station->getAttributes()["Elev"]);
        mTavLineEdit->setText(station->getAttributes()["Tav"]);
        mAmpLineEdit->setText(station->getAttributes()["Amp"]);
        mTmhtLineEdit->setText(station->getAttributes()["Tmht"]);
        mWmhtLineEdit->setText(station->getAttributes()["Wmht"]);
    }

}

void CMainWindow::clearStationLineEdits()
{
    mStatNameLineEdit->setText("");
    mStatIDLineEdit->setText("");
    mPlaceNameLineEdit->setText("");
    mLatLineEdit->setText("");
    mLongLineEdit->setText("");
    mElevLineEdit->setText("");
    mTavLineEdit->setText("");
    mAmpLineEdit->setText("");
    mTmhtLineEdit->setText("");
    mWmhtLineEdit->setText("");
}

CMainWindow::~CMainWindow()
{
    delete ui;
}
