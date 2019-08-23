#ifndef QOBJECT_H
#define QOBJECT_H

#include <QObject>

class qobject : public QObject
{
    Q_OBJECT
public:
    explicit qobject(QObject *parent = nullptr);

signals:

public slots:
};

#endif // QOBJECT_H