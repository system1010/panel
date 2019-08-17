#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "nativeeventfilter.h"
#include <QLabel>
#include <QProcess>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void slotGlobalHotkey();

    void slotButton();

    void slotButton1();

    void slotButton2();

    void slotButton3();

private:
    Ui::MainWindow *ui;
    NativeEventFilter *nativeEventFilter;
};

class BlinkLabel : public QLabel {
private:
    bool    m_bBlink;
    QString m_strText;

protected:
    virtual void timerEvent(QTimerEvent*)
    {
        QProcess process;
        process.start("cat /sys/class/power_supply/BAT0/capacity");
        process.waitForFinished();
        QString output(process.readAllStandardOutput());
        //m_bBlink = !m_bBlink;
        setText(output);
    }

public:
    BlinkLabel(const QString& strText,
                     int      nInterval = 1000,
                     QWidget* pwgt      = 0
              )
        : QLabel(strText, pwgt)
        , m_bBlink(true)
        , m_strText(strText)
    {
        startTimer(nInterval);
    }
};

class BlinkLabel1 : public QLabel {
private:
    bool    m_bBlink;
    QString m_strText;

protected:
    virtual void timerEvent(QTimerEvent*)
    {
        QProcess process;
        process.start("date");
        process.waitForFinished();
        QString output(process.readAllStandardOutput());
        //m_bBlink = !m_bBlink;
        setText(output);
    }

public:
    BlinkLabel1(const QString& strText,
                     int      nInterval = 1000,
                     QWidget* pwgt      = 0
              )
        : QLabel(strText, pwgt)
        , m_bBlink(true)
        , m_strText(strText)
    {
        startTimer(nInterval);
    }
};

#endif // MAINWINDOW_H
