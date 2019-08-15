#include<X11/Xlib.h>
#include<stdio.h>
#include<sys/types.h>
pid_t  pid, pid1, pid2;
void aaa (void){
    if (pid2==0) system("mplayer");
}
void bbb (void){
    if (pid1==0) system("quicknanobrowser -geometry 550x350+90-0");
}
void ccc (void){
    if (pid==0) system("xterm -fa 'Monospace' -fs 8");
}
void ddd (void){
system("xdo");
}




int main(void)
{
    Display * dpy;
    XEvent ev;

    if(!(dpy = XOpenDisplay(0x0))) return 1;

    XGrabKey(dpy, XKeysymToKeycode(dpy, XStringToKeysym("F11")), Mod1Mask,
            DefaultRootWindow(dpy), True, GrabModeAsync, GrabModeAsync);
    XGrabKey(dpy, XKeysymToKeycode(dpy, XStringToKeysym("F12")), Mod1Mask,
        DefaultRootWindow(dpy), True, GrabModeAsync, GrabModeAsync);
    XGrabKey(dpy, XKeysymToKeycode(dpy, XStringToKeysym("F3")), Mod1Mask,
        DefaultRootWindow(dpy), True, GrabModeAsync, GrabModeAsync);
    XGrabKey(dpy, XKeysymToKeycode(dpy, XStringToKeysym("q")), Mod1Mask,
        DefaultRootWindow(dpy), True, GrabModeAsync, GrabModeAsync);
    XGrabKey(dpy, XKeysymToKeycode(dpy, XStringToKeysym("t")), Mod1Mask,
            DefaultRootWindow(dpy), True, GrabModeAsync, GrabModeAsync);
    XGrabKey(dpy, XKeysymToKeycode(dpy, XStringToKeysym("f")), Mod1Mask,
            DefaultRootWindow(dpy), True, GrabModeAsync, GrabModeAsync);




    for(;;)
    {
        XNextEvent(dpy, &ev);
        if(ev.type == KeyPress){
        if (ev.xkey.keycode==XKeysymToKeycode(dpy, XStringToKeysym("F11"))) system("amixer set Master 2dB-");
	if (ev.xkey.keycode==XKeysymToKeycode(dpy, XStringToKeysym("F12"))) system("amixer set Master 2dB+");
        if (ev.xkey.keycode==69) {
              pid2=fork();
              aaa();
        }
        if (ev.xkey.keycode==XKeysymToKeycode(dpy, XStringToKeysym("q"))) {
               pid1=fork();
               bbb();
        }
        if (ev.xkey.keycode==XKeysymToKeycode(dpy, XStringToKeysym("t"))) {
               pid=fork();
                ccc();

        }
        if (ev.xkey.keycode==XKeysymToKeycode(dpy, XStringToKeysym("f"))){
           fork();
                ddd();


        }
	}
    }
}

