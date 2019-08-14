import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

import info 1.0  // Import Module

Window {
    visible: true
    width: 360
    height: 360
    title: qsTr("Enumeration")

    ListView {
        anchors.fill: parent
        delegate: Item {
            height: 48
            width: parent.width
            Text {
                anchors.fill: parent
                text: "Message " + model.text

                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }
        }

        model: ListModel {
            // Use the enumerations from C ++
            ListElement {text: Info.Information}
            ListElement {text: Info.Debug}
            ListElement {text: Info.Warning}
            ListElement {text: Info.Error}
        }
    }
}
