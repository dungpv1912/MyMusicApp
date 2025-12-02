import QtQuick 2.0

Rectangle {
    id: mainContent
    width: 440
    height: 270

    property int volume: mySetting.volume
    Rectangle {
        id: recVolumeBar
        width: 300
        height: 40
        anchors.centerIn: parent

        ChangeVolBttn{
            id: minusVol
            width: 40
            height: 40
            anchors.left:  parent.left
            isPlus:false
            vol:volume
            onVolChanged: {
                mainContent.volume = vol
                mySetting.volume = vol
            }
        }

        Rectangle{
            id: volumeBar
            width: 200
            height: 20
            anchors.centerIn: parent
            border.color: "blue"

            Rectangle{
                id: currVol
                width: volume*2
                height: 20
                anchors.left: parent.left
                color: "blue"
            }
        }

        ChangeVolBttn{
            id: addVol
            width: 40
            height: 40
            anchors.right: parent.right
            isPlus:true
            vol:volume
            onVolChanged: {
                mainContent.volume = vol
                mySetting.volume = vol
            }
        }
    }

}
