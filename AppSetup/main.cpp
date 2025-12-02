#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "AppEngine.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    AppEngine myEngine(app);

    return app.exec();
}
