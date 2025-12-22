import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    id: root
    radius: 6
    color: "#b00020"
    Layout.fillWidth: true
    implicitHeight: contentRow.implicitHeight + 24
    visible: false

    property string message
    signal retryRequested()

    RowLayout {
        id: contentRow
        anchors.fill: parent
        anchors.margins: 12
        spacing: 12

        Label {
            text: message
            color: "#ffffff"
            Layout.fillWidth: true
            wrapMode: Text.WordWrap
        }

        Button {
            text: qsTr("Retry")
            Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
            onClicked: retryRequested()
        }
    }
}
