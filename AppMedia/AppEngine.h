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

enum AppHome_Enum: int {
    APP_MAIN,
    APP_HOME,
    APP_MEDIA,
    APP_SETUP,
    APP_GALLERY
};

class AppSetting;

class AppEngine : public QObject
{
    Q_OBJECT
public:
    explicit AppEngine(QGuiApplication &app, QObject *parent = nullptr);
    ~AppEngine();
    void showViewer();
    void hideViewer();
    Q_INVOKABLE void requestShow(int appID);

public slots:
    int showWindow(int appID);
    int hideWindow(int appID);


private:
    QGuiApplication *mApp;
    QQuickView *mViewer;
    AppEngineAdaptor *mAptor;
    local::AppMain *mInterface;

};

class AppSetting: public QObject{
    Q_OBJECT
    Q_PROPERTY(int volume READ volume WRITE setVolume NOTIFY volumeChanged)
    Q_PROPERTY(int language READ language WRITE setLanguage NOTIFY languageChanged)


public:
    int volume() const;
    int language() const;
    explicit AppSetting(QObject *parent = nullptr);

    ~AppSetting();
public slots:
    void setVolume(int volume);
    void setLanguage(int language);

signals:
    void volumeChanged(int volume);
    void languageChanged(int language);

private:
    int m_volume;

    int m_language;
};

#endif // APPENGINE_H
