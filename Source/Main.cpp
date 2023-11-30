#include "LifeQuickItem.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>

using namespace sp;

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    qmlRegisterType<LifeQuickItem>("SP", 1, 0, "LifeQuickItem");

    QQmlApplicationEngine engine;
    engine.load("qrc:/Main.qml");

    return app.exec();
}
