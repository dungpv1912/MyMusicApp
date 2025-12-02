#ifndef APPCOMMON_H
#define APPCOMMON_H
#include <QDebug>
#define LOG     qDebug() << Q_FUNC_INFO << "[" << __LINE__ << "]" << " "


#define PATH_NAME_MAIN       "/com/path/main"
#define SERVICE_NAME_MAIN     "com.service.main"

#define PATH_NAME_HOME       "/com/path/home"
#define PATH_NAME_VIDEO      "/com/path/video"
#define PATH_NAME_SETUP      "/com/path/setup"

#define SERVICE_NAME_HOME     "com.service.home"
#define SERVICE_NAME_VIDEO    "com.service.video"
#define SERVICE_NAME_SETUP    "com.service.setup"

#define INTERFACE_NAME          "local.AppEngine"

enum APP_ID: int {
    APP_MAIN,
    APP_HOME,
    APP_MEDIA,
    APP_SETUP
};

#endif // APPCOMMON_H
