# Magic Keys


Magic Keys is an open source programmable keypad. The hardware is based on the Digispark/Arduino platform using the ATtiny85 microcontroller and a cheap button pad. A custom PCB was designed to attach to the button pad. The Eagle source files are in the hardware folder. We are in the process of designing our own button pad and they should be avaliable in the next few months.

####How It Works
The Attiny85 acts as a USB HID device and communicates button presses to the computer. There is a Node JS app (located in the app folder) that runs in the background. When a key is pressed, the NodeJS app will run the script associated with the button in the app/keys folder. (Key1 = 1.js etc). All you have to do is put the code you want to run on a button press in the appropriate button file and it will run on press. [RobotJS](https://github.com/octalmage/robotjs)  is automatically included in each one of those files, without needing to declare it. So, if you want a key to type Hello World. The only code needed in the key file is:
```
robot.typeString("Hello World");
```
Now, every time you push that button, it will type Hello World.

#### Required Hardware
The source files for the custom Magic Keys board located in the hardware folder is designed to solder onto 2 different keypad modules by RobotDyn. [4x4 module](http://robotdyn.com/catalog/buttons_control/button_keypad_4x4_module/) and [3x4 module](http://robotdyn.com/catalog/buttons_control/button_keypad_3x4_module/). We will be selling the addon board as well as a complete button pad shortly. For now, you can use a Digispark or roll your own pcb based on the design files provided.

####Plans
- Make a GUI app based on electron to make it easy to swap button functions on the fly
- Include a lot of example functions
- Make and sell complete keypads (open source)

####Install
######Hardware
>(Note: We are in the process of getting our own VID/PID and will compile complete firmware without the Digispark loader as soon as we have it. This process will change and become much easier.)

First you need Arduino with the Digispark board addon. [Instructions can be found here.](http://digistump.com/wiki/digispark/tutorials/connecting) You need to burn the micronucleus bootloader on the ATiny85 (v1.11) [located here.](https://github.com/micronucleus/micronucleus/tree/v1.11/firmware/releases). I highly recommend not disabling the reset fuse as the extra pin is not needed for this project.

Then, you need to load the code located in the arduino/MagicKeys folder onto the board.

######Software
You need to install [NodeJS](https://nodejs.org/en/). This was tested with v4.5.0 but should work with any version v0.8.0 and up. 
Navigate to the app directory and run:
```
npm install
```
When that is done, all you have to do is run:
```
node index.js
```
And the program should begin to run and look for your device. When a button is pressed, the javascript code in the keys directory for your button will run.


######Ubuntu/Linux
**Permissions**
Linux requires some permissions to access the usb devices directly. Create this file `/etc/udev/rules.d/49-magickeys.rules` and add the following line to it to grant the proper permissions.
`SUBSYSTEMS=="usb", ATTRS{idVendor}=="16c0", ATTRS{idProduct}=="05df", MODE:="0666"`
Then you can reload the rules with `sudo udevadm control --reload-rules`
You may need to reboot your system if the rules reload does not work. 