#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned long X11Atom;
typedef unsigned long X11Window;

typedef struct X11Screen {
  void *        private0;
  void *        display;
  X11Window     root;
  int           width;
  int           height;
  int           mwidth;
  int           mheight;
  int           depthsCount;
  void *        depths;
  int           rootDepth;
  void *        rootVisual;
  unsigned long defaultGc;
  unsigned long cmap;
  unsigned long whitePixel;
  unsigned long blackPixel;
  int           maxMaps;
  int           minMaps;
  int           backingStore;
  int           saveUnders;
  long          rootInputMask;
} X11Screen;

typedef struct X11Display {
  void *        private0;
  void *        private1;
  int           fd;
  int           private2;
  int           protoMajorVersion;
  int           protoMinorVersion;
  char *        vendor;
  unsigned long private3;
  unsigned long private4;
  unsigned long private5;
  int           private6;
  void *        resourceAlloc;
  int           byteOrder;
  int           bitmapUnit;
  int           bitmapPad;
  int           bitmapBitOrder;
  int           formatsCount;
  void *        pixmapFormat;
  int           private8;
  int           release;
  void *        private9;
  void *        private10;
  int           qlen;
  unsigned long lastRequestRead;
  unsigned long request;
  void *        private11;
  void *        private12;
  void *        private13;
  void *        private14;
  unsigned      maxRequestSize;
  void *        db;
  void *        private15;
  char *        displayName;
  int           defaultScreen;
  int           screensCount;
  X11Screen *   screens;
  unsigned long motionBuffer;
  unsigned long private16;
  int           minKeycode;
  int           maxKeycode;
  void *        private17;
  void *        private18;
  int           private19;
  char *        xdefaults;
} X11Display;

typedef struct X11AnyEvent {
  int           type;
  unsigned long serial;
  int           sendEvent;
  X11Display *  display;
  X11Window     window;
} X11AnyEvent;

typedef struct X11KeyEvent {
  int           type;
  unsigned long serial;
  int           sendEvent;
  X11Display *  display;
  X11Window     window;
  X11Window     root;
  X11Window     subwindow;
  unsigned long time;
  int           x;
  int           y;
  int           xRoot;
  int           yRoot;
  unsigned int  state;
  unsigned int  keycode;
  int           sameScreen;
} X11KeyEvent;

typedef struct X11ButtonEvent {
  int           type;
  unsigned long serial;
  int           sendEvent;
  X11Display *  display;
  X11Window     window;
  X11Window     root;
  X11Window     subwindow;
  unsigned long time;
  int           x;
  int           y;
  int           xRoot;
  int           yRoot;
  unsigned int  state;
  unsigned int  button;
  int           sameScreen;
} X11ButtonEvent;

typedef union X11Event {
  int            type;
  X11AnyEvent    xany;
  X11KeyEvent    xkey;
  X11ButtonEvent xbutton;
  int            private0[48];
} X11Event;

typedef struct X11MwmHints {
  unsigned long flags;
  unsigned long functions;
  unsigned long decorations;
  long          inputMode;
  unsigned long status;
} X11MwmHints;

typedef struct X11SizeHints {
  long  flags;
  int   x;
  int   y;
  int   width;
  int   height;
  int   min_width;
  int   min_height;
  int   max_width;
  int   max_height;
  int   width_inc;
  int   height_inc;
  struct {
    int x;
    int y;
  }     min_aspect;
  struct {
    int x;
    int y;
  }     max_aspect;
  int   base_width;
  int   base_height;
  int   win_gravity;
} X11SizeHints;

X11Display *   XOpenDisplay           (const char * displayName);
X11Window      XCreateSimpleWindow    (X11Display * display, X11Window parent, int x, int y, unsigned width, unsigned height, unsigned borderWidth, unsigned long border, unsigned long background);
X11Atom        XInternAtom            (X11Display * display, const char * atomName, int onlyIfExists);
int            XSetWMProtocols        (X11Display * display, X11Window window, X11Atom * protocols, int count);
int            XSetStandardProperties (X11Display * display, X11Window window, const char * windowName, const char * iconName, unsigned long iconPixmap, char ** argv, int argc, X11SizeHints * hints);
int            XChangeProperty        (X11Display * display, X11Window window, X11Atom property, X11Atom type, int format, int mode, const void * data, int elementsCount);
int            XSelectInput           (X11Display * display, X11Window window, long eventMask);
int            XMapWindow             (X11Display * display, X11Window window);
int            XPending               (X11Display * display);
int            XNextEvent             (X11Display * display, X11Event * outEvent);
int            XPeekEvent             (X11Display * display, X11Event * outEvent);
int            XGetGeometry           (X11Display * display, X11Window window, X11Window * outRoot, int * outX, int * outY, unsigned * outWidth, unsigned * outHeight, unsigned * outBorderWidth, unsigned * outDepth);
int            XDestroyWindow         (X11Display * display, X11Window window);
int            XCloseDisplay          (X11Display * display);
X11SizeHints * XAllocSizeHints        (void);
void           XSetWMNormalHints      (X11Display * display, X11Window window, X11SizeHints * hints);
int            XFree                  (void * data);
void *         XCreateImage           (X11Display * display, void * visual, unsigned depth, int format, int offset, void * data, unsigned width, unsigned height, int bitmapPad, int bytesPerLine);
int            XPutPixel              (void * image, int x, int y, unsigned long pixel);
int            XPutImage              (X11Display * display, X11Window window, unsigned long gc, void * image, int sourceX, int sourceY, int targetX, int targetY, unsigned width, unsigned height);
int            XQueryPointer          (X11Display * display, X11Window window, X11Window * outRoot, X11Window * outChild, int * outRootX, int * outRootY, int * outWindowX, int * outWindowY, unsigned * outMask);

#ifdef __cplusplus
}
#endif