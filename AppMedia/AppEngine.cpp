#include "AppEngine.h"
#include <QTimer>

AppEngine::AppEngine(QGuiApplication &app, QObject *parent) : mApp(&app), QObject(parent)
{
//    AppSetting* mSetting = new AppSetting;
    mViewer = new QQuickView;
//    mViewer->rootContext()->setContextProperty("mySetting", mSetting);
    mViewer->rootContext()->setContextProperty("myEngine", this);
    mViewer->setSource(QUrl::fromLocalFile(":/main.qml"));


    QDBusConnection dbus = QDBusConnection::sessionBus();
    if(!dbus.isConnected())
    {
        LOG << "Can not connect to dbus";
    }

    // register object service
    if(!dbus.registerService(SERVICE_NAME_MEDIA))
    {
        LOG << "Can not Register Service " << SERVICE_NAME_MEDIA;
    }

    // register object paths
    if(!dbus.registerObject(PATH_NAME_MEDIA, this))
    {
        LOG << "cannot registerObject" << PATH_NAME_MEDIA;
    }

    mAptor = new AppEngineAdaptor(this);
    mInterface = new local::AppMain(QString(SERVICE_NAME_MAIN), QString(PATH_NAME_MAIN), dbus, this);
    mInterface->registrationAppID(AppHome_Enum::APP_MEDIA, "AppMedia", SERVICE_NAME_MEDIA, PATH_NAME_MEDIA);
}

AppEngine::~AppEngine()
{
    LOG << "decontructor";
    mInterface->requestShow(AppHome_Enum::APP_HOME);
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
        mInterface->deregistrationAppID(AppHome_Enum::APP_MEDIA, "AppMedia");
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
    if(appID == AppHome_Enum::APP_MEDIA)
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
    if(appID == AppHome_Enum::APP_MEDIA)
    {
        mViewer->hide();
        return 1;
    }
    else
    {
        return 0;
    }
}


int AppSetting::volume() const
{
    return m_volume;
}

int AppSetting::language() const
{
    return m_language;
}

AppSetting::AppSetting(QObject *parent)
{
    m_volume = 50;
    m_language = 0;
}


AppSetting::~AppSetting()
{

}

void AppSetting::setVolume(int volume)
{
    if (m_volume == volume)
        return;

    m_volume = volume;
    emit volumeChanged(m_volume);
}

void AppSetting::setLanguage(int language)
{
    if (m_language == language)
        return;

    m_language = language;
    emit languageChanged(m_language);
}
