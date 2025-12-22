import QtQuick
import QtQuick.Controls

Item {
    anchors.fill: parent
    visible: false

    Rectangle {
        anchors.fill: parent
        color: "#80000000"
    }

    BusyIndicator {
        anchors.centerIn: parent
        running: true
        width: 48
        height: 48
    }
}
