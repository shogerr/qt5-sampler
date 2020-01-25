import QtQuick 2.13
import QtQuick.Controls 2.13
import QtQuick.Controls 2.13 as Controls

Controls.MenuBar {
    Menu {
        id: fileMenu
        title: qsTr("File")

        MenuItem {
            text: qsTr("Open")
            //onTriggered: function() {}
        }
    }
}
