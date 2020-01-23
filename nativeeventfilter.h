#ifndef NATIVEEVENTFILTER_H
#define NATIVEEVENTFILTER_H

//#include <QObject>
#include <QWidget>
#include <QAbstractNativeEventFilter>
class NativeEventFilter : public /*QObject*/QWidget, public QAbstractNativeEventFilter
{
    Q_OBJECT
public:
    explicit NativeEventFilter(/*QObject*/ QWidget *parent = nullptr);

 virtual bool nativeEventFilter(const QByteArray &eventType, void *message, qintptr *result);
    void setShortcut();
    void setShortcut1();

    void unsetShortcut();

signals:
    void activated();

public slots:
};

#endif // NATIVEEVENTFILTER_H
