#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "src/GameEngine.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    GameEngine gameEngine;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("GameEngine", &gameEngine);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("Povilization_QML", "Main");

    return QGuiApplication::exec();
}
