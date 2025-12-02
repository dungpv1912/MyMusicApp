function getIndex(name){
    if (name === "Setting")
        return 3
    else if (name === "Gallery")
        return 2
    else if (name ==="Music")
        return 1
}

function getImgPath(name){
    if (name === "Setting")
        return "qrc:/img/settings.png"
    else if (name === "Gallery")
        return "qrc:/img/gallery.png"
    else if (name ==="Music")
        return "qrc:/img/music-player.png"

}

function statusBarGetImg(name){
    if (name === "goHomePage")
        return "qrc:/img/home.png"
    else if (name === "back")
        return "qrc:/img/back.png"
    else if (name ==="showList")
        return "qrc:/img/playlistIcon.png"
    else if (name ==="zoomImage")
        return "qrc:/img/EngIcon.png"

}

