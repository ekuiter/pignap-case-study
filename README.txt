PIGNAP
======

PIGNAP is developed inside a Linux virtual machine with Vagrant/VirtualBox. This allows much faster compile times than on Windows (1min vs. 20min. on my machine) and easy setup/reproducible builds.

- Install VirtualBox (https://www.virtualbox.org/wiki/Downloads) and Vagrant (https://www.vagrantup.com/downloads.html).
- Open a Windows command line (cmd.exe) and navigate to the PIGNAP folder with "cd".
- Run "set PORT=COM*" - COM* should be the Windows COM port where the ESP32 is connected (see Windows device manager).
- Run "vagrant up". This starts the virtual machine. On the first time, ESP-IDF is installed which may take a while. (This only works when the ESP32 is actually connected.)
- Run "vagrant ssh". This starts a Linux shell inside the virtual machine. From this shell, PIGNAP can be flashed and compiled:
  - "make" builds the project (on the first time, this takes a while)
  - "make flash" flashes it to the ESP32
  - "make monitor" opens a serial console
- To exit the Linux shell, run "exit". After that, stop the virtual machine with "vagrant halt".

To summarize: Set the COM port, run "vagrant up" and "vagrant ssh", "make flash", "exit" and "vagrant halt".