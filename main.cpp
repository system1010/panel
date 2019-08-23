#include <QApplication>
#include "label.h"
#include "button.h"
#include <QProcess>
void slotButton();
void slotButton1();
void slotButton2();
void slotButton3();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    class label lbl;
    lbl.setGeometry(1200,755,40,23);
    lbl.setObjectName("lbl");
    lbl.show();
    class label lbl1;
    lbl1.setGeometry(1245,755,150,23);
    lbl1.setObjectName("lbl1");
    lbl1.show();
    class button button;
    button.show();
    button.setText("Browser");
    button.setGeometry(10,10,80,23);
    QObject::connect(&button, &button::clicked, slotButton);
    class button button1;
    button1.show();
    button1.setText("Terminal");
    button1.setGeometry(10,35,80,23);
    QObject::connect(&button1, &button::clicked, slotButton1);
    class button button2;
    button2.show();
    button2.setText("QtCreator");
    button2.setGeometry(10,60,80,23);
    QObject::connect(&button2, &button::clicked, slotButton2);
    QPushButton* button3 = new QPushButton;
    button3->show();
    button3->setText("Off");
    button3->setGeometry(10,85,80,23);
    QObject::connect(button3, &QPushButton::clicked, slotButton3);
    QProcess process;
    process.startDetached("tinywm");
    return a.exec();

}

void slotButton()
{
    QProcess process;
    process.startDetached("quicknanobrowser");
}
void slotButton1()
{
    QProcess process;
    process.startDetached("minimal-term -geometry 400x500-1+1");
}
void slotButton2()
{
    QProcess process;
    process.startDetached("/opt/Qt5.9.8/Tools/QtCreator/bin/qtcreator");
}
void slotButton3()
{
    QProcess process;
    process.startDetached("init 0");
}
