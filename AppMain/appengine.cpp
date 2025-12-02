#include "appengine.h"
#include "appcommon.h"
#include <QDBusMessage>
#include <QDBusConnection>

AppEngine::AppEngine(QObject *parent) : QObject(parent)
{
    mAdaptor = new AppMainAdaptor(this);
    registerDbus();
}

void AppEngine::registerDbus()
{
    QDBusConnection dbus = QDBusConnection::sessionBus();
    if(!dbus.isConnected())
    {
        LOG << "Can not connect to dbus";
        return;
    }

    // register object service
    if(!dbus.registerService(SERVICE_NAME_MAIN))
    {
        LOG << "Can not Register Service " << SERVICE_NAME_MAIN;
        return;
    }

    // register object paths
    if(!dbus.registerObject(PATH_NAME_MAIN, this))
    {
        LOG << "cannot registerObject" << PATH_NAME_MAIN;
        return;
    }

    LOG << "Successful!!!";
}

void AppEngine::registrationAppID(int appid, const QString &appname, const QString &servicename, const QString &objectpath)
{
    if(!mMappApps.contains(appid))
    {
        ApplicationHandler *pApp = new ApplicationHandler(appid, appname, servicename, objectpath);
        mMappApps[appid] = pApp;
        if(appid == APP_HOME)
        {
            pApp->requestShowWindow();
        }
    }
    else
    {
        LOG << "Map is already included the appID: " << appid;
    }
}

void AppEngine::deregistrationAppID(int appid, const QString &appname)
{
    LOG << "appid: " << appid;
    if(!mMappApps.contains(appid))
    {
        LOG << "Map does not include the appID: " << appid;
    }
    else
    {
        mMappApps.remove(appid);
    }
}

void AppEngine::requestShow(int appid)
{
    LOG << "appid: " << appid;
    if(mMappApps.contains(appid))
    {
        ApplicationHandler *pApp = mMappApps[appid];
        connect(pApp, &ApplicationHandler::callbackResponsed, this, &AppEngine::onHideWindowChanged, Qt::UniqueConnection);
        pApp->requestShowWindow();
    }
    else
    {
        LOG << "Map does not include the appID: " << appid;
    }
}

void AppEngine::onHideWindowChanged(int result, int lastappid, int appid)
{
    disconnect(mMappApps[appid], &ApplicationHandler::callbackResponsed, this, &AppEngine::onHideWindowChanged);
    if(result > 0)
    {
        mMappApps[lastappid]->requestHideWindow();
    }
}
