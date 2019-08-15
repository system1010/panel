/* TinyWM is written by Nick Welch <nick@incise.org> in 2005 & 2011.
 *
 * This software is in the public domain
 * and is provided AS IS, with NO WARRANTY. */

#include <X11/Xlib.h>
#include<stdio.h>
#include<sys/types.h>
pid_t  pid, pid1, pid2;
void aaa (void){
	    if (pid2==0) system("mplayer");
}
void bbb (void){
	    if (pid1==0) system("qupzilla");
}
void ccc (void){
	    if (pid==0) system("xterm");
}
void ddd (void){
	system("xdo");
}




#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main(void)
{
    Display * dpy;
    XWindowAttributes attr;
    XButtonEvent start;
    XEvent ev;

    if(!(dpy = XOpenDisplay(0x0))) return 1;

    
    
    

 XGrabKey(dpy, XKeysymToKeycode(dpy, XStringToKeysym("F11")), Mod1Mask,
		             DefaultRootWindow(dpy), True, GrabModeAsync, GrabModeAsync);
     XGrabKey(dpy, XKeysymToKeycode(dpy, XStringToKeysym("F12")), Mod1Mask,
		             DefaultRootWindow(dpy), True, GrabModeAsync, GrabModeAsync);
         XGrabKey(dpy, XKeysymToKeycode(dpy, XStringToKeysym("F3")), Mod1Mask,
			         DefaultRootWindow(dpy), True, GrabModeAsync, GrabModeAsync);
	     XGrabKey(dpy, XKeysymToKeycode(dpy, XStringToKeysym("F4")), Mod1Mask,
			             DefaultRootWindow(dpy), True, GrabModeAsync, GrabModeAsync);
	         XGrabKey(dpy, XKeysymToKeycode(dpy, XStringToKeysym("F5")), Mod1Mask,
				             DefaultRootWindow(dpy), True, GrabModeAsync, GrabModeAsync);
		     XGrabKey(dpy, XKeysymToKeycode(dpy, XStringToKeysym("F6")), Mod1Mask,
				                 DefaultRootWindow(dpy), True, GrabModeAsync, GrabModeAsync);








    
    
    
    
    
    
    
    XGrabKey(dpy, XKeysymToKeycode(dpy, XStringToKeysym("F7")), Mod1Mask,
            DefaultRootWindow(dpy), True, GrabModeAsync, GrabModeAsync);
    XGrabButton(dpy, 1, Mod1Mask, DefaultRootWindow(dpy), True,
            ButtonPressMask|ButtonReleaseMask|PointerMotionMask, GrabModeAsync, GrabModeAsync, None, None);
    XGrabButton(dpy, 3, Mod1Mask, DefaultRootWindow(dpy), True,
            ButtonPressMask|ButtonReleaseMask|PointerMotionMask, GrabModeAsync, GrabModeAsync, None, None);

    start.subwindow = None;
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
				        if (ev.xkey.keycode==70) {
						               pid1=fork();
							                      bbb();
									              }
					        if (ev.xkey.keycode==71) {
							               pid=fork();
								                       ccc();

										               }
						        if (ev.xkey.keycode==72){
								           fork();
									                   ddd();


											           }


      if(ev.xkey.subwindow != None)
	                  XRaiseWindow(dpy, ev.xkey.subwindow);



							        }

















        //if(ev.type == KeyPress && ev.xkey.subwindow != None)
          //  XRaiseWindow(dpy, ev.xkey.subwindow);
        if(ev.type == ButtonPress && ev.xbutton.subwindow != None)
        {
            XGetWindowAttributes(dpy, ev.xbutton.subwindow, &attr);
            start = ev.xbutton;
        }
        else if(ev.type == MotionNotify && start.subwindow != None)
        {
            int xdiff = ev.xbutton.x_root - start.x_root;
            int ydiff = ev.xbutton.y_root - start.y_root;
            XMoveResizeWindow(dpy, start.subwindow,
                attr.x + (start.button==1 ? xdiff : 0),
                attr.y + (start.button==1 ? ydiff : 0),
                MAX(1, attr.width + (start.button==3 ? xdiff : 0)),
                MAX(1, attr.height + (start.button==3 ? ydiff : 0)));
        }
        else if(ev.type == ButtonRelease)
            start.subwindow = None;
    }
}

