#include <QApplication>
#include <QCommandLineParser>
#include <QCommandLineOption>

#include "main_window.hpp"

int main(int argc, char* argv[]) {

    QApplication app(argc, argv);
    QCommandLineParser parser;
    parser.setApplicationDescription(QCoreApplication::applicationName());
    parser.addHelpOption();
    parser.addVersionOption();
    parser.process(app);

    MainWindow window;
    window.show();
    return app.exec();
}