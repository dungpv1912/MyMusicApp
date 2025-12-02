import QtQuick 2.12
import QtQuick.Controls 2.12
import "qrc:/"

Rectangle {
    id: root
    visible: true
    width: 640
    height: 320
    anchors.centerIn: parent
    onWidthChanged: if (width !== 640) width = 640
    onHeightChanged: if (height !== 320) height = 320

    StatusBar{

    }


}
