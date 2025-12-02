import QtQuick 2.9

Item {
    id: root
    width: 1920
    height: 1080 - 80
    Rectangle
    {
        id: statusbar
        width: 1920
        height: 90
        color: "orange"
        Text {
            id: txtStatusbar
            text: qsTr("Status Bar Area")
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
        }
    }

    Rectangle
    {
        id: title
        width: 1280
        height: 90
        color: "red"
        anchors.top: statusbar.bottom
        Text {
            id: txtTitle
            text: qsTr("App Home Screen")
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
        }
    }
    Item {
        id: appArea
        width: 1280
        height: 900 - 80
        anchors.top: title.bottom
        Rectangle
        {
            id: videoApp
            width: 639
            height: 900 - 80
            color: "blue"
            anchors.left: parent.left
            Text {
                id: txtVideo
                text: qsTr("Video Player")
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
            }
            MouseArea
            {
                anchors.fill: parent
                onClicked:
                {
                    console.debug("onClicked")
                    myEngine.requestShow(1);
                }
            }
            Rectangle
            {
                id: setupApp
                width: 639
                height: 900 - 80
                color: "blue"
                anchors.left: videoApp.right
                anchors.leftMargin: 2
                Text {
                    id: txtSetup
                    text: qsTr("Setup Player")
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                }
                MouseArea
                {
                    anchors.fill: parent
                    onClicked:
                    {
                        console.debug("onClicked")
                        myEngine.requestShow(3);
                    }
                }
            }
        }
    }

    Rectangle
    {
        id: widget
        width: 640
        height: 990 - 80
        color: "green"
        anchors.top: statusbar.bottom
        anchors.left: appArea.right
        Text {
            id: txtWidget
            text: qsTr("Video Widget")
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
        }
        MouseArea
        {
            anchors.fill: parent
            onClicked:
            {
                console.debug("onClicked")
                myEngine.requestShow(2);
            }
        }
    }
}
