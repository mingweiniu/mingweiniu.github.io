/*
 * edit from 《Linux C/C++視窗程式設計－使用GTK+與Qt》
 * compile on linux
 * gcc DemoWin.c -lX11 
 */

//c lib
#include <stdlib.h>
#include <unistd.h>
//X11 lib
#include <X11/Xlib.h>

int main(int argc, char **argv){
//argue a space
    Display *theDis;
    theDis = XOpenDisplay(NULL);// Open a display.
    if (!theDis) exit(0); //you can put error message here
//create the window, or you can use XCreateWindow()
    int theScreenNum = 0;
    Window theWin = XCreateSimpleWindow(
        theDis,
        RootWindow(theDis, theScreenNum),
        0, 0, 200, 100, 0,
        BlackPixel(theDis, theScreenNum),
        WhitePixel(theDis , theScreenNum));  
//set window name
    XStoreName(theDis, theWin, "hello");
//show the window
    XMapWindow(theDis , theWin);
    XFlush(theDis);
    sleep(5);
//close the window
    XDestroyWindow(theDis , theWin);
    XCloseDisplay(theDis);
//end of cpp
   return 0;
}
