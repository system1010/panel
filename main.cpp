#include "mainwindow.h"
#include <QApplication>
#include <QtWidgets>
#include <QProcess>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.show();
    BlinkLabel   lbl("<FONT COLOR = RED><CENTER>BAT0</CENTER></FONT>");
    lbl.setGeometry(10,140,80,23);
    lbl.show();
    BlinkLabel1   lbl1("<FONT COLOR = RED><CENTER>DATE</CENTER></FONT>");
    lbl1.setGeometry(-40,170,150,23);
    lbl1.show();
    QProcess process;
    process.startDetached("tinywm");
    return a.exec();
}
