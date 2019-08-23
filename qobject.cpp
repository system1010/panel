#include "qobject.h"
#include <QDebug>
#include <QProcess>
void slotGlobalHotkey();
qobject::qobject(QObject *parent) : QObject(parent)
{
    nativeEventFilter = new NativeEventFilter(this);    // Инициализируем фильтр
    qApp->installNativeEventFilter(nativeEventFilter);  // Устанавилваем его на приложение
    // подключаем сигнал фильтра к слоту
    QObject::connect(nativeEventFilter, &NativeEventFilter::activated, slotGlobalHotkey);
    nativeEventFilter->setShortcut();   // Устанавилваем хоткей

}
void slotGlobalHotkey()
{
    // И сообщаем пользователю, если он нажал нужный нам HotKey
    QProcess process;
    process.startDetached("xterm");
    qDebug() << "test";
}
