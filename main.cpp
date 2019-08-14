#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml> // Include QtQml to use qmlRegisterType

#include "info.h" // Connect the header file of the Info class

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<Info>("info", 1, 0, "Info"); // Register this class as a module

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
