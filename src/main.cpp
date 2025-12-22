#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "app/AppState.h"
#include "app/AppController.h"
#include "models/FeedModel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    AppState appState;
    FeedModel feedModel;
    AppController controller(&appState, &feedModel);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("AppState", &appState);
    engine.rootContext()->setContextProperty("FeedModel", &feedModel);
    engine.rootContext()->setContextProperty("AppController", &controller);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("QtServiceLab", "Main");

    return app.exec();
}
