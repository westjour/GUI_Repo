#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H

#include <QMainWindow>
#include <QVector>

class CDailyWeatherView;
class QComboBox;
class QLineEdit;
class CStation;

namespace Ui {
class MainWindow;
}

class CMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CMainWindow(QWidget *parent = 0);
    ~CMainWindow();

    void clearStationLineEdits();
    void makeConnections();
    
public slots:
    void stationIndexChanged(QString text);
    void yearIndexChanged(QString text);

private:
    //
    // GUI Elements
    //
    Ui::MainWindow *ui;
    QComboBox* mStationCombobox;
    QComboBox* mYearCombobox;
    QLineEdit* mStatNameLineEdit;
    QLineEdit* mStatIDLineEdit;
    QLineEdit* mPlaceNameLineEdit;
    QLineEdit* mLatLineEdit;
    QLineEdit* mLongLineEdit;
    QLineEdit* mElevLineEdit;
    QLineEdit* mTavLineEdit;
    QLineEdit* mAmpLineEdit;
    QLineEdit* mTmhtLineEdit;
    QLineEdit* mWmhtLineEdit;

    CDailyWeatherView* mDailyWeatherView;
};

#endif // CMAINWINDOW_H
