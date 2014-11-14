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
    QLabel *stationLabel;
    QComboBox *mStationCombobox;
    QLabel *statIDLabel;
    QLineEdit *mStatIDLineEdit;
    QLabel *statNameLabel;
    QLineEdit *mStatNameLineEdit;
    QLabel *placeLabel;
    QLabel *latLabel;
    QLineEdit *mPlaceNameLineEdit;
    QLineEdit *mLatLineEdit;
    QLabel *longLabel;
    QLabel *elevLabel;
    QLabel *tavLabel;
    QLabel *ampLabel;
    QLineEdit *mLongLineEdit;
    QLineEdit *mElevLineEdit;
    QLineEdit *mTavLineEdit;
    QLineEdit *mAmpLineEdit;
    QLabel *tmhtLabel;
    QLabel *wmhtLabel;
    QLineEdit *mTmhtLineEdit;
    QLineEdit *mWmhtLineEdit;
    QGroupBox *dwGroupBox;
    QWidget *formLayoutWidget_2;
    QFormLayout *yearFormLayout;
    QLabel *yearLabel;
    QComboBox *mYearCombobox;
    QTableView *mDailyWeatherView;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *WDB)
    {
        if (WDB->objectName().isEmpty())
            WDB->setObjectName(QStringLiteral("WDB"));
        WDB->resize(879, 1118);
        centralWidget = new QWidget(WDB);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        statGroupBox = new QGroupBox(centralWidget);
        statGroupBox->setObjectName(QStringLiteral("statGroupBox"));
        statGroupBox->setGeometry(QRect(10, 10, 801, 381));
        formLayoutWidget = new QWidget(statGroupBox);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(20, 30, 381, 341));
        stationDataFormLayout = new QFormLayout(formLayoutWidget);
        stationDataFormLayout->setSpacing(6);
        stationDataFormLayout->setContentsMargins(11, 11, 11, 11);
        stationDataFormLayout->setObjectName(QStringLiteral("stationDataFormLayout"));
        stationDataFormLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        stationDataFormLayout->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        stationDataFormLayout->setContentsMargins(0, 0, 0, 0);
        stationLabel = new QLabel(formLayoutWidget);
        stationLabel->setObjectName(QStringLiteral("stationLabel"));

        stationDataFormLayout->setWidget(0, QFormLayout::LabelRole, stationLabel);

        mStationCombobox = new QComboBox(formLayoutWidget);
        mStationCombobox->setObjectName(QStringLiteral("mStationCombobox"));

        stationDataFormLayout->setWidget(0, QFormLayout::FieldRole, mStationCombobox);

        statIDLabel = new QLabel(formLayoutWidget);
        statIDLabel->setObjectName(QStringLiteral("statIDLabel"));

        stationDataFormLayout->setWidget(1, QFormLayout::LabelRole, statIDLabel);

        mStatIDLineEdit = new QLineEdit(formLayoutWidget);
        mStatIDLineEdit->setObjectName(QStringLiteral("mStatIDLineEdit"));

        stationDataFormLayout->setWidget(1, QFormLayout::FieldRole, mStatIDLineEdit);

        statNameLabel = new QLabel(formLayoutWidget);
        statNameLabel->setObjectName(QStringLiteral("statNameLabel"));

        stationDataFormLayout->setWidget(2, QFormLayout::LabelRole, statNameLabel);

        mStatNameLineEdit = new QLineEdit(formLayoutWidget);
        mStatNameLineEdit->setObjectName(QStringLiteral("mStatNameLineEdit"));

        stationDataFormLayout->setWidget(2, QFormLayout::FieldRole, mStatNameLineEdit);

        placeLabel = new QLabel(formLayoutWidget);
        placeLabel->setObjectName(QStringLiteral("placeLabel"));

        stationDataFormLayout->setWidget(3, QFormLayout::LabelRole, placeLabel);

        latLabel = new QLabel(formLayoutWidget);
        latLabel->setObjectName(QStringLiteral("latLabel"));

        stationDataFormLayout->setWidget(4, QFormLayout::LabelRole, latLabel);

        mPlaceNameLineEdit = new QLineEdit(formLayoutWidget);
        mPlaceNameLineEdit->setObjectName(QStringLiteral("mPlaceNameLineEdit"));

        stationDataFormLayout->setWidget(3, QFormLayout::FieldRole, mPlaceNameLineEdit);

        mLatLineEdit = new QLineEdit(formLayoutWidget);
        mLatLineEdit->setObjectName(QStringLiteral("mLatLineEdit"));

        stationDataFormLayout->setWidget(4, QFormLayout::FieldRole, mLatLineEdit);

        longLabel = new QLabel(formLayoutWidget);
        longLabel->setObjectName(QStringLiteral("longLabel"));

        stationDataFormLayout->setWidget(5, QFormLayout::LabelRole, longLabel);

        elevLabel = new QLabel(formLayoutWidget);
        elevLabel->setObjectName(QStringLiteral("elevLabel"));

        stationDataFormLayout->setWidget(6, QFormLayout::LabelRole, elevLabel);

        tavLabel = new QLabel(formLayoutWidget);
        tavLabel->setObjectName(QStringLiteral("tavLabel"));

        stationDataFormLayout->setWidget(7, QFormLayout::LabelRole, tavLabel);

        ampLabel = new QLabel(formLayoutWidget);
        ampLabel->setObjectName(QStringLiteral("ampLabel"));

        stationDataFormLayout->setWidget(8, QFormLayout::LabelRole, ampLabel);

        mLongLineEdit = new QLineEdit(formLayoutWidget);
        mLongLineEdit->setObjectName(QStringLiteral("mLongLineEdit"));

        stationDataFormLayout->setWidget(5, QFormLayout::FieldRole, mLongLineEdit);

        mElevLineEdit = new QLineEdit(formLayoutWidget);
        mElevLineEdit->setObjectName(QStringLiteral("mElevLineEdit"));

        stationDataFormLayout->setWidget(6, QFormLayout::FieldRole, mElevLineEdit);

        mTavLineEdit = new QLineEdit(formLayoutWidget);
        mTavLineEdit->setObjectName(QStringLiteral("mTavLineEdit"));

        stationDataFormLayout->setWidget(7, QFormLayout::FieldRole, mTavLineEdit);

        mAmpLineEdit = new QLineEdit(formLayoutWidget);
        mAmpLineEdit->setObjectName(QStringLiteral("mAmpLineEdit"));

        stationDataFormLayout->setWidget(8, QFormLayout::FieldRole, mAmpLineEdit);

        tmhtLabel = new QLabel(formLayoutWidget);
        tmhtLabel->setObjectName(QStringLiteral("tmhtLabel"));

        stationDataFormLayout->setWidget(9, QFormLayout::LabelRole, tmhtLabel);

        wmhtLabel = new QLabel(formLayoutWidget);
        wmhtLabel->setObjectName(QStringLiteral("wmhtLabel"));

        stationDataFormLayout->setWidget(10, QFormLayout::LabelRole, wmhtLabel);

        mTmhtLineEdit = new QLineEdit(formLayoutWidget);
        mTmhtLineEdit->setObjectName(QStringLiteral("mTmhtLineEdit"));

        stationDataFormLayout->setWidget(9, QFormLayout::FieldRole, mTmhtLineEdit);

        mWmhtLineEdit = new QLineEdit(formLayoutWidget);
        mWmhtLineEdit->setObjectName(QStringLiteral("mWmhtLineEdit"));

        stationDataFormLayout->setWidget(10, QFormLayout::FieldRole, mWmhtLineEdit);

        dwGroupBox = new QGroupBox(centralWidget);
        dwGroupBox->setObjectName(QStringLiteral("dwGroupBox"));
        dwGroupBox->setGeometry(QRect(10, 410, 801, 491));
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
        WDB->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(WDB);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 879, 22));
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
        stationLabel->setText(QApplication::translate("WDB", "Choose a Station:", 0));
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
    } // retranslateUi

};

namespace Ui {
    class WDB: public Ui_WDB {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WDB_H
