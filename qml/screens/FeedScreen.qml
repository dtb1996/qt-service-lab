import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    id: root

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 16
        spacing: 12

        // Header
        RowLayout {
            Layout.fillWidth: true

            Label {
                text: qsTr("Feed")
                font.pixelSize: 24
                font.bold: true
                Layout.fillWidth: true
            }

            AppButton {
                text: qsTr("Reload")
                enabled: !AppState.loading
                onClicked: AppController.loadFeed()
            }
        }

        // Error Banner
        ErrorBanner {
            visible: AppState.error.length > 0
            message: AppState.error
            onRetryRequested: AppController.loadFeed()
        }

        // Feed list
        ListView {
            Layout.fillWidth: true
            Layout.fillHeight: true
            model: FeedModel
            spacing: 8
            clip: true

            delegate: Rectangle {
                width: ListView.view.width
                implicitHeight: contentColumn.implicitHeight + 24
                radius: 6
                color: "#2c2c2c"

                Column {
                    id: contentColumn
                    anchors.fill: parent
                    anchors.margins: 12
                    spacing: 4

                    Text {
                        text: title
                        font.pixelSize: 16
                        font.bold: true
                        color: "#ffffff"
                    }

                    Text {
                        text: body
                        font.pixelSize: 13
                        color: "#cccccc"
                        wrapMode: Text.WordWrap
                    }

                    Text {
                        text: Qt.formatDateTime(timestamp, "hh:mm:ss")
                        font.pixelSize: 11
                        color: "#999999"
                    }
                }
            }
        }
    }

    LoadingOverlay {
        visible: AppState.loading
    }

    Component.onCompleted: {
        AppController.loadFeed()
    }
}
