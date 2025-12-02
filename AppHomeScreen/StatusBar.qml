import QtQuick 2.0
import QtQuick.Controls 2.12
import "utils.js" as Utils
Rectangle {
    id: statusBar
    width: 640
    height: 50
    anchors.top: parent.top
    anchors.horizontalCenter: parent.horizontalCenter
    color: "#333333"
    ListModel {
        id: actionModel
        ListElement { nameAction: "back" ;imgSrc: "qrc:/img/back.png"}
        ListElement { nameAction: "goHomePage";   imgSrc: "qrc:/img/home.png"}
        ListElement { nameAction: "showList" ;imgSrc: "qrc:/img/playlistIcon.png"}
    }

    Component{
        id: actionComp
        Rectangle{
            width: 50
            height: 50
            property bool hovered: false
            color: hovered ? "#555555" : "transparent"
            Image{
                id:img
                width: 40
                height: 40
                source: model.imgSrc
                anchors.centerIn: parent
                Component.onCompleted: console.log("model.nameAction: "+ model.nameAction)
            }
            MouseArea {
                id: hoverArea
                anchors.fill: parent
                hoverEnabled: true
                onEntered: hovered = true
                onExited: hovered = false

                // Optional: Click handler
                onClicked: {
                    console.log("Clicked:", model.nameAction)
                    myEngine.requestShow(1)
                }

            }
        }
    }
    // Container for both icons
    ListView {
        id: iconList
        width: 200
        height: 50
        orientation: ListView.Horizontal
        model: actionModel
        delegate: actionComp
        spacing: 10
        clip: true
        boundsBehavior: Flickable.StopAtBounds
    }

    // Clock
    Text {
        id: timeLabel
        anchors.centerIn:  parent
        font.pixelSize: 16
        color: "white"
        text: Qt.formatDateTime(new Date(), "hh:mm AP dd-MMM")

        Timer {
            interval: 1000
            running: true
            repeat: true
            onTriggered: {
                timeLabel.text = Qt.formatDateTime(new Date(), "hh:mm AP dd-MMM")
            }
        }
    }


}
