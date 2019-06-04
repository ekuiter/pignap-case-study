PIGNAP
======

- Install ESP-IDF according to https://docs.espressif.com/projects/esp-idf/en/stable/get-started/index.html.
- Start a terminal (C:\msys2\mingw32.exe, NOT cmd.exe or msys2.exe).
- Make sure the IDF_PATH environment variable is set to ESP-IDF with "echo $IDF_PATH".
- Go to the PIGNAP folder with "cd".
- "make" builds the project
- "make flash" flashes it to the ESP32
- "make monitor" opens a serial console

Notes:
- The first "make" can take a while because it compiles the entire ESP-IDF. Subsequent "make" is faster.
- On the first "make", a menu is opened that allows to set SDK options.
  The only option that MUST be configured is the serial port for flashing:
  Serial flasher config > Default serial port > COM...
  Then choose "Save" and "Exit", this generates an "sdkconfig" file which is used in subsequent builds.