#ifndef X11_COMPATIBILITY_H
#define X11_COMPATIBILITY_H

#if defined(__APPLE__)

#include <gdk/gdk.h>
typedef GdkDisplay Display;
typedef GdkWindow Window;
#define XKeysymToString gdk_keyval_name
// TODO: lb
#define XResetScreenSaver(x)

#define KeySym guint
#define KeyPress GDK_KEY_PRESS
#define KeyRelease GDK_KEY_RELEASE
#define ButtonPress GDK_BUTTON_PRESS
#define ButtonRelease GDK_BUTTON_RELEASE
#define MotionNotify GDK_MOTION_NOTIFY
#define FocusIn GDK_FOCUS_CHANGE
#define FocusOut GDK_FOCUS_CHANGE

#define XAutoRepeatOff(x)
#define XAutoRepeatOn(x)
#define XCloseDisplay gdk_display_close

#include <gdk/gdkkeysyms.h>
#define XK_Escape GDK_KEY_Escape

#define XK_Alt_L GDK_KEY_Alt_L
#define XK_Alt_R GDK_KEY_Alt_R

#define XK_Shift_L GDK_KEY_Shift_L
#define XK_Shift_R GDK_KEY_Shift_R

#define XK_a GDK_KEY_a
#define XK_e GDK_KEY_e
#define XK_d GDK_KEY_d
#define XK_f GDK_KEY_f
#define XK_i GDK_KEY_i
#define XK_j GDK_KEY_j
#define XK_k GDK_KEY_k
#define XK_l GDK_KEY_l
#define XK_n GDK_KEY_n
#define XK_p GDK_KEY_p
#define XK_s GDK_KEY_s
#define XK_v GDK_KEY_v
#define XK_w GDK_KEY_w

#define XK_semicolon GDK_KEY_semicolon

#define XK_F5 GDK_KEY_F5
#define XK_F6 GDK_KEY_F6
#define XK_F7 GDK_KEY_F7
#define XK_F8 GDK_KEY_F8
#define XK_F9 GDK_KEY_F9
#define XK_F12 GDK_KEY_F12

#include <os/lock.h>
#define pthread_spinlock_t os_unfair_lock
#define pthread_spin_init(x, y) *x = OS_UNFAIR_LOCK_INIT
#define pthread_spin_lock(x) os_unfair_lock_lock(x);
#define pthread_spin_unlock(x) os_unfair_lock_unlock(x);
#define pthread_spin_destroy(x)

#endif

#endif
