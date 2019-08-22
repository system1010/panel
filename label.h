#ifndef LABEL_H
#define LABEL_H
#include <QLabel>
#include <QProcess>

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
        QProcess process1;
        process1.start("date");
        process1.waitForFinished();
        QString output1(process1.readAllStandardOutput());
        setText(output1);
        }
     }
};

#endif // LABEL_H



