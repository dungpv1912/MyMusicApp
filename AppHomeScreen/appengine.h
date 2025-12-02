#ifndef APPENGINE_H
#define APPENGINE_H

#include <QObject>
#include <QDebug>
#include <QGuiApplication>
#include <QQuickView>
#include <QQmlContext>
#include <QDBusMessage>
#include <QDBusConnection>

#include "interface_adaptor.h"
#include "appmain_interface.h"

#define PATH_NAME_HOME       "/com/path/home"
#define PATH_NAME_VIDEO      "/com/path/video"
#define PATH_NAME_SETUP      "/com/path/setup"
#define PATH_NAME_MEDIA      "/com/path/media"
#define PATH_NAME_GALLERY      "/com/path/gallery"

#define SERVICE_NAME_HOME     "com.service.home"
#define SERVICE_NAME_VIDEO    "com.service.video"
#define SERVICE_NAME_SETUP    "com.service.setup"
#define SERVICE_NAME_MEDIA    "com.service.media"
#define SERVICE_NAME_GALLERY    "com.service.gallery"


#define INTERFACE_NAME          "com.interface"


#define PATH_NAME_MAIN       "/com/path/main"
#define SERVICE_NAME_MAIN     "com.service.main"


#define LOG          qDebug() << Q_FUNC_INFO
enum APP_ID: int {
    APP_MAIN,
    APP_HOME,//1
    APP_MEDIA,//2
    APP_SETUP,//3
    APP_GALLERY//4
};

class AppEngine : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int lastId READ lastId WRITE setLastId NOTIFY lastIdChanged)
public:
    explicit AppEngine(QGuiApplication &app, QObject *parent = nullptr);
    ~AppEngine();
    void showViewer();
    void hideViewer();
    Q_INVOKABLE void requestShow(int appID);

    int lastId() const
    {
        return m_lastId;
    }

signals:

    void lastIdChanged(int lastId);

public slots:
    int showWindow(int appID);
    int hideWindow(int appID);

    void setLastId(int lastId)
    {
        if (m_lastId == lastId)
            return;

        m_lastId = lastId;
        emit lastIdChanged(m_lastId);
    }

private:
    QGuiApplication *mApp;
    QQuickView *mViewer;
    AppEngineAdaptor *mAptor;
    local::AppMain *mInterface;

    int m_lastId;
};

#endif // APPENGINE_H
