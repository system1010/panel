import QtQuick 2.3
import QtQuick.Layouts 1.1

Rectangle {
    id: mybutton

    //Добавляем к кнопку свойство text,
    //в которое можно будет что-нибудь записать.
    //Это будет текст нашей кнопки
    property string text

    //Добавляем сигнал, который будет вызываться,
    //когда пользователь нажал на кнопку
    signal clicked

    color: "yellow"
    radius: 5

    //Ширина и высота кнопки по умолчанию
    implicitWidth: buttonText.width + radius
    implicitHeight: buttonText.height + radius

    border {
        color: "grey"
        width: 1
    }

    //Непосредственно элемент, рисующий текст кнопки
    Text {
        id: buttonText
        //По центру кнопки
        anchors.centerIn: parent
        text: mybutton.text
    }

    MouseArea {
        anchors.fill: parent
        onClicked: mybutton.clicked()
    }
}
