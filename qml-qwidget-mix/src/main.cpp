#include <QApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QCommandLineParser>
#include <QCommandLineOption>
#include <QDebug>

#include "button_sampler.h"
#include "quickpanel.h"

void PrintArgs(int& argc, char** argv)
{
    qDebug() << "Printing argv...";
    for (int i = 0; i < argc; i++)
        qDebug() << argv[i];
}

QCoreApplication* CreateApplication(int& argc, char* argv[])
{
    for (int i = 1; i < argc; i++)
    {
        if (!qstrcmp(argv[i], "--no-gui"))
        {
            return new QCoreApplication(argc, argv);
        }
        if (!qstrcmp(argv[i], "--qml"))
        {
            return new QGuiApplication(argc, argv);
        }
    }

    return new QApplication(argc, argv);

}

int main(int argc, char** argv)
{
    qInfo() << "Application Starting";

    QScopedPointer<QCoreApplication> a(CreateApplication(argc, argv));

    QCoreApplication::setOrganizationName("USNR");
    QCoreApplication::setApplicationName("Qt Sampler");
    QCoreApplication::setApplicationVersion(QT_VERSION_STR);

    QCommandLineParser parser;
    parser.setApplicationDescription(QCoreApplication::applicationName());
    parser.addHelpOption();
    parser.addVersionOption();
    // Add dummy options for application type selection.
    parser.addOption(QCommandLineOption("qml"));
    parser.addOption(QCommandLineOption("no-gui"));
    parser.process(*a);

    QWidget* window;
    ButtonSampler* button_sampler;

    qmlRegisterType<QuickPanel>("com.usnr.qtsampler.quickpanel", 1, 0, "QuickPanel");
    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));



    if (qobject_cast<QApplication*>(a.data()))
    {
        qDebug() << "Widget GUI Starting";
        window = new QWidget();
        window->setObjectName("buttonPanelWindow");
        button_sampler = new ButtonSampler(window);
        qobject_cast<QApplication*>(a.data())->setStyleSheet("QWidget#buttonPanelWindow { background-color : black }");
        //qobject_cast<QApplication*>(a.data())->setStyleSheet("QProgressBar::chunk { background : QLinearGradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #F00, stop: 1 #0F0); }");
        window->show();
        window->adjustSize();
    }
    else if (qobject_cast<QGuiApplication*>(a.data()))
    {
        qDebug() << "QML GUI Started";
        engine.load(url);
    }
    else { qDebug() << "No GUI"; }


    return a->exec();
}
