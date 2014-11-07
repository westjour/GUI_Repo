#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H

#include <QMainWindow>

class CTableView;
class QComboBox;
class QLineEdit;
class CStation;

/* Forward declaration this class so that we can use it as a
member variable. It is actually defined in ui_mainWindow.h */
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
    

public slots:
    void stationIndexChanged(QString text);
    void yearIndexChanged(QString text);
    void onFileSave();
    void onFileOpen();
    void onStationDataChanged(QString field);

private:
    void buildMenuBar();
    void buildMacMenuBar();
    void saveXML();
    void makeConnections();
    void disableStationDataLineEdits();
    void enableStationDataLineEdits();
    
    //
    // GUI Elements
    //
    Ui::MainWindow* ui;
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
    
    QMenuBar* macMenuBar;
    QAction* mFileSave;
    QAction* mFileOpen;
    QAction* mFileExit;
    
    CTableView* mDailyWeatherView;
    CTableView* mHrWeatherView;
};

#endif // CMAINWINDOW_H
