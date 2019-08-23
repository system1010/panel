//#ifndef QOBJECT_H
//#define QOBJECT_H
#include <QApplication>
#include <QObject>
#include "nativeeventfilter.h"

class qobject : public QObject
{
    Q_OBJECT
public:
    explicit qobject(QObject *parent = nullptr);

signals:

public slots:

private:
    NativeEventFilter *nativeEventFilter;

};

//#endif // QOBJECT_H
