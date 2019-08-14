import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

import SingletonClass 1.0

//Будем использовать вертикальный лейаут
import QtQuick.Layouts 1.1
import QtQuick.Dialogs 1.2

Window {
    visible: true
    height: 200
    width: 100
    //Этот лейаут расположит все дочерние
    //элементы по вертикали друг над другом
    ColumnLayout {
        //Отступ между элементами (кнопками)
        spacing: 5

        //Наш ColumnLayout будет вписан в
        //окно приложения с отступами по 5
        //со всех сторон
        anchors.fill: parent
        anchors.margins: 5

        //Создаем три одинаковые кнопки
        MyButton {
            //Все они поделят свободное
            //пространство лейаута между собой
            Layout.fillHeight: true
            Layout.fillWidth: true
            color: "green"
            text: "Hello, world!"

            onClicked: messageDialog.visible = true;
        }

        MyButton {
            Layout.fillHeight: true
            Layout.fillWidth: true
            color: "blue"
            text: "Some button"
            onClicked: SingletonClass.getMessage(SingletonClass.Info);
        }

        MyButton {
            Layout.fillHeight: true
            Layout.fillWidth: true
            text: "Quit"
            onClicked: Qt.quit()
        }
    }

    MessageDialog {
        id: messageDialog
        title: "Qt"
        text: "Hello, world!"
    }
}



/*
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
            SingletonClass.getMessage(SingletonClass.Info);
            SingletonClass.getMessage(SingletonClass.Debug);
            SingletonClass.getMessage(SingletonClass.Warning);
            SingletonClass.getMessage(SingletonClass.Error);        }
    }
}
*/
