#include <QDebug>
#include "label.h"
#include "button.h"
#include "nativeeventfilter.h"
#include <QDebug>
#include <QMenu>
#include <QVector>
#include <QX11Info>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <xcb/xcb.h>
#include <QGridLayout>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
namespace
{
    Display * m_display;        // Соединение с сервером X11
    Window m_win;               // Захватываемое окно - в данном случае будет вся система
    int keycode, keycode1;                // код клавиши
    unsigned int modifier;      // код модификаторов

    /* Вектор дополнительных мfодификаторов Num Lock, Caps lock
     * Они тоже учитываются в X11, поэтому понадобяться все возможные комбинации
     * */
    QVector<quint32> maskModifiers(){
        return QVector<quint32>() << 0 << Mod2Mask << LockMask << (Mod2Mask | LockMask);
    
    }
        XWindowAttributes attr;
	 xcb_button_press_event_t *start;
	xcb_motion_notify_event_t *motion;        

}

NativeEventFilter::NativeEventFilter(/*QObject*/QWidget *parent) : /*QObject*/QWidget (parent)
{
    m_display = QX11Info::display();        // Создадим подключение к серверу
    m_win = DefaultRootWindow(m_display);   // и вытащим из него захватываемое окно с помощью макроса


    label *lbl=new label;
    lbl->setObjectName("lbl");
    //lbl->setStyleSheet("border-image:url(/media/sda3/usr/bin/battery-charged-icon.png)");
    lbl->setFixedSize(80,50);
    label *lbl1=new label;
    lbl1->setObjectName("lbl1");
    button *button1 = new button("Browser");
    button1->setStyleSheet("border-image:url(/media/sda3/usr/bin/intetnet.png);");
    button1->setFixedSize(80,50);
    connect(button1, &QPushButton::clicked, this, []{ 
    QProcess process; process.startDetached("browser --no-sandbox");});
    button *button2 = new button("Terminal");
    button2->setStyleSheet("border-image:url(/media/sda3/usr/bin/terminal-icon.png)");
    button2->setFixedSize(80,50);
    connect(button2, &QPushButton::clicked, this, []{
    QProcess process; process.startDetached("st");});
    button *button3 = new button("QtCreator");
    connect(button3, &QPushButton::clicked, this, []{
    QProcess process; process.startDetached("browser1 --no-sandbox");});
    button *button4 = new button("Dev-Tool");
    connect(button4, &QPushButton::clicked, this, []{
    QProcess process; process.startDetached("st -geometry 80x66+0+0");});
    button *button5 = new button("Off");
    button5->setStyleSheet("border-image:url(/media/sda3/usr/bin/Windows-Turn-Off-icon.png)");
    button5->setFixedSize(80,50);
    connect(button5, &QPushButton::clicked, this, []{
    QProcess process; process.start("init 0"); process.waitForFinished();});
    button *button6 = new button("Apps");
    QMenu *menu = new QMenu;
    button6->setMenu(menu);
    button6->menu()->addAction("test");
    connect(button6, &QPushButton::clicked, this, []{
    QProcess process; process.start("xterm");});

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(button1, 0, 0);
    layout->addWidget(button2, 1, 0);
    layout->addWidget(button3, 2, 0);
    layout->addWidget(button4, 3, 0);
    layout->addWidget(button6, 4, 0);
    layout->addWidget(button5, 5, 0);
    layout->addWidget(lbl,6,0);
    layout->addWidget(lbl1,7,0);
    setLayout(layout);
    show();

    connect(this, &NativeEventFilter::activated, this, []{QProcess process; process.startDetached("xalttab");qDebug() << "test";});

//QApplication::instance()->installNativeEventFilter(new NativeEventFilter);

    setShortcut();  
    setShortcut1();

}

bool NativeEventFilter::nativeEventFilter(const QByteArray &eventType, void *message, qintptr/* long int*/  *result)
{
  Q_UNUSED(eventType)
  Q_UNUSED(result)

    /* В вот обработка события строится уже на библиотеке XCB вместо Xlib.
     * Вроде как, получая событие Qt знает его в качестве XCB события,
     * но не знает его в качестве события Xlib, хотя использовать более
     * легкий синтаксис Xlib для установки хоткеев нам никто не запрещает
     * */
    xcb_key_press_event_t *keyEvent = 0;

    // Итак проверяем, что это было xcb событие
    if (eventType == "xcb_generic_event_t") {
        // кастуем сообщение собственно в xcb событие
        xcb_generic_event_t *event = static_cast<xcb_generic_event_t *>(message);

        // проверяем, что произошло нажатие клавиши
        //if ((event->response_type & 127) == XCB_KEY_PRESS){
	if ((event->response_type & 127) == XCB_BUTTON_PRESS){	
xcb_button_press_event_t* buttonPressEvent = static_cast<xcb_button_press_event_t*>(message);
   



                   
                   XRaiseWindow(m_display, buttonPressEvent->child);
    // int revert_to; 
      //    Time time; 
     XSetInputFocus(m_display, buttonPressEvent->child, RevertToNone, CurrentTime);


XGetWindowAttributes(m_display, buttonPressEvent->child, &attr);
start = buttonPressEvent;
//qDebug() << start->state;
	}
    if ((event->response_type & 127) == XCB_MOTION_NOTIFY){
	//	XCB_MOTION_NOTIFY

motion = static_cast<xcb_motion_notify_event_t *>(message);
int xdiff = motion->root_x - start->root_x;
int ydiff = motion->root_y - start->root_y;
//if(xdiff>50)xdiff=100;
//if(ydiff>50)ydiff=100;
    

if(motion->state==264)XMoveWindow(m_display, motion->child,attr.x+xdiff,attr.y+ydiff);

if(motion->state==1032)XResizeWindow(m_display, motion->child,MAX(1, attr.width +  xdiff),MAX(1, attr.height +  ydiff));

//XMoveResizeWindow(m_display, motion->child,attr.x+(motion->state==264 ? xdiff : 0),attr.y+(motion->state==264 ? ydiff : 0),MAX(1, attr.width + (motion->state==1032 ? xdiff : 0)),MAX(1, attr.height + (motion->state==1032 ? ydiff : 0)));



/* 
if((event->response_type & 127) == XCB_BUTTON_RELEASE)
          start->child = None;
*/
  /*  
	// Если так, то кастуем сообщение в событие нажатия клавиши
            keyEvent = static_cast<xcb_key_press_event_t *>(message);

            // Далее проверям, является ли это событие нужным хоткее
            foreach (quint32 maskMods, maskModifiers()) {
                if(keyEvent->state == (modifier | maskMods )
                      &&  keyEvent->detail == keycode ){
                    emit activated();   // и посылаем сигналe
                    return true;
                    }
                    }
                      
 */      
}
    if((event->response_type & 127) == XCB_BUTTON_RELEASE)
	  start->child = None;
           
        keyEvent = static_cast<xcb_key_press_event_t *>(message);
           
           foreach (quint32 maskMods, maskModifiers()) {
                if(keyEvent->state == (modifier | maskMods )
                      &&  (keyEvent->detail == keycode) )    {
                    emit activated();  
                   //slotGlobalHotkey();  
                  return true;
                }
            }

         
    }
    return false;
}

void NativeEventFilter::setShortcut()
{
    unsetShortcut();        /* Вначале для перестраховки отключим предполагаемый хоткей,
                             * даже несмотря на то, что будет мусор в первый раз в параметрах хоткея.
                             * */

    // получим код клавиши из KeySym определения и соединения с сервером X11
    keycode = XKeysymToKeycode(m_display, XK_Tab);
    modifier = ControlMask; // Зададим модификатор

    /* А теперь пройдемся по всем возможным комбинациям с учётом Num Lock и Caps Lock
     * устанавливая хоткеи
     * */
    foreach (quint32 maskMods, maskModifiers()) {
        XGrabKey(m_display,         // указываем соединение с X11
                 keycode ,          // код клавиши
                 modifier | maskMods,   // модификатор со всеми возможными масками
                 m_win,             // Захватываемое окно
                 True,              // Является ли приложение владельцем события. в данном примере не принципиально.
                 GrabModeAsync,     // Обязательно Ассинхронный режим обработки, иначе, рискуете встрять
                 GrabModeAsync);    // с замороженной системой, не реагирующей ни на какие воздействия, если
                                    // заранее не напишите корректную передачу события обратно в систему,
                                    // а скорее всего так и будет
    }
}

void NativeEventFilter::setShortcut1()
{
    //unsetShortcut();        /* Вначале для перестраховки отключим предполагаемый хоткей,
     //                        * даже несмотря на то, что будет мусор в первый раз в параметрах хоткея.
       //                      * */

    // получим код клавиши из KeySym определения и соединения с сервером X11
    keycode1 = XKeysymToKeycode(m_display, XK_Q);
    modifier = ControlMask; // Зададим модификатор

    /* А теперь пройдемся по всем возможным комбинациям с учётом Num Lock и Caps Lock
     * устанавливая хоткеи
     * */
    foreach (quint32 maskMods, maskModifiers()) {
        XGrabKey(m_display,         // указываем соединение с X11
                   keycode1 ,          // код клавиши
                   modifier | maskMods,   // модификатор со всеми возможными масками
                   m_win,             // Захватываемое окно
                   True,              // Является ли приложение владельцем события. в данном примере не принципиально.
                   GrabModeAsync,     // Обязательно Ассинхронный режим обработки, иначе, рискуете встрять
                   GrabModeAsync);    // с замороженной системой, не реагирующей ни на какие воздействия, если
                                    // заранее не напишите корректную передачу события обратно в систему,
                                    // а скорее всего так и будет
     XGrabButton(m_display, 1, Mod1Mask, m_win, True, ButtonPressMask|ButtonReleaseMask|PointerMotionMask, GrabModeAsync, GrabModeAsync, None, None);
	XGrabButton(m_display, 3, Mod1Mask, m_win, True, ButtonPressMask|ButtonReleaseMask|PointerMotionMask, GrabModeAsync, GrabModeAsync, None, None);
    }
}

void NativeEventFilter::unsetShortcut()
{
    // Проходим по всем возможным комбинациям и удаляем хоткей
    foreach (quint32 maskMods, maskModifiers()) {
       XUngrabKey(m_display,
                   keycode,
                   modifier | maskMods,
                   m_win);
    }
}
