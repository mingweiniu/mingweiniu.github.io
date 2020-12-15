/*
 * edit from 《Linux C/C++視窗程式設計－使用GTK+與Qt》
 * compile with linux
 * gcc win_mouse.c -o DemoWin -lXext -lX11 -g -Wall -O3 
 */

//c lib
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//X11 lib
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <X11/Xatom.h>
#include <X11/keysym.h> 

int main(int argc, char **argv){
    char *display_name = NULL;
    Display *theDis = XOpenDisplay(display_name);// Open a display.
    if (!theDis) exit(0); //you can put error message here
    int theScreenNum;
    Window theWin = XCreateSimpleWindow(
        theDis,
        RootWindow(theDis, theScreenNum),
        0, 0, 200, 100, 0,
        BlackPixel(theDis, theScreenNum),
        WhitePixel(theDis , theScreenNum));
    XStoreName(theDis, theWin, "hello");  

//Set fonts
    const char *hello = "hello Xwindow";
    GC theGC=DefaultGC(theDis, theScreenNum);
    XFontStruct *fontinfo;
    fontinfo =  XQueryFont(theDis,XGContextFromGC(theGC));
    int textWidth = XTextWidth(fontinfo, hello, strlen(hello));
    int textHeight = fontinfo->ascent + fontinfo->descent;
//set mask      
    XSelectInput(theDis, theWin,ExposureMask | KeyPressMask | ButtonPressMask);
    XMapWindow(theDis , theWin); 

//make atom to comminucate to window manager
    Atom wm_protocols = XInternAtom(theDis, "WM_PROTOCOLS",0);
    Atom wm_delwindow = XInternAtom(theDis, "WM_DELETE_WINDOW",0);
//deal with events
    bool looping = 1;
    XEvent event;
    while(looping){
        XNextEvent(theDis, &event);
        switch(event.type){
        case Expose :
            if(event.xany.window == theWin){
                Window root;
                int xreturn, yreturn;
                unsigned int w, h;
                unsigned int width_return, depth_return;
                XGetGeometry(theDis, theWin, &root,
                    &xreturn,&yreturn, &w, &h,
                    &width_return, &depth_return);
                XDrawString(theDis, theWin, theGC,
                    (w - textWidth)/2,
                    (h + textHeight)/2,
                    hello, strlen(hello));
                XFlush(theDis);
            }break;
        case ButtonPress:
            looping = 0;break;
        case ClientMessage:
            if((event.xclient.message_type == wm_protocols)
                &&(event.xclient.format == 32)){
                Atom a = event.xclient.data.l[0];
                if(a==wm_delwindow) looping = 0;
            }break;
        }
    } 
//close the window
    XDestroyWindow(theDis , theWin);
    XFlush(theDis);
    XCloseDisplay(theDis);
//end of cpp
   return 0;
}
