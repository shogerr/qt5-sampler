import QtQuick 2.13
import QtQuick.Layouts 1.11

Item {
    id: root 
    anchors.fill: parent
    objectName: "canvasFrame"

    RowLayout {
        id: layout
        anchors.fill: parent
        spacing: 6
        Rectangle {
            Layout.fillWidth: true
            Layout.fillHeight: true

            Layout.minimumWidth: 50
            color: 'plum'
            Text {
                text: "Canvas"
                font.pointSize: 26
                color: 'red'
            }
        }
    }

}