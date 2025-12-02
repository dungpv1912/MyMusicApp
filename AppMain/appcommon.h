#ifndef APPCOMMON_H
#define APPCOMMON_H
#include <QDebug>
#define LOG     qDebug() << Q_FUNC_INFO << "[" << __LINE__ << "]" << " "


#define PATH_NAME_MAIN       "/com/path/main"
#define SERVICE_NAME_MAIN     "com.service.main"

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


#define INTERFACE_NAME          "local.AppEngine"

enum APP_ID: int {
    APP_MAIN,
    APP_HOME,
    APP_MEDIA,
    APP_SETUP,
    APP_GALLERY
};

#endif // APPCOMMON_H
