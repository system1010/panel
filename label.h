#ifndef LABEL_H
#define LABEL_H
#include <QLabel>
#include <QProcess>
#include <QTime>
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
        }else if (objectName()=="lbl1"){
        setText(QTime::currentTime().toString("hh:mm:ss"));
        }
     }
};

#endif // LABEL_H



