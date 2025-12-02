import QtQuick 2.0

Rectangle{
    id: changeVol
    width: 40
    height: 40
    property bool isPlus
    property int vol
    property bool  hovered
    color:hovered ? "#D3D3D3": "transparent"
    Image{
        anchors.fill: parent
        source: isPlus === false ?"img/minusIcon.png":"img/plusIcon.png"
    }

    MouseArea{
        anchors.fill: parent
        hoverEnabled: true
        onEntered: changeVol.hovered = true
        onExited: changeVol.hovered = false
        onClicked: {
            if (isPlus===true)
                vol = vol<90 ?vol+10:100
            else
                vol = vol>10 ? vol-10:0

            console.log("vol"+ vol)
        }
    }
}
