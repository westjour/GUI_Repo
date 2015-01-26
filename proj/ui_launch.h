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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LaunchForm
{
public:
    QPushButton *pushButtonOpen;
    QLabel *label;
    QPushButton *pushButton_newSDB;
    QPushButton *pushButton_newWDB;
    QPushButton *pushButton_newXDB;
    QPushButton *pushButton_newCDB;

    void setupUi(QWidget *LaunchForm)
    {
        if (LaunchForm->objectName().isEmpty())
            LaunchForm->setObjectName(QStringLiteral("LaunchForm"));
        LaunchForm->resize(483, 344);
        pushButtonOpen = new QPushButton(LaunchForm);
        pushButtonOpen->setObjectName(QStringLiteral("pushButtonOpen"));
        pushButtonOpen->setGeometry(QRect(40, 90, 115, 32));
        label = new QLabel(LaunchForm);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 30, 221, 31));
        QFont font;
        font.setPointSize(19);
        label->setFont(font);
        pushButton_newSDB = new QPushButton(LaunchForm);
        pushButton_newSDB->setObjectName(QStringLiteral("pushButton_newSDB"));
        pushButton_newSDB->setGeometry(QRect(40, 140, 111, 31));
        pushButton_newWDB = new QPushButton(LaunchForm);
        pushButton_newWDB->setObjectName(QStringLiteral("pushButton_newWDB"));
        pushButton_newWDB->setGeometry(QRect(40, 170, 111, 31));
        pushButton_newXDB = new QPushButton(LaunchForm);
        pushButton_newXDB->setObjectName(QStringLiteral("pushButton_newXDB"));
        pushButton_newXDB->setGeometry(QRect(40, 200, 115, 32));
        pushButton_newCDB = new QPushButton(LaunchForm);
        pushButton_newCDB->setObjectName(QStringLiteral("pushButton_newCDB"));
        pushButton_newCDB->setGeometry(QRect(40, 230, 115, 32));

        retranslateUi(LaunchForm);

        QMetaObject::connectSlotsByName(LaunchForm);
    } // setupUi

    void retranslateUi(QWidget *LaunchForm)
    {
        LaunchForm->setWindowTitle(QApplication::translate("LaunchForm", "XML Editor - Home", 0));
        pushButtonOpen->setText(QApplication::translate("LaunchForm", "Open...", 0));
        label->setText(QApplication::translate("LaunchForm", "<html><head/><body><p><span style=\" color:#006600;\">Welcome/Splash Screen</span></p></body></html>", 0));
        pushButton_newSDB->setText(QApplication::translate("LaunchForm", "New SDB", 0));
        pushButton_newWDB->setText(QApplication::translate("LaunchForm", "New WDB", 0));
        pushButton_newXDB->setText(QApplication::translate("LaunchForm", "New XDB", 0));
        pushButton_newCDB->setText(QApplication::translate("LaunchForm", "New CDB", 0));
    } // retranslateUi

};

namespace Ui {
    class LaunchForm: public Ui_LaunchForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAUNCH_H
