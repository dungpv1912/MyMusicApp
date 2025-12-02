import QtQuick 2.0
import QtQuick.Controls 2.12

Rectangle {
    id: mainContent
    width: 640
    height: 270

    anchors.bottom:  parent.bottom
    anchors.horizontalCenter: parent.horizontalCenter
    property int selectedItem: 0
    ListModel {
        id: setupModel
        ListElement {
            settingItem: "Language"
        }
        ListElement {
            settingItem: "Volume"
        }

    }

    Component {
        id: contentDelegate
        Rectangle{
            id :rectContent
            width: 200; height: 50
            property bool hovered: false
            color:hovered ? "#D3D3D3": "transparent"
            border.color: (mainContent.selectedItem === index)?"blue": "transparent"

            Rectangle{
                id:recSettingItem
                width: 200; height: 40
                anchors.centerIn: parent
                color:rectContent.color
                Text {
                    anchors.centerIn: parent
                    text: settingItem
                    color: (mainContent.selectedItem === index)?"red":"black"
                    font.bold:  (mainContent.selectedItem === index)?true:false
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
                    mainContent.selectedItem = index
                }
            }
        }
    }

    Item {
        id: leftComp
        width: 200
        height: 270
        z:1
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        ListView{
            width: 200
            height: 270
            delegate: contentDelegate
            model: setupModel
        }

    }
    Rectangle {
        id: straitLine
        z:1
        width: 2
        height: 270
        anchors.left: leftComp.right
        anchors.bottom: parent.bottom
        color: "blue"

    }
    Item {
        id: rightComp
        width: 440
        height: 270
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        Loader {
                id: loader
                anchors.centerIn: parent
                source : (selectedItem===0)?"settingLanguage.qml":"settingVolume.qml"

            }
    }

    onSelectedItemChanged: {
        loader.source = (selectedItem===0)?"settingLanguage.qml":"settingVolume.qml"

    }
}
