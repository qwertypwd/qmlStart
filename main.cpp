#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
//#include "testModel.h"
#include "avgViewer.h"

int main(int argc, char *argv[])
{

    //TestModel tm;
    //AvgViewer av(tm);
    AvgViewer av;
    //QScopedPointer<AvgViewer> av(new AvgViewer);


    qmlRegisterSingletonInstance(
        "AvgViewerModule", // Имя модуля
        1, // Основная версия модуля
        0, // Минорная версия модуля
        "AvgViewer", // Определяет, как будет называться в QML, чтобы получить к нему доступ
        &av
        );


    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection
        );
    engine.loadFromModule("untitled3", "Main");

    return app.exec();
}
