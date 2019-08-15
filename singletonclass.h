#ifndef SINGLETONCLASS_H
#define SINGLETONCLASS_H

#include <QObject>
#include <QQmlEngine>
#include <QJSEngine>
#include <QMainWindow>
#include <QtWidgets>

class core : public QMainWindow
{
    Q_OBJECT

public:
    explicit core(QWidget *parent = 0);
    //~core();

protected:
    bool nativeEvent (const QByteArray & eventType , void *message, long *result);

private slots:
    //void on_keySequenceEdit_keySequenceChanged(const QKeySequence &keySequence);
    //void on_BtnSave_clicked();

private:
//    Ui::core *ui;
};
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
