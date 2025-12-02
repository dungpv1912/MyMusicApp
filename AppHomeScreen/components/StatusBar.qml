import QtQuick 2.0

Rectangle {
    id: statusBar
    width: 640
    height: 50
    anchors.top: parent.top
    anchors.horizontalCenter: parent.horizontalCenter
    color: "Pink"

    Text{
        anchors.centerIn: parent
        text: "DATE_TIME"
    }
}
