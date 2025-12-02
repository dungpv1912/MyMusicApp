import QtQuick 2.0
import QtQuick.Controls 2.12
import "utils.js" as Utils

Item {
    id: mainContent
    width: 640
    height: 270

    anchors.bottom:  parent.bottom
    anchors.horizontalCenter: parent.horizontalCenter

    ListModel {
        id: contentModel1
        ListElement {
            appName: "Music"
            Desc1: "Songs Tittles"
            Desc2: "Artist name"
        }
        ListElement {
            appName: "Gallery"
            Desc1: ""
            Desc2: "unKnown"
        }

    }



    ListModel {
        id: contentModel2
        ListElement {
            appName: "Setting"
            Desc1: " "
            Desc2: " "
        }

    }
    Component {
        id: contentDelegate
        Item {
            width: 320; height: 270
            Rectangle{
                id :rectContent
                width: 250; height: 230
                anchors.centerIn: parent
                property bool hovered: false
                color:hovered ? "#D3D3D3": "transparent"
                border.color: "blue"
                border.width: 2    // Bolder border
                Rectangle{
                    id:recAppName
                    width: 200; height: 40
                    color:rectContent.color
                    anchors.top:  parent.top
                    anchors.topMargin: 10
                    anchors.horizontalCenter: parent.horizontalCenter
                    Text {
                        anchors.centerIn: parent
                        text: appName
                    }

                }

                Rectangle{
                    id :recImg
                    width: 100; height: 100
                    color:rectContent.color
                    anchors.centerIn: parent
                    Image {
                        id: img
                        width: 100; height: 100
                        source: Utils.getImgPath(model.appName)
                        anchors.fill: parent
                        focus: true
                    }
                }

                Rectangle{
                    id:decription
                    width: 200; height: 40
                    color:rectContent.color
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 20
                    anchors.horizontalCenter: parent.horizontalCenter
                    Column {
                        anchors.centerIn: parent
                        Text { text:  Desc1 }
                        Text { text:  Desc2 }
                    }
                }

                MouseArea
                {
                    hoverEnabled: true
                    onEntered: rectContent.hovered = true
                    onExited: rectContent.hovered = false

                    anchors.fill: parent
                    onClicked:
                    {
                        console.debug("onClicked")
                        myEngine.requestShow(Utils.getIndex(appName));
                    }
                }
            }


        }
    }

    SwipeView{
            id: swipeView
            anchors.fill: parent
            currentIndex: 0
            ListView {
                id :list1st
                width: 640
                height: 270
                model:contentModel1
                delegate: contentDelegate
                orientation: ListView.Horizontal
            }



        ListView {
            id :list2nd
            width: 640
            height: 270
            model:contentModel2
            delegate: contentDelegate
            orientation: ListView.Horizontal
        }
    }
    PageIndicator {
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        count: swipeView.count
        currentIndex: swipeView.currentIndex
    }
}
