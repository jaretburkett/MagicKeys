# Magic Keys

###==Under Construction==

Magic Keys is an open source programmable keypad. The hardware is based on the Digispark/Arduino platform using the ATtiny85 microcontroller and a cheap button pad.

####Plans
Have an easily hackable keypad to create and run macros quickly.

####Installation

#####Ubuntu/Linux
**Permissions**
Linux requires some permissions to access the usb devices directly. Create this file `/etc/udev/rules.d/49-magickeys.rules` and add the following line to it to grant the proper permissions.
`SUBSYSTEMS=="usb", ATTRS{idVendor}=="16c0", ATTRS{idProduct}=="05df", MODE:="0666"`
Then you can reload the rules with `sudo udevadm control --reload-rules`
You may need to reboot your system if the rules reload does not work. 