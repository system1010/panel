import QtQuick 2.9
import QtQuick.Window 2.2

import QtQuick.Layouts 1.1

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
        }

        MyButton {
            Layout.fillHeight: true
            Layout.fillWidth: true
            color: "blue"
        }

        MyButton {
            Layout.fillHeight: true
            Layout.fillWidth: true
        }
    }
}
