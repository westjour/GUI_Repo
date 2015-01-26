/********************************************************************************
** Form generated from reading UI file 'wdb.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WDB_H
#define UI_WDB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WDB
{
public:
    QWidget *centralWidget;
    QGroupBox *statGroupBox;
    QWidget *formLayoutWidget;
    QFormLayout *stationDataFormLayout;
    QLabel *statIDLabel;
    QLineEdit *mStatIDLineEdit;
    QLabel *statNameLabel;
    QLineEdit *mStatNameLineEdit;
    QLabel *placeLabel;
    QLineEdit *mPlaceNameLineEdit;
    QLabel *latLabel;
    QLineEdit *mLatLineEdit;
    QLabel *longLabel;
    QLineEdit *mLongLineEdit;
    QLabel *elevLabel;
    QLineEdit *mElevLineEdit;
    QLabel *tavLabel;
    QLineEdit *mTavLineEdit;
    QLabel *ampLabel;
    QLineEdit *mAmpLineEdit;
    QLabel *tmhtLabel;
    QLineEdit *mTmhtLineEdit;
    QLabel *wmhtLabel;
    QLineEdit *mWmhtLineEdit;
    QGroupBox *dwGroupBox;
    QWidget *formLayoutWidget_2;
    QFormLayout *yearFormLayout;
    QLabel *yearLabel;
    QComboBox *mYearCombobox;
    QTableView *mDailyWeatherView;
    QSplitter *splitter;
    QLabel *stationLabel;
    QComboBox *mStationCombobox;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *WDB)
    {
        if (WDB->objectName().isEmpty())
            WDB->setObjectName(QStringLiteral("WDB"));
        WDB->resize(923, 927);
        centralWidget = new QWidget(WDB);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        statGroupBox = new QGroupBox(centralWidget);
        statGroupBox->setObjectName(QStringLiteral("statGroupBox"));
        statGroupBox->setGeometry(QRect(10, 70, 441, 301));
        formLayoutWidget = new QWidget(statGroupBox);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(20, 30, 381, 341));
        stationDataFormLayout = new QFormLayout(formLayoutWidget);
        stationDataFormLayout->setSpacing(6);
        stationDataFormLayout->setContentsMargins(11, 11, 11, 11);
        stationDataFormLayout->setObjectName(QStringLiteral("stationDataFormLayout"));
        stationDataFormLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        stationDataFormLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        stationDataFormLayout->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        stationDataFormLayout->setContentsMargins(0, 0, 0, 0);
        statIDLabel = new QLabel(formLayoutWidget);
        statIDLabel->setObjectName(QStringLiteral("statIDLabel"));

        stationDataFormLayout->setWidget(0, QFormLayout::LabelRole, statIDLabel);

        mStatIDLineEdit = new QLineEdit(formLayoutWidget);
        mStatIDLineEdit->setObjectName(QStringLiteral("mStatIDLineEdit"));

        stationDataFormLayout->setWidget(0, QFormLayout::FieldRole, mStatIDLineEdit);

        statNameLabel = new QLabel(formLayoutWidget);
        statNameLabel->setObjectName(QStringLiteral("statNameLabel"));

        stationDataFormLayout->setWidget(1, QFormLayout::LabelRole, statNameLabel);

        mStatNameLineEdit = new QLineEdit(formLayoutWidget);
        mStatNameLineEdit->setObjectName(QStringLiteral("mStatNameLineEdit"));

        stationDataFormLayout->setWidget(1, QFormLayout::FieldRole, mStatNameLineEdit);

        placeLabel = new QLabel(formLayoutWidget);
        placeLabel->setObjectName(QStringLiteral("placeLabel"));

        stationDataFormLayout->setWidget(2, QFormLayout::LabelRole, placeLabel);

        mPlaceNameLineEdit = new QLineEdit(formLayoutWidget);
        mPlaceNameLineEdit->setObjectName(QStringLiteral("mPlaceNameLineEdit"));

        stationDataFormLayout->setWidget(2, QFormLayout::FieldRole, mPlaceNameLineEdit);

        latLabel = new QLabel(formLayoutWidget);
        latLabel->setObjectName(QStringLiteral("latLabel"));

        stationDataFormLayout->setWidget(3, QFormLayout::LabelRole, latLabel);

        mLatLineEdit = new QLineEdit(formLayoutWidget);
        mLatLineEdit->setObjectName(QStringLiteral("mLatLineEdit"));

        stationDataFormLayout->setWidget(3, QFormLayout::FieldRole, mLatLineEdit);

        longLabel = new QLabel(formLayoutWidget);
        longLabel->setObjectName(QStringLiteral("longLabel"));

        stationDataFormLayout->setWidget(4, QFormLayout::LabelRole, longLabel);

        mLongLineEdit = new QLineEdit(formLayoutWidget);
        mLongLineEdit->setObjectName(QStringLiteral("mLongLineEdit"));

        stationDataFormLayout->setWidget(4, QFormLayout::FieldRole, mLongLineEdit);

        elevLabel = new QLabel(formLayoutWidget);
        elevLabel->setObjectName(QStringLiteral("elevLabel"));

        stationDataFormLayout->setWidget(5, QFormLayout::LabelRole, elevLabel);

        mElevLineEdit = new QLineEdit(formLayoutWidget);
        mElevLineEdit->setObjectName(QStringLiteral("mElevLineEdit"));

        stationDataFormLayout->setWidget(5, QFormLayout::FieldRole, mElevLineEdit);

        tavLabel = new QLabel(formLayoutWidget);
        tavLabel->setObjectName(QStringLiteral("tavLabel"));

        stationDataFormLayout->setWidget(6, QFormLayout::LabelRole, tavLabel);

        mTavLineEdit = new QLineEdit(formLayoutWidget);
        mTavLineEdit->setObjectName(QStringLiteral("mTavLineEdit"));

        stationDataFormLayout->setWidget(6, QFormLayout::FieldRole, mTavLineEdit);

        ampLabel = new QLabel(formLayoutWidget);
        ampLabel->setObjectName(QStringLiteral("ampLabel"));

        stationDataFormLayout->setWidget(7, QFormLayout::LabelRole, ampLabel);

        mAmpLineEdit = new QLineEdit(formLayoutWidget);
        mAmpLineEdit->setObjectName(QStringLiteral("mAmpLineEdit"));

        stationDataFormLayout->setWidget(7, QFormLayout::FieldRole, mAmpLineEdit);

        tmhtLabel = new QLabel(formLayoutWidget);
        tmhtLabel->setObjectName(QStringLiteral("tmhtLabel"));

        stationDataFormLayout->setWidget(8, QFormLayout::LabelRole, tmhtLabel);

        mTmhtLineEdit = new QLineEdit(formLayoutWidget);
        mTmhtLineEdit->setObjectName(QStringLiteral("mTmhtLineEdit"));

        stationDataFormLayout->setWidget(8, QFormLayout::FieldRole, mTmhtLineEdit);

        wmhtLabel = new QLabel(formLayoutWidget);
        wmhtLabel->setObjectName(QStringLiteral("wmhtLabel"));

        stationDataFormLayout->setWidget(9, QFormLayout::LabelRole, wmhtLabel);

        mWmhtLineEdit = new QLineEdit(formLayoutWidget);
        mWmhtLineEdit->setObjectName(QStringLiteral("mWmhtLineEdit"));

        stationDataFormLayout->setWidget(9, QFormLayout::FieldRole, mWmhtLineEdit);

        dwGroupBox = new QGroupBox(centralWidget);
        dwGroupBox->setObjectName(QStringLiteral("dwGroupBox"));
        dwGroupBox->setGeometry(QRect(0, 390, 801, 491));
        formLayoutWidget_2 = new QWidget(dwGroupBox);
        formLayoutWidget_2->setObjectName(QStringLiteral("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(10, 30, 261, 31));
        yearFormLayout = new QFormLayout(formLayoutWidget_2);
        yearFormLayout->setSpacing(6);
        yearFormLayout->setContentsMargins(11, 11, 11, 11);
        yearFormLayout->setObjectName(QStringLiteral("yearFormLayout"));
        yearFormLayout->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        yearFormLayout->setContentsMargins(0, 0, 0, 0);
        yearLabel = new QLabel(formLayoutWidget_2);
        yearLabel->setObjectName(QStringLiteral("yearLabel"));

        yearFormLayout->setWidget(0, QFormLayout::LabelRole, yearLabel);

        mYearCombobox = new QComboBox(formLayoutWidget_2);
        mYearCombobox->setObjectName(QStringLiteral("mYearCombobox"));

        yearFormLayout->setWidget(0, QFormLayout::FieldRole, mYearCombobox);

        mDailyWeatherView = new QTableView(dwGroupBox);
        mDailyWeatherView->setObjectName(QStringLiteral("mDailyWeatherView"));
        mDailyWeatherView->setGeometry(QRect(10, 70, 781, 411));
        mDailyWeatherView->setAlternatingRowColors(true);
        mDailyWeatherView->verticalHeader()->setVisible(false);
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(24, 40, 421, 26));
        splitter->setOrientation(Qt::Horizontal);
        stationLabel = new QLabel(splitter);
        stationLabel->setObjectName(QStringLiteral("stationLabel"));
        splitter->addWidget(stationLabel);
        mStationCombobox = new QComboBox(splitter);
        mStationCombobox->setObjectName(QStringLiteral("mStationCombobox"));
        splitter->addWidget(mStationCombobox);
        WDB->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(WDB);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 923, 22));
        WDB->setMenuBar(menuBar);
        mainToolBar = new QToolBar(WDB);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        WDB->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(WDB);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        WDB->setStatusBar(statusBar);

        retranslateUi(WDB);

        QMetaObject::connectSlotsByName(WDB);
    } // setupUi

    void retranslateUi(QMainWindow *WDB)
    {
        WDB->setWindowTitle(QApplication::translate("WDB", "WEATHER", 0));
        statGroupBox->setTitle(QApplication::translate("WDB", "Station Information", 0));
        statIDLabel->setText(QApplication::translate("WDB", "Station ID:", 0));
        statNameLabel->setText(QApplication::translate("WDB", "Station Name:", 0));
        placeLabel->setText(QApplication::translate("WDB", "Place Name:", 0));
        latLabel->setText(QApplication::translate("WDB", "Lat:", 0));
        longLabel->setText(QApplication::translate("WDB", "Long:", 0));
        elevLabel->setText(QApplication::translate("WDB", "Elev:", 0));
        tavLabel->setText(QApplication::translate("WDB", "Tav:", 0));
        ampLabel->setText(QApplication::translate("WDB", "Amp:", 0));
        tmhtLabel->setText(QApplication::translate("WDB", "Tmht:", 0));
        wmhtLabel->setText(QApplication::translate("WDB", "Wmht:", 0));
        dwGroupBox->setTitle(QApplication::translate("WDB", "Daily Weather", 0));
        yearLabel->setText(QApplication::translate("WDB", "Choose Year:", 0));
        stationLabel->setText(QApplication::translate("WDB", "Choose a Station:", 0));
    } // retranslateUi

};

namespace Ui {
    class WDB: public Ui_WDB {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WDB_H
