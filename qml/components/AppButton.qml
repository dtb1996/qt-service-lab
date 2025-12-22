import QtQuick
import QtQuick.Controls

Button {
    id: control

    // === Styling ===
    property color backgroundColor: "#2c2c2c"
    property color hoverColor: "#3a3a3a"
    property color pressedColor: "#1f1f1f"
    property color disabledColor: "#555555"

    property color textColor: "#ffffff"
    property color disabledTextColor: "#aaaaaa"

    property int cornerRadius: 6
    property int hPadding: 16
    property int vPadding: 8

    font.pixelSize: 14
    implicitHeight: 36
    implicitWidth: Math.max(80, contentItem.implicitWidth + hPadding * 2)

    leftPadding: hPadding
    rightPadding: hPadding
    topPadding: vPadding
    bottomPadding: vPadding

    // === Background ===
    background: Rectangle {
        radius: control.cornerRadius
        color: !control.enabled ? control.disabledColor :
                control.down    ? control.pressedColor  :
                control.hovered ? control.hoverColor    : control.backgroundColor

        border.color: "#ccffffff"
        border.width: 1
    }

    // === Text ===
    contentItem: Text {
        text: control.text
        color: control.enabled ? control.textColor : control.disabledColor
        font: control.font
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
    }

    // === Cursor feedback ===
    hoverEnabled: true

    HoverHandler {
        cursorShape: Qt.PointingHandCursor
    }
}
