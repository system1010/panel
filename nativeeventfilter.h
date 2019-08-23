#ifndef NATIVEEVENTFILTER_H
#define NATIVEEVENTFILTER_H

#include <QObject>
#include <QAbstractNativeEventFilter>

class NativeEventFilter : public QObject, public QAbstractNativeEventFilter
{
    Q_OBJECT
public:
    explicit NativeEventFilter(QObject *parent = nullptr);

    bool nativeEventFilter(const QByteArray &eventType, void *message, long *result);
    void setShortcut();
    void unsetShortcut();

signals:
    void activated();

public slots:
};

#endif // NATIVEEVENTFILTER_H
