#ifndef INFO_H
#define INFO_H

#include <QObject>

class Info : public QObject
{
    Q_OBJECT
public:
    enum State {
        Information,
        Debug,
        Warning,
        Error
    };
    Q_ENUM(State)
};


#endif // INFO_H
