import QtQuick 2.6
import QtQuick.Controls 2.6
import QtQuick.Window 2.6

ApplicationWindow
{
    id: appWindow
    visible: true

    color: "transparent"

    width: 300
    height: 200

    Rectangle {
        id: myRect
        anchors.fill: parent
        color: "black"
        Text {
            id: myText
            // This function is to show that I want to attach some content dynamically.
            // It must be only invoked once per instanciate of this .qml file, but
            // running this proves it's called many times.
            text: myGlobal.createDynamicText()
            font.family: "Helvetica"
            font.pointSize: 24
            anchors.centerIn: parent
            color: "yellow"
        }
    }
    // Having not the direct assignment above but only the line below will make it work.
    // Component.onCompleted: myText.text = myGlobal.createDynamicText();
}
