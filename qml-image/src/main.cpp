#include <QApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <memory>

#include "workspace.hpp"


int main(int argc, char** argv)
{
    // App
    Workspace workspace;

    // Qt
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication::setApplicationVersion("0.0.1");

    auto app = std::make_unique<QGuiApplication>(argc, argv);

    // Qml
    qmlRegisterType<Workspace>("App", 1, 0, "Workspace");
    qmlRegisterType<ImageItem>("App", 1, 0, "ImageItem");

    QQmlApplicationEngine engine;

    const QUrl url("qrc:///main.qml");

    engine.load(url);
    engine.rootContext()->setContextProperty("workspace", &workspace);

    return app->exec();
}
