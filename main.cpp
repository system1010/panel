#include <QApplication>
#include "label.h"
#include "button.h"
#include "qobject.h"
#include <QProcess>
void slotButton1();
void slotButton2();
void slotButton3();
void slotButton4();
void slotButton5();
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    label lbl;
    lbl.setGeometry(1200,755,40,23);
    lbl.setObjectName("lbl");
    lbl.show();
    label lbl1;
    lbl1.setGeometry(1245,755,150,23);
    lbl1.setObjectName("lbl1");
    lbl1.show();
    button button1;
    button1.show();
    button1.setText("Browser");
    button1.setGeometry(10,10,80,23);
    QObject::connect(&button1, &button::clicked, slotButton1);
    button button2;
    button2.show();
    button2.setText("Terminal");
    button2.setGeometry(10,35,80,23);
    QObject::connect(&button2, &button::clicked, slotButton2);
    button button3;
    button3.show();
    button3.setText("QtCreator");
    button3.setGeometry(10,60,80,23);
    QObject::connect(&button3, &button::clicked, slotButton3);
    button button4;
    button4.show();
    button4.setText("Off");
    button4.setGeometry(10,110,80,23);
    QObject::connect(&button4, &button::clicked, slotButton4);
    button button5;
    button5.show();
    button5.setText("Colobot");
    button5.setGeometry(10,85,80,23);
    QObject::connect(&button5, &button::clicked, slotButton5);
    qobject o;
    QProcess process;
    process.startDetached("tinywm");
    return a.exec();

}

void slotButton1()
{
    QProcess process;
    process.startDetached("quicknanobrowser");
}
void slotButton2()
{
    QProcess process;
    process.startDetached("minimal-term -geometry 400x500-1+1");
}
void slotButton3()
{
    QProcess process;
    process.startDetached("/opt/Qt5.9.8/Tools/QtCreator/bin/qtcreator");
}
void slotButton4()
{
    QProcess process;
    process.startDetached("init 0");
}
void slotButton5(){
    QProcess process;
    process.startDetached("colobot");
}
