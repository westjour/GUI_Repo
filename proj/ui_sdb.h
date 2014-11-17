/********************************************************************************
** Form generated from reading UI file 'sdb.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SDB_H
#define UI_SDB_H

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
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SDB
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *sldescLineEdit;
    QLineEdit *slsourLineEdit;
    QLineEdit *sltxLineEdit;
    QLineEdit *sldpLineEdit;
    QLineEdit *scountLineEdit;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *slatLineEdit;
    QLineEdit *slongLineEdit;
    QLineEdit *taconLineEdit;
    QLineEdit *scomLineEdit;
    QLabel *label_10;
    QLabel *label_11;
    QLineEdit *salbLineEdit;
    QLineEdit *uLineEdit;
    QLabel *label_12;
    QComboBox *soilCombobox;
    QLabel *label_13;
    QLineEdit *ssiteLineEdit;
    QLabel *label_14;
    QLineEdit *SWCONLineEdit;
    QLabel *label_15;
    QLineEdit *CN2LineEdit;
    QLineEdit *slpfLineEdit;
    QLineEdit *slnfLineEdit;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *smhbLabel;
    QLineEdit *smhbLineEdit;
    QLabel *smpxLabel;
    QLineEdit *smpxLineEdit;
    QLabel *smkeLabel;
    QLineEdit *smkeLineEdit;
    QLabel *pondMaxLabel;
    QLineEdit *pondMaxLineEdit;
    QGroupBox *groupBox_2;
    QTableView *soilLayerView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SDB)
    {
        if (SDB->objectName().isEmpty())
            SDB->setObjectName(QStringLiteral("SDB"));
        SDB->resize(843, 959);
        centralwidget = new QWidget(SDB);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 411, 331));
        scrollArea = new QScrollArea(groupBox);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(10, 20, 341, 301));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 339, 666));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        label_2 = new QLabel(scrollAreaWidgetContents);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(scrollAreaWidgetContents);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(scrollAreaWidgetContents);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_4);

        label_5 = new QLabel(scrollAreaWidgetContents);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_5);

        sldescLineEdit = new QLineEdit(scrollAreaWidgetContents);
        sldescLineEdit->setObjectName(QStringLiteral("sldescLineEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, sldescLineEdit);

        slsourLineEdit = new QLineEdit(scrollAreaWidgetContents);
        slsourLineEdit->setObjectName(QStringLiteral("slsourLineEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, slsourLineEdit);

        sltxLineEdit = new QLineEdit(scrollAreaWidgetContents);
        sltxLineEdit->setObjectName(QStringLiteral("sltxLineEdit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, sltxLineEdit);

        sldpLineEdit = new QLineEdit(scrollAreaWidgetContents);
        sldpLineEdit->setObjectName(QStringLiteral("sldpLineEdit"));

        formLayout->setWidget(4, QFormLayout::FieldRole, sldpLineEdit);

        scountLineEdit = new QLineEdit(scrollAreaWidgetContents);
        scountLineEdit->setObjectName(QStringLiteral("scountLineEdit"));

        formLayout->setWidget(6, QFormLayout::FieldRole, scountLineEdit);

        label_6 = new QLabel(scrollAreaWidgetContents);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_6);

        label_7 = new QLabel(scrollAreaWidgetContents);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout->setWidget(8, QFormLayout::LabelRole, label_7);

        label_8 = new QLabel(scrollAreaWidgetContents);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout->setWidget(9, QFormLayout::LabelRole, label_8);

        label_9 = new QLabel(scrollAreaWidgetContents);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout->setWidget(10, QFormLayout::LabelRole, label_9);

        slatLineEdit = new QLineEdit(scrollAreaWidgetContents);
        slatLineEdit->setObjectName(QStringLiteral("slatLineEdit"));

        formLayout->setWidget(7, QFormLayout::FieldRole, slatLineEdit);

        slongLineEdit = new QLineEdit(scrollAreaWidgetContents);
        slongLineEdit->setObjectName(QStringLiteral("slongLineEdit"));

        formLayout->setWidget(8, QFormLayout::FieldRole, slongLineEdit);

        taconLineEdit = new QLineEdit(scrollAreaWidgetContents);
        taconLineEdit->setObjectName(QStringLiteral("taconLineEdit"));

        formLayout->setWidget(9, QFormLayout::FieldRole, taconLineEdit);

        scomLineEdit = new QLineEdit(scrollAreaWidgetContents);
        scomLineEdit->setObjectName(QStringLiteral("scomLineEdit"));

        formLayout->setWidget(10, QFormLayout::FieldRole, scomLineEdit);

        label_10 = new QLabel(scrollAreaWidgetContents);
        label_10->setObjectName(QStringLiteral("label_10"));

        formLayout->setWidget(11, QFormLayout::LabelRole, label_10);

        label_11 = new QLabel(scrollAreaWidgetContents);
        label_11->setObjectName(QStringLiteral("label_11"));

        formLayout->setWidget(12, QFormLayout::LabelRole, label_11);

        salbLineEdit = new QLineEdit(scrollAreaWidgetContents);
        salbLineEdit->setObjectName(QStringLiteral("salbLineEdit"));

        formLayout->setWidget(11, QFormLayout::FieldRole, salbLineEdit);

        uLineEdit = new QLineEdit(scrollAreaWidgetContents);
        uLineEdit->setObjectName(QStringLiteral("uLineEdit"));

        formLayout->setWidget(12, QFormLayout::FieldRole, uLineEdit);

        label_12 = new QLabel(scrollAreaWidgetContents);
        label_12->setObjectName(QStringLiteral("label_12"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_12);

        soilCombobox = new QComboBox(scrollAreaWidgetContents);
        soilCombobox->setObjectName(QStringLiteral("soilCombobox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, soilCombobox);

        label_13 = new QLabel(scrollAreaWidgetContents);
        label_13->setObjectName(QStringLiteral("label_13"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_13);

        ssiteLineEdit = new QLineEdit(scrollAreaWidgetContents);
        ssiteLineEdit->setObjectName(QStringLiteral("ssiteLineEdit"));

        formLayout->setWidget(5, QFormLayout::FieldRole, ssiteLineEdit);

        label_14 = new QLabel(scrollAreaWidgetContents);
        label_14->setObjectName(QStringLiteral("label_14"));

        formLayout->setWidget(13, QFormLayout::LabelRole, label_14);

        SWCONLineEdit = new QLineEdit(scrollAreaWidgetContents);
        SWCONLineEdit->setObjectName(QStringLiteral("SWCONLineEdit"));

        formLayout->setWidget(13, QFormLayout::FieldRole, SWCONLineEdit);

        label_15 = new QLabel(scrollAreaWidgetContents);
        label_15->setObjectName(QStringLiteral("label_15"));

        formLayout->setWidget(14, QFormLayout::LabelRole, label_15);

        CN2LineEdit = new QLineEdit(scrollAreaWidgetContents);
        CN2LineEdit->setObjectName(QStringLiteral("CN2LineEdit"));

        formLayout->setWidget(14, QFormLayout::FieldRole, CN2LineEdit);

        slpfLineEdit = new QLineEdit(scrollAreaWidgetContents);
        slpfLineEdit->setObjectName(QStringLiteral("slpfLineEdit"));

        formLayout->setWidget(16, QFormLayout::FieldRole, slpfLineEdit);

        slnfLineEdit = new QLineEdit(scrollAreaWidgetContents);
        slnfLineEdit->setObjectName(QStringLiteral("slnfLineEdit"));

        formLayout->setWidget(15, QFormLayout::FieldRole, slnfLineEdit);

        label_16 = new QLabel(scrollAreaWidgetContents);
        label_16->setObjectName(QStringLiteral("label_16"));

        formLayout->setWidget(15, QFormLayout::LabelRole, label_16);

        label_17 = new QLabel(scrollAreaWidgetContents);
        label_17->setObjectName(QStringLiteral("label_17"));

        formLayout->setWidget(16, QFormLayout::LabelRole, label_17);

        smhbLabel = new QLabel(scrollAreaWidgetContents);
        smhbLabel->setObjectName(QStringLiteral("smhbLabel"));

        formLayout->setWidget(17, QFormLayout::LabelRole, smhbLabel);

        smhbLineEdit = new QLineEdit(scrollAreaWidgetContents);
        smhbLineEdit->setObjectName(QStringLiteral("smhbLineEdit"));

        formLayout->setWidget(17, QFormLayout::FieldRole, smhbLineEdit);

        smpxLabel = new QLabel(scrollAreaWidgetContents);
        smpxLabel->setObjectName(QStringLiteral("smpxLabel"));

        formLayout->setWidget(18, QFormLayout::LabelRole, smpxLabel);

        smpxLineEdit = new QLineEdit(scrollAreaWidgetContents);
        smpxLineEdit->setObjectName(QStringLiteral("smpxLineEdit"));

        formLayout->setWidget(18, QFormLayout::FieldRole, smpxLineEdit);

        smkeLabel = new QLabel(scrollAreaWidgetContents);
        smkeLabel->setObjectName(QStringLiteral("smkeLabel"));

        formLayout->setWidget(19, QFormLayout::LabelRole, smkeLabel);

        smkeLineEdit = new QLineEdit(scrollAreaWidgetContents);
        smkeLineEdit->setObjectName(QStringLiteral("smkeLineEdit"));

        formLayout->setWidget(19, QFormLayout::FieldRole, smkeLineEdit);

        pondMaxLabel = new QLabel(scrollAreaWidgetContents);
        pondMaxLabel->setObjectName(QStringLiteral("pondMaxLabel"));

        formLayout->setWidget(20, QFormLayout::LabelRole, pondMaxLabel);

        pondMaxLineEdit = new QLineEdit(scrollAreaWidgetContents);
        pondMaxLineEdit->setObjectName(QStringLiteral("pondMaxLineEdit"));

        formLayout->setWidget(20, QFormLayout::FieldRole, pondMaxLineEdit);


        verticalLayout->addLayout(formLayout);

        scrollArea->setWidget(scrollAreaWidgetContents);
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 350, 811, 511));
        soilLayerView = new QTableView(groupBox_2);
        soilLayerView->setObjectName(QStringLiteral("soilLayerView"));
        soilLayerView->setGeometry(QRect(10, 30, 791, 471));
        soilLayerView->verticalHeader()->setVisible(false);
        SDB->setCentralWidget(centralwidget);
        groupBox_2->raise();
        groupBox->raise();
        menubar = new QMenuBar(SDB);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 843, 22));
        SDB->setMenuBar(menubar);
        statusbar = new QStatusBar(SDB);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        SDB->setStatusBar(statusbar);

        retranslateUi(SDB);

        QMetaObject::connectSlotsByName(SDB);
    } // setupUi

    void retranslateUi(QMainWindow *SDB)
    {
        SDB->setWindowTitle(QApplication::translate("SDB", "SOIL", 0));
        groupBox->setTitle(QApplication::translate("SDB", "Soil Information", 0));
        label->setText(QApplication::translate("SDB", "SlDesc", 0));
        label_2->setText(QApplication::translate("SDB", "Slsour", 0));
        label_3->setText(QApplication::translate("SDB", "Sltx", 0));
        label_4->setText(QApplication::translate("SDB", "Sldp", 0));
        label_5->setText(QApplication::translate("SDB", "SCount", 0));
        label_6->setText(QApplication::translate("SDB", "SLat", 0));
        label_7->setText(QApplication::translate("SDB", "SLong", 0));
        label_8->setText(QApplication::translate("SDB", "Tacon", 0));
        label_9->setText(QApplication::translate("SDB", "Scom", 0));
        label_10->setText(QApplication::translate("SDB", "Salb", 0));
        label_11->setText(QApplication::translate("SDB", "U", 0));
        label_12->setText(QApplication::translate("SDB", "Choose a Soil:", 0));
        label_13->setText(QApplication::translate("SDB", "SSite", 0));
        label_14->setText(QApplication::translate("SDB", "SWCON", 0));
        label_15->setText(QApplication::translate("SDB", "CN2", 0));
        label_16->setText(QApplication::translate("SDB", "Slnf", 0));
        label_17->setText(QApplication::translate("SDB", "Slpf", 0));
        smhbLabel->setText(QApplication::translate("SDB", "Smhb", 0));
        smpxLabel->setText(QApplication::translate("SDB", "Smpx", 0));
        smkeLabel->setText(QApplication::translate("SDB", "Smke", 0));
        pondMaxLabel->setText(QApplication::translate("SDB", "PondMax", 0));
        groupBox_2->setTitle(QApplication::translate("SDB", "Layers", 0));
    } // retranslateUi

};

namespace Ui {
    class SDB: public Ui_SDB {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SDB_H
