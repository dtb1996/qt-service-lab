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

#if QT_VERSION >= QT_VERSION_CHECK(6, 10, 0)
    // For local Qt 6.10+ builds
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("QtServiceLab", "Main");
#else
    // For CI builds on older Qt 6 (Ubuntu 22.04)
    const QUrl url(QStringLiteral("qrc:/qml/Main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        });
    engine.load(url);
#endif

    return app.exec();
}
