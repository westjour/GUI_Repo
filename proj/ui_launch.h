/********************************************************************************
** Form generated from reading UI file 'launch.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAUNCH_H
#define UI_LAUNCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LaunchForm
{
public:
    QLabel *label;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButtonOpen;
    QPushButton *pushButton_newSDB;
    QPushButton *pushButton_newWDB;
    QPushButton *pushButton_newXDB;
    QPushButton *pushButton_newCDB;

    void setupUi(QWidget *LaunchForm)
    {
        if (LaunchForm->objectName().isEmpty())
            LaunchForm->setObjectName(QStringLiteral("LaunchForm"));
        LaunchForm->resize(483, 344);
        label = new QLabel(LaunchForm);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 30, 221, 31));
        QFont font;
        font.setPointSize(19);
        label->setFont(font);
        layoutWidget = new QWidget(LaunchForm);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 90, 207, 168));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonOpen = new QPushButton(layoutWidget);
        pushButtonOpen->setObjectName(QStringLiteral("pushButtonOpen"));

        verticalLayout->addWidget(pushButtonOpen);

        pushButton_newSDB = new QPushButton(layoutWidget);
        pushButton_newSDB->setObjectName(QStringLiteral("pushButton_newSDB"));

        verticalLayout->addWidget(pushButton_newSDB);

        pushButton_newWDB = new QPushButton(layoutWidget);
        pushButton_newWDB->setObjectName(QStringLiteral("pushButton_newWDB"));

        verticalLayout->addWidget(pushButton_newWDB);

        pushButton_newXDB = new QPushButton(layoutWidget);
        pushButton_newXDB->setObjectName(QStringLiteral("pushButton_newXDB"));

        verticalLayout->addWidget(pushButton_newXDB);

        pushButton_newCDB = new QPushButton(layoutWidget);
        pushButton_newCDB->setObjectName(QStringLiteral("pushButton_newCDB"));

        verticalLayout->addWidget(pushButton_newCDB);


        retranslateUi(LaunchForm);

        QMetaObject::connectSlotsByName(LaunchForm);
    } // setupUi

    void retranslateUi(QWidget *LaunchForm)
    {
        LaunchForm->setWindowTitle(QApplication::translate("LaunchForm", "XML Editor - Home", 0));
        label->setText(QApplication::translate("LaunchForm", "<html><head/><body><p><span style=\" color:#006600;\">Welcome/Splash Screen</span></p></body></html>", 0));
        pushButtonOpen->setText(QApplication::translate("LaunchForm", "Open...", 0));
        pushButton_newSDB->setText(QApplication::translate("LaunchForm", "New Soil (SDB) File", 0));
        pushButton_newWDB->setText(QApplication::translate("LaunchForm", "New Weather (WDB) File", 0));
        pushButton_newXDB->setText(QApplication::translate("LaunchForm", "New Experiment (XDB) File", 0));
        pushButton_newCDB->setText(QApplication::translate("LaunchForm", "New Crop (CDB) File", 0));
    } // retranslateUi

};

namespace Ui {
    class LaunchForm: public Ui_LaunchForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAUNCH_H
