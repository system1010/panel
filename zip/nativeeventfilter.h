#ifndef NATIVEEVENTFILTER_H
#define NATIVEEVENTFILTER_H

#include <QObject>
#include <QAbstractNativeEventFilter>

class NativeEventFilter : public QObject, public QAbstractNativeEventFilter
{
    Q_OBJECT
public:
    explicit NativeEventFilter(QObject *parent = 0);

    // переопределяем метод nativeEventFilter
    bool nativeEventFilter(const QByteArray &eventType, void *message, long *result);
    void setShortcut();     // Добавляем метод установки хоткея
    void unsetShortcut();   // и метод удаления хоткея для полноты картины

signals:
    void activated();       // Сигнал активации хоткея

public slots:
};

#endif // NATIVEEVENTFILTER_H
