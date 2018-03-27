/*  PadNull
 *  Copyright (C) 2004-2009 PCSX2 Team
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */
#if defined(__APPLE__)
#include "Darwin/LinuxCompat.h"
#else
#include <gdk/gdkx.h>
#endif
#include "PadLinux.h"

Display *GSdsp;
int autoRepeatMode;

void _PadUpdate(int pad)
{
    KeySym key;

#if defined(__APPLE__)
  	GdkEvent *evt;

  	while ((evt = gdk_event_get()) != NULL) {
        switch (evt->type) {
#else
    XEvent evt;

    // keyboard input
    while (XPending(GSdsp) > 0) {
        XNextEvent(GSdsp, &evt);
        switch (evt.type) {
#endif
            case KeyPress:
#if defined(__APPLE__)
				        key = evt->key.keyval;
#else
                key = XLookupKeysym((XKeyEvent *)&evt, 0);
#endif

                // Add code to check if it's one of the keys we configured here on a real pda plugin..

                event.evt = KEYPRESS;
                event.key = key;
                break;

            case KeyRelease:
#if defined(__APPLE__)
				        key = evt->key.keyval;
#else
                key = XLookupKeysym((XKeyEvent *)&evt, 0);
#endif

                // Add code to check if it's one of the keys we configured here on a real pda plugin..

                event.evt = KEYRELEASE;
                event.key = key;
                break;

#if !defined(__APPLE__)
            case FocusIn:
                XAutoRepeatOff(GSdsp);
                break;
#endif

            case FocusOut:
                XAutoRepeatOn(GSdsp);
                break;
        }
    }
}

s32 _PADOpen(void *pDsp)
{

    GtkScrolledWindow *win;

    win = *(GtkScrolledWindow **)pDsp;

#if defined(__APPLE__)
		GSdsp = gdk_display_get_default();
#else
    if (GTK_IS_WIDGET(win)) {
        // Since we have a GtkScrolledWindow, for now we'll grab whatever display
        // comes along instead. Later, we can fiddle with this, but I'm not sure the
        // best way to get a Display* out of a GtkScrolledWindow. A GtkWindow I might
        // be able to manage... --arcum42
        GSdsp = GDK_DISPLAY_XDISPLAY(gdk_display_get_default());
    } else {
        GSdsp = *(Display **)pDsp;
    }
#endif

    XAutoRepeatOff(GSdsp);

    return 0;
}

void _PADClose()
{
    XAutoRepeatOn(GSdsp);
}
