#include "appengine.h"
#include <QTimer>

AppEngine::AppEngine(QGuiApplication &app, QObject *parent) : mApp(&app), QObject(parent)
{
    mViewer = new QQuickView;
    mViewer->setSource(QUrl::fromLocalFile(":/main.qml"));
    mViewer->rootContext()->setContextProperty("myEngine", this);

    QDBusConnection dbus = QDBusConnection::sessionBus();
    if(!dbus.isConnected())
    {
        LOG << "Can not connect to dbus";
    }

    // register object service
    if(!dbus.registerService(SERVICE_NAME_HOME))
    {
        LOG << "Can not Register Service " << SERVICE_NAME_HOME;
    }

    // register object paths
    if(!dbus.registerObject(PATH_NAME_HOME, this))
    {
        LOG << "cannot registerObject" << PATH_NAME_HOME;
    }
    LOG << "registering ..." ;
    mAptor = new AppEngineAdaptor(this);
    mInterface = new local::AppMain(QString(SERVICE_NAME_MAIN), QString(PATH_NAME_MAIN), dbus, this);
    mInterface->registrationAppID(APP_HOME, "AppHomeScreen", SERVICE_NAME_HOME, PATH_NAME_HOME);
    LOG << "register Done" ;
}

AppEngine::~AppEngine()
{
    LOG << "decontructor";
    if(mViewer)
    {
        delete mViewer;
        mViewer = nullptr;
    }
    if(mAptor)
    {
        delete mAptor;
        mAptor = nullptr;
    }
    if(mInterface)
    {
        mInterface->deregistrationAppID(APP_HOME, "AppHomeScreen");
        delete mInterface;
        mInterface = nullptr;
    }
}

void AppEngine::requestShow(int appID)
{
    LOG << "appID: " << appID;
    mInterface->requestShow(appID);
}

void AppEngine::showViewer()
{
    mViewer->show();
}

void AppEngine::hideViewer()
{
    mViewer->hide();
}

int AppEngine::showWindow(int appID)
{
    LOG << "appID: " << appID;
    if(appID == APP_HOME)
    {
        mViewer->show();
        mViewer->setX(500);
        mViewer->setY(250);
        return 1;
    }
    else
    {
        return 0;
    }
}

int AppEngine::hideWindow(int appID)
{
    LOG << "appID: " << appID;
    if(appID == APP_HOME)
    {
        mViewer->hide();
        return 1;
    }
    else
    {
        return 0;
    }
}
