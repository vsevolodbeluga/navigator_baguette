#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "mapus.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterType<MapUs> ("myclass", 1, 0, "MapUs"); //установка плагина с классом рассчёта

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    if(engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
