import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

import SingletonClass 1.0


Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Singleton Class")

    ListView {
        anchors.fill: parent
        delegate: Item {
            height: 48
            width: parent.width
            Text {
                anchors.fill: parent
                text: model.text

                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }
        }

        model: listModel
    }

    ListModel {
        id: listModel

        Component.onCompleted: {
            listModel.append({'text': SingletonClass.getMessage(SingletonClass.Info)})
            listModel.append({'text': SingletonClass.getMessage(SingletonClass.Debug)})
            listModel.append({'text': SingletonClass.getMessage(SingletonClass.Warning)})
            listModel.append({'text': SingletonClass.getMessage(SingletonClass.Error)})
        }
    }
}
