#include <QApplication>
#include "nativeeventfilter.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NativeEventFilter *nativeEventFilter = new NativeEventFilter;
    a.installNativeEventFilter(nativeEventFilter); 
    return a.exec();

}

