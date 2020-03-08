#ifndef LABEL_H
#define LABEL_H
#include <QLabel>
#include <QProcess>
#include <QTime>
//#include <QSysInfo>
class label : public QLabel
{
public:
    label();
protected:
    virtual void timerEvent(QTimerEvent*)
    {
        if (objectName()=="lbl"){
        QProcess process;
        process.start("cat /sys/class/power_supply/BAT0/capacity");
        process.waitForFinished();
        QString output(process.readAllStandardOutput());
        setText(output);
        //QSystemDeviceInfo *deviceInfo = new QSystemDeviceInfo(this);
        //setText(deviceInfo->batteryLevel());
        if (text().toInt()<10)setStyleSheet("border-image:url(/media/sda3/usr/bin/battery-empty-icon.png)");
        if (text().toInt()>90)setStyleSheet("border-image:url(/media/sda3/usr/bin/battery-charged-icon.png)");
        if (text().toInt()<20&&text().toInt()>10)setStyleSheet("border-image:url(/media/sda3/usr/bin/battery-1-icon.png)");
        if (text().toInt()<30&&text().toInt()>20)setStyleSheet("border-image:url(/media/sda3/usr/bin/battery-2-icon.png)");
        if (text().toInt()<90&&text().toInt()>30)setStyleSheet("border-image:url(/media/sda3/usr/bin/battery-3-icon.png)");
        }else if (objectName()=="lbl1"){
        setText(QTime::currentTime().toString("hh:mm:ss"));
        }
     }
};

#endif // LABEL_H



