#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "nativeeventfilter.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void slotGlobalHotkey();

private:
    Ui::MainWindow *ui;
    NativeEventFilter *nativeEventFilter;
};

#endif // MAINWINDOW_H
