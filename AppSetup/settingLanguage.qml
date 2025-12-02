import QtQuick 2.0

Rectangle {
    id: langContent
    width: 440
    height: 270
    property int selectedItem: mySetting.language
    ListModel {
        id: setupModel
        ListElement {
            settingItem: "TiengViet"
        }
        ListElement {
            settingItem: "English"
        }

    }

    Component {
        id: contentDelegate
        Rectangle{
            id :rectContent
            width: 440; height: 50
            property bool hovered: false
            color:hovered ? "#D3D3D3": "transparent"
            Rectangle{
                id:redDot
                z:1
                visible: (selectedItem===index)?true:false
                width: 10
                height: 10
                radius: 5
                color: "red"
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: 20
            }

            Rectangle{
                id:recSettingItem
                width: 440; height: 40
                anchors.centerIn: parent
                color:rectContent.color
                Text {
                    anchors.centerIn: parent
                    text: settingItem
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
                    langContent.selectedItem = index
                    mySetting.language = langContent.selectedItem
                }
            }
        }
    }

    ListView{
        width: 440
        height: 270
        delegate: contentDelegate
        model: setupModel
    }

}
