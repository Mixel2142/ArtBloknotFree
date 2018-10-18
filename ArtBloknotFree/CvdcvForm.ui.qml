import QtQuick 2.4

Item {
    width: 400
    height: 400

    Rectangle {
        id: rectangle
        x: 60
        y: 44
        width: 200
        height: 200
        color: "#ffffff"

        Image {
            id: image
            x: 50
            y: 57
            width: 100
            height: 100
            source: "qrc:/qtquickplugin/images/template_image.png"
        }
    }
}
