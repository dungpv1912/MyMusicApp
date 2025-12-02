#ifndef APPENGINE_H
#define APPENGINE_H

#include <QObject>
#include <QMap>
#include "applicationhandler.h"
#include "appmain_adaptor.h"

class AppEngine : public QObject
{
    Q_OBJECT
public:
    explicit AppEngine(QObject *parent = nullptr);
    void registerDbus();


signals:

public slots:
    void registrationAppID(int appid, const QString &appname, const QString &servicename,
                           const QString &objectpath);
    void deregistrationAppID( int appid, const QString &appname );

    void requestShow(int appid);
    void onHideWindowChanged(int result, int lastappid, int appid);

private:
    QMap<int, ApplicationHandler*> mMappApps;
    AppMainAdaptor *mAdaptor;
};

#endif // APPENGINE_H
