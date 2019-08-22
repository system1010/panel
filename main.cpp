#include "mainwindow.h"
#include <QApplication>
#include "label.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    label lbl;
    lbl.setGeometry(1200,755,40,23);
    lbl.setObjectName("lbl");
    lbl.show();
    label lbl1;
    lbl1.setGeometry(1245,755,150,23);
    lbl1.setObjectName("lbl1");
    lbl1.show();
    return a.exec();
}
