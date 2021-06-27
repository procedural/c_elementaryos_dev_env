# Tiny X11

```c
#include "tinyx11/tinyx11.h"
#include "killgnu/killgnu.h"

int main() {
  X11Display * d = XOpenDisplay(0);
  X11Window    w = XCreateSimpleWindow(d, d->screens[d->defaultScreen].root, 0, 0, 400, 400, 1, d->screens[d->defaultScreen].blackPixel, d->screens[d->defaultScreen].blackPixel);
  {
    X11Atom deleteAtom = XInternAtom(d, "WM_DELETE_WINDOW", 0);
    XSetWMProtocols(d, w, &deleteAtom, 1);
  }
  XSetStandardProperties(d, w, "tinyx11", "tinyx11", 0, 0, 0, 0);
  if (0) {
    X11Atom hintsAtom = XInternAtom(d, "_MOTIF_WM_HINTS", 0);
    X11MwmHints hints = {};
    hints.flags       = 2;
    hints.decorations = 0;
    XChangeProperty(d, w, hintsAtom, hintsAtom, 32, 0, &hints, 5);
  }
  if (0) {
    X11SizeHints * sizeHints = XAllocSizeHints();
    sizeHints->flags      = (1L << 4) | (1L << 5);
    sizeHints->min_width  = 400;
    sizeHints->max_width  = 400;
    sizeHints->min_height = 400;
    sizeHints->max_height = 400;
    XSetWMNormalHints(d, w, sizeHints);
    XFree(sizeHints);
  }
  XSelectInput(d, w, 15);
  XMapWindow(d, w);

  unsigned width     = 0;
  unsigned height    = 0;
  void *   imageData = 0;
  void *   image     = 0;
  unsigned frame     = 0;
  while (1) {
    if (1) {
      char frameChars[21];
      killGnuToCharsUInt32u(frame, frameChars);
      killGnuPrint("Frame: ");
      killGnuPrint(frameChars);
      killGnuPrint("\n");
    }

    while (XPending(d) > 0) {
      X11Event e = {};
      XNextEvent(d, &e);
      if (e.type == 33 || e.type == 17) {
        goto exit;
      }
      if (e.type == 2) {
        unsigned keycode = e.xkey.keycode;
        {
          char keycodeChars[21];
          killGnuToCharsUInt32u(keycode, keycodeChars);
          killGnuPrint("KeyboardKeyPress: ");
          killGnuPrint(keycodeChars);
          killGnuPrint("\n");
        }
      }
      if (e.type == 3) {
        int released = 1;
        if (XPending(d) > 0) {
          X11Event ne = {};
          XPeekEvent(d, &ne);
          if (ne.type == 2 && ne.xkey.time == e.xkey.time && ne.xkey.keycode == e.xkey.keycode) {
            XNextEvent(d, &e);
            released = 0;
          }
        }
        if (released == 1) {
          unsigned keycode = e.xkey.keycode;
          {
            char keycodeChars[21];
            killGnuToCharsUInt32u(keycode, keycodeChars);
            killGnuPrint("KeyboardKeyRelease: ");
            killGnuPrint(keycodeChars);
            killGnuPrint("\n");
          }
        }
      }
      if (e.type == 4) {
        unsigned button = e.xbutton.button;
        {
          char buttonChars[21];
          killGnuToCharsUInt32u(button, buttonChars);
          killGnuPrint("MouseButtonPress: ");
          killGnuPrint(buttonChars);
          killGnuPrint("\n");
        }
      }
      if (e.type == 5) {
        unsigned button = e.xbutton.button;
        {
          char buttonChars[21];
          killGnuToCharsUInt32u(button, buttonChars);
          killGnuPrint("MouseButtonRelease: ");
          killGnuPrint(buttonChars);
          killGnuPrint("\n");
        }
      }
    }

    if (1) {
      unsigned long root  = 0;
      unsigned long child = 0;
      int           gx    = 0;
      int           gy    = 0;
      int           x     = 0;
      int           y     = 0;
      unsigned      mask  = 0;
      XQueryPointer(d, w, &root, &child, &gx, &gy, &x, &y, &mask);
      char xChars[21];
      char yChars[21];
      char maskChars[33];
      maskChars[32] = 0;
      killGnuToCharsSInt32d(x, xChars);
      killGnuToCharsSInt32d(y, yChars);
      killGnuToCharsWithoutNullTerminatorBinary32(mask, maskChars);
      killGnuPrint("Mouse x: ");
      killGnuPrint(xChars);
      killGnuPrint(", y: ");
      killGnuPrint(yChars);
      killGnuPrint(", mask: ");
      killGnuPrint(maskChars);
      killGnuPrint("\n");
    }

    unsigned previousWidth  = width;
    unsigned previousHeight = height;

    unsigned long root        = 0;
    int           x           = 0;
    int           y           = 0;
    unsigned      borderWidth = 0;
    unsigned      depth       = 0;
    XGetGeometry(d, w, &root, &x, &y, &width, &height, &borderWidth, &depth);
    if (1) {
      char widthChars[21];
      char heightChars[21];
      killGnuToCharsUInt32u(width, widthChars);
      killGnuToCharsUInt32u(height, heightChars);
      killGnuPrint("Window width: ");
      killGnuPrint(widthChars);
      killGnuPrint(", height: ");
      killGnuPrint(heightChars);
      killGnuPrint("\n");
    }

    if (width != previousWidth || height != previousHeight) {
      if (image != 0) {
        killGnuFree(imageData);
        XFree(image);
      }
      imageData = killGnuMalloc(width * height * 4 * sizeof(unsigned char));
      image = XCreateImage(d, d->screens[d->defaultScreen].rootVisual, d->screens[d->defaultScreen].rootDepth, 2, 0, imageData, width, height, 32, 0);
    }
    for (unsigned y = 0; y < height; y += 1) {
      for (unsigned x = 0; x < width; x += 1) {
        XPutPixel(image, x, y, 255*256*256 + 0*256 + 255);
      }
    }
    XPutImage(d, w, d->screens[d->defaultScreen].defaultGc, image, 0, 0, 0, 0, width, height);

    frame += 1;
  }

exit:;

  killGnuFree(imageData);
  XFree(image);
  XDestroyWindow(d, w);
  XCloseDisplay(d);
}
```

```
cc main.c -nostdinc -nostdlib -fno-stack-protector -fno-asynchronous-unwind-tables killgnu/libkillgnu.a /usr/lib/x86_64-linux-gnu/libX11.so
```

```
$ valgrind ./a.out 
==9108== Memcheck, a memory error detector
==9108== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==9108== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
==9108== Command: ./a.out
==9108== 
Frame: 0
Mouse x: 40, y: -4, mask: 00000000000000000000000000000000
Window width: 400, height: 400
Frame: 1
Mouse x: 41, y: -4, mask: 00000000000000000000000000000000
Window width: 400, height: 400
Frame: 2
Mouse x: 41, y: -4, mask: 00000000000000000000000000000000
Window width: 400, height: 400
Frame: 3
Mouse x: 41, y: -4, mask: 00000000000000000000000000000000
Window width: 400, height: 400
Frame: 4
Mouse x: 43, y: -6, mask: 00000000000000000000000000000000
Window width: 400, height: 400
Frame: 5
Mouse x: 43, y: -7, mask: 00000000000000000000000000000000
Window width: 400, height: 400
Frame: 6
Mouse x: 42, y: -11, mask: 00000000000000000000000000000000
Window width: 400, height: 400
Frame: 7
Mouse x: 37, y: -17, mask: 00000000000000000000000000000000
Window width: 400, height: 400
Frame: 8
Mouse x: 27, y: -21, mask: 00000000000000000000000000000000
Window width: 400, height: 400
Frame: 9
Mouse x: 23, y: -22, mask: 00000000000000000000000000000000
Window width: 400, height: 400
Frame: 10
Mouse x: 22, y: -23, mask: 00000000000000000000000000000000
Window width: 400, height: 400
Frame: 11
Mouse x: 20, y: -25, mask: 00000000000000000000000000000000
Window width: 400, height: 400
Frame: 12
Mouse x: 16, y: -26, mask: 00000000000000000000000000000000
Window width: 400, height: 400
Frame: 13
Mouse x: 12, y: -27, mask: 00000000000000000000000000000000
Window width: 400, height: 400
Frame: 14
Mouse x: 7, y: -28, mask: 00000000000000000000000000000000
Window width: 400, height: 400
Frame: 15
Mouse x: 3, y: -31, mask: 00000000000000000000000000000000
Window width: 400, height: 400
Frame: 16
Mouse x: 1, y: -33, mask: 00000000000000000000000000000000
Window width: 400, height: 400
Frame: 17
Mouse x: 1, y: -33, mask: 00000000000000000000000000000000
Window width: 400, height: 400
Frame: 18
Mouse x: 1, y: -33, mask: 00000000000000000000000000000000
Window width: 400, height: 400
Frame: 19
Mouse x: 1, y: -33, mask: 00000000000000000000000000000000
Window width: 400, height: 400
Frame: 20
Mouse x: 1, y: -33, mask: 00000000000000000000000100000000
Window width: 400, height: 400
Frame: 21
Mouse x: 1, y: -33, mask: 00000000000000000000000100000000
Window width: 400, height: 400
Frame: 22
Mouse x: 1, y: -33, mask: 00000000000000000000000100000000
Window width: 400, height: 400
Frame: 23
Mouse x: 1, y: -33, mask: 00000000000000000000000100000000
Window width: 401, height: 400
Frame: 24
Mouse x: -8, y: -28, mask: 00000000000000000000000100000000
Window width: 401, height: 400
Frame: 25
Mouse x: -8, y: -27, mask: 00000000000000000000000100000000
Window width: 413, height: 393
Frame: 26
Mouse x: -17, y: -26, mask: 00000000000000000000000100000000
Window width: 434, height: 384
Frame: 27
Mouse x: -90, y: -22, mask: 00000000000000000000000100000000
Window width: 434, height: 384
Frame: 28
Mouse x: -83, y: -54, mask: 00000000000000000000000100000000
Window width: 525, height: 373
Frame: 29
Mouse x: -8, y: -58, mask: 00000000000000000000000100000000
Window width: 620, height: 403
Frame: 30
Mouse x: 28, y: -41, mask: 00000000000000000000000100000000
Window width: 625, height: 439
Frame: 31
Mouse x: 61, y: -22, mask: 00000000000000000000000100000000
Window width: 569, height: 444
Frame: 32
Mouse x: 20, y: -16, mask: 00000000000000000000000100000000
Window width: 494, height: 428
Frame: 33
Mouse x: -14, y: -21, mask: 00000000000000000000000100000000
Window width: 475, height: 411
Frame: 34
Mouse x: -32, y: -32, mask: 00000000000000000000000100000000
Window width: 490, height: 399
Frame: 35
Mouse x: -18, y: -38, mask: 00000000000000000000000100000000
Window width: 542, height: 400
Frame: 36
Mouse x: 4, y: -32, mask: 00000000000000000000000000000000
Window width: 562, height: 405
Frame: 37
Mouse x: 59, y: -13, mask: 00000000000000000000000000000000
Window width: 562, height: 405
Frame: 38
Mouse x: 113, y: 25, mask: 00000000000000000000000000000000
Window width: 562, height: 405
Frame: 39
Mouse x: 153, y: 82, mask: 00000000000000000000000000000000
Window width: 562, height: 405
Frame: 40
Mouse x: 158, y: 104, mask: 00000000000000000000000000000000
Window width: 562, height: 405
Frame: 41
Mouse x: 158, y: 106, mask: 00000000000000000000000000000000
Window width: 562, height: 405
Frame: 42
MouseButtonPress: 1
KeyboardKeyPress: 64
MouseButtonRelease: 1
Mouse x: 156, y: 110, mask: 00000000000000000000000000001000
Window width: 562, height: 405
Frame: 43
==9108== 
==9108== HEAP SUMMARY:
==9108==     in use at exit: 0 bytes in 0 blocks
==9108==   total heap usage: 351 allocs, 351 frees, 90,585 bytes allocated
==9108== 
==9108== All heap blocks were freed -- no leaks are possible
==9108== 
==9108== For counts of detected and suppressed errors, rerun with: -v
==9108== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
