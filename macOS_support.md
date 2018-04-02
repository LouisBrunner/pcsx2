# macOS support roadmap

## Done

 - Compiling core
 - Compiling null plugins
 - Running PCSX2
 - Loading plugins
 - Configure plugins
 - Change Documents location

 - Hang when quitting from main window + Semaphore Wait aborts -> waiting for MTVU to be canceled (but it is blocked on a semaphore, deadlock) -> make semaphore timeout regularly + call pthread_testcancel

## To do

 - Crash on null plugins configure -> gtk problem
 - Crash when quitting from console log -> wxWindow bug when deleting MainEmuFrame, probably linked to thread block/cancel (see hang on quitting main window)
 - Block on onepad rebinding -> key not detected, blocking on gamepad stuff
 - Load Game -> hang then crash on recompiled stuff, no idea

 - Package mode
 - Compiling sound plugins

 - Compiling graphic plugins
