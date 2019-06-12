PIGNAP
======

PIGNAP is developed inside a Linux virtual machine (VM) with Vagrant/VirtualBox. This allows much faster compile times than on Windows (1min vs. 20min. on my machine) and easy setup/reproducible builds.

Requirements
============

- Install VirtualBox (https://www.virtualbox.org/wiki/Downloads) and Vagrant (https://www.vagrantup.com/downloads.html). Tested with VirtualBox 6.0.8 and Vagrant 2.2.4.
- Install the VirtualBox Extension Pack (https://www.virtualbox.org/wiki/Downloads). (The version must be the same as VirtualBox!)

Script Usage
============

Some scripts are included for easy usage:

- flash.bat: Starts the VM (if not yet running) and flashes the software to the ESP32.
- shell.bat: Starts the VM (if not yet running) and opens a shell. See below.
- halt.bat: Stops the VM. Use this after flashing is done and the VM is no more needed.
- reset.bat: Completely removes the VM.

Manual Usage
============

- Open a Windows command line (cmd.exe) and navigate to the PIGNAP folder with "cd".
- Run "vagrant up". This starts the VM. On the first time, ESP-IDF is installed which may take a while.
- Run "vagrant ssh". This starts a Linux shell inside the VM. From this shell, PIGNAP can be flashed and compiled:
  - "make" builds the project (on the first time, this takes a while)
  - "make flash" flashes it to the ESP32
  - "make monitor" opens a serial console
- To exit the Linux shell, run "exit". After that, stop the VM with "vagrant halt".

Flashing
========

Flashing is only possible if "CP210x UART Bridge" shows up when running "lsusb". If not, remove and reconnect the ESP32 and try again.
When the VM is running, the ESP32 is NOT available in Windows. To get it back as a COM port, stop the VM with "vagrant halt".

If flashing fails with the error message "Failed to connect to ESP32: Timed out waiting for packet header", try to hold down the BOOT button on the ESP32 board while flashing (see https://www.esp32.com/viewtopic.php?t=9731). Alternatively, you can flash directly from Windows, but this requires manual setup of esptool.

Resetting the VM
================

In the PIGNAP folder, run "vagrant destroy". This will completely remove the VM.
Then remove the ".vagrant" and "build" folders.
Run "vagrant up" to reinitialize the VM.