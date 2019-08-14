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
    process.startDetached("xterm");
}else if(message==Message::Error){
    process.startDetached("xterm");
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
