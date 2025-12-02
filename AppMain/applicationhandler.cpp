#include "applicationhandler.h"
#include "appcommon.h"
#include <QDBusPendingCall>

int ApplicationHandler::mLastAppID = APP_MAIN;

ApplicationHandler::ApplicationHandler(QObject *parent) : QObject(parent)
{
    mAppID = APP_MAIN;
    mAppName = "";
    mServiceName = "";
    mObjectpath = "";
}

ApplicationHandler::ApplicationHandler(int appid, QString appname, QString servicename, QString objectpath, QObject *parent)
{
    mAppID = appid;
    mAppName = appname;
    mServiceName = servicename;
    mObjectpath = objectpath;
    LOG << " appid = " << mAppID << " appname = " << mAppName << " servicename = " << mServiceName << " objectpath = " << mObjectpath;
    mInteface = new local::AppEngine(servicename, objectpath, QDBusConnection::sessionBus(), parent);
}

void ApplicationHandler::requestShowWindow()
{
    LOG << " appid = " << mAppID << " mServiceName = " << mServiceName << " mObjectpath = " << mObjectpath;
    QDBusPendingCall clsPendingcall = mInteface->showWindow(mAppID);
    if(clsPendingcall.isError())
    {
        LOG << "showWindow: " << clsPendingcall.error().type() << " --> " << clsPendingcall.error().errorString(clsPendingcall.error().type());
    }
    else
    {
        QDBusPendingCallWatcher *p_clsWatcher = new QDBusPendingCallWatcher( clsPendingcall, this );
        QObject::connect( p_clsWatcher, SIGNAL(finished(QDBusPendingCallWatcher*)),
                          this, SLOT(onShowWindowResponsed(QDBusPendingCallWatcher*)) );
    }
}

void ApplicationHandler::requestHideWindow()
{
    LOG << " appid = " << mAppID << " mServiceName = " << mServiceName << " mObjectpath = " << mObjectpath;
    QDBusPendingCall clsPendingcall = mInteface->hideWindow(mAppID);
    if(clsPendingcall.isError())
    {
        LOG << "hideWindow: " << clsPendingcall.error().type() << " --> " << clsPendingcall.error().errorString(clsPendingcall.error().type());

    }
    else
    {
        LOG << "Hide sucessfull";
    }
}

void ApplicationHandler::onShowWindowResponsed(QDBusPendingCallWatcher *a_pCall)
{
    QDBusPendingReply<int> reply = *a_pCall;
    if ( reply.isError())
    {
        LOG << "DBusConnection::callResponseSlot error reply: " << reply.error().errorString(reply.error().type());
    }
    else
    {
        int nRet = reply.argumentAt<0>();
        LOG << "nRet: " << nRet << ", mLastAppID: " << mLastAppID << ", mAppID: " << mAppID;
        if(nRet > 0)
        {
            if(mLastAppID != mAppID)
            {
                if(mLastAppID != APP_MAIN)
                {
                    callbackResponsed(nRet, mLastAppID, mAppID);
                }
                mLastAppID = mAppID;
            }
        }
    }

    a_pCall->deleteLater();
}
