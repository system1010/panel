#include "singletonclass.h"
#include <QProcess>

SingletonClass::SingletonClass(QObject *parent) : QObject(parent)
{

}

QString SingletonClass::getMessage(SingletonClass::Message message)
{
QProcess process;

if(message==Message::Info){
    process.startDetached("xterm");
}else if(message==Message::Debug){
    process.startDetached("quicknanobrowser");
}else if(message==Message::Warning){
    process.startDetached("init 0");
}else if(message==Message::Error){
    process.startDetached("/opt/Qt5.9.8/Tools/QtCreator/bin/qtcreator");
}

/*    switch (message)
    {
        case Message::Info:
            return "This is Info Message";
        case Message::Debug:
            return "This is Debug Message";
        case Message::Warning:
            return "This is Warning Message";
        case Message::Error:
            return "This is Error Message";
        default:
            return "Nothin not found";
     }
*/
}
bool core::nativeEvent(const QByteArray &eventType, void *message, long *result)
{
    //MSG* msg = static_cast<MSG*>(message);
    //if (msg->message == WM_HOTKEY)
    //{ // Была нажата одна из горячих клавиш

        //if (msg->wParam == 1)
        //{
    QProcess processs;

        processs.startDetached("xterm");

        //qDebug() << 'Hotkey pressed';
        //QMessageBox::information(0, "", "Hotkey pressed");
            //qDebug() << result;
        //return true;
     //   }
    //}
    return false;
}
