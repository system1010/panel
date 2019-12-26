#include <QApplication>
#include "label.h"
#include "button.h"
#include <QProcess>
#include "nativeeventfilter.h"
#include <QDebug>
#include <QMenu>
void slotButton1();
void slotButton2();
void slotButton3();
void slotButton4();
void slotButton5();
void slotButton6();
void slotGlobalHotkey();
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
    QObject::connect(&button1, &button::clicked, []{QProcess process;
        process.startDetached("WebEngine --no-sandbox");});
    button button2;
    button2.show();
    button2.setText("Terminal");
    button2.setGeometry(10,35,80,23);
    QObject::connect(&button2, &button::clicked, []{QProcess process; process.startDetached("xterm");});
    button button3;
    button3.show();
    button3.setText("QtCreator");
    button3.setGeometry(10,60,80,23);
    QObject::connect(&button3, &button::clicked, []{QProcess process;
        process.startDetached("/opt/Qt5.13.0/Tools/QtCreator/bin/qtcreator");});
    button button4;
    button4.show();
    button4.setText("Off");
    button4.setGeometry(10,110,80,23);
    QObject::connect(&button4, &button::clicked, []{QProcess process;
        process.start("init 0");
        process.waitForFinished();});
    button button5;
    button5.show();
    button5.setText("Colobot");
    button5.setGeometry(10,85,80,23);
    QObject::connect(&button5, &button::clicked, []{QProcess process; process.startDetached("colobot");});

    button button6;
    QMenu menu;
    button6.setMenu(&menu);
    menu.show();
    button6.show();
    button6.setText("Apps");
    button6.setGeometry(10,135,80,23);
    //QObject::connect(&button6, &button::clicked, slotButton6);
    button6.menu()->addAction("test");

    //rocess process;
    //ocess.startDetached("tinywm");
    NativeEventFilter *nativeEventFilter = new NativeEventFilter;    // Инициализируем фильтр
    a.installNativeEventFilter(nativeEventFilter);  // Устанавилваем его на приложение
    // подключаем сигнал фильтра к слоту
    QObject::connect(nativeEventFilter, &NativeEventFilter::activated, slotGlobalHotkey);
    nativeEventFilter->setShortcut();   // Устанавилваем хоткей
    nativeEventFilter->setShortcut1();   // Устанавилваем хоткей
    //QObject::connect(&menu, &QMenu::triggered, slotButton6);
    return a.exec();

}



void slotGlobalHotkey()
{
    // И сообщаем пользователю, если он нажал нужный нам HotKey
    QProcess process;
    process.startDetached("xterm");
    qDebug() << "test";
}

