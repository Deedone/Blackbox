#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/keysym.h>
#include <stdlib.h>
#include <stdio.h>




int main() {

	Display *d;
	Window w;
	XEvent e;
	int s;

	d = XOpenDisplay(NULL);

	if (d == NULL) {
		printf("Can't open display\n");
		return 1;
	}

	s = DefaultScreen(d);

	w = XCreateSimpleWindow(d, RootWindow(d, s), 0, 0, 100, 100, 1, BlackPixel(d, s), BlackPixel(d, s));
	XSelectInput(d, w, ExposureMask | KeyPressMask  );
	XMapWindow(d, w);

	Atom wmDelete=XInternAtom(d, "WM_DELETE_WINDOW", True);
	XSetWMProtocols(d, w, &wmDelete, 1);
	XmbSetWMProperties(d, w, "BLACKBOX",0,0,0,0,0,0);

	while (1) {
		XNextEvent(d, &e);
		if (e.type == KeyPress && e.xkey.keycode == XKeysymToKeycode(d, XK_Escape)) {
			printf("Keypress %d\n", e.xkey.keycode);
			break;
		}

		if (e.type == ClientMessage) 
			break;
	}

	XCloseDisplay(d);
	return 0;


}
