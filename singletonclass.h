#ifndef SINGLETONCLASS_H
#define SINGLETONCLASS_H

#include <QObject>
#include <QQmlEngine>
#include <QJSEngine>

class SingletonClass : public QObject
{
    Q_OBJECT
public:
    explicit SingletonClass(QObject *parent = nullptr);

    enum class Message {
        Info,
        Debug,
        Warning,
        Error
    };
    Q_ENUM(Message)

    Q_INVOKABLE QString getMessage(Message message);

signals:

public slots:
};

static QObject *singletonProvider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    SingletonClass *singletonClass = new SingletonClass();
    return singletonClass;
}

#endif // SINGLETONCLASS_H
