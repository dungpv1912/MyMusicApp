#include <QCoreApplication>
#include "appengine.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    AppEngine engine;
    return a.exec();
}
