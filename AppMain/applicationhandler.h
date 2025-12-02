#ifndef APPLICATIONHANDLER_H
#define APPLICATIONHANDLER_H

#include <QObject>
#include "interface_interface.h"

class ApplicationHandler : public QObject
{
    Q_OBJECT
public:
    explicit ApplicationHandler(QObject *parent = nullptr);
    explicit ApplicationHandler(int appid, QString appname, QString servicename,
                                QString objectpath, QObject *parent = nullptr);
    void requestShowWindow();
    void requestHideWindow();

signals:
    void callbackResponsed(int, int, int);
public slots:
    void onShowWindowResponsed( QDBusPendingCallWatcher *a_pCall);

private:
    int mAppID;
    static int mLastAppID;
    QString mAppName;
    QString mServiceName;
    QString mObjectpath;

    local::AppEngine *mInteface;
};

#endif // APPLICATIONHANDLER_H
