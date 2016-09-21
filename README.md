# Magic Keys

###==Under Development==
> This project is under active development and is not yet ready for public use. A lot of the features will work, but it is likely to have a lot of unimplemented features at this time.

Magic Keys is an open source programmable keypad. The hardware is based on the Digispark/Arduino platform using the ATtiny85 microcontroller and a cheap button pad. A custom PCB was designed to attach to the button pad. The Eagle source files are in the hardware folder.

####How It Works
The Attiny85 acts as a USB HID device and communicates button presses to the computer. There is a Node JS app (located in the app folder) that runs in the background. When a key is pressed, the NodeJS app will run the script associated with the button in the app/keys folder. (Key1 = 1.js etc). All you have to do is put the code you want to run on a button press in the appropriate button file and it will run on press. [RobotJS](https://github.com/octalmage/robotjs)  is automatically included in each one of those files, without needing to declare it. So, if you want a key to type Hello World. The only code needed in the key file is:
```
robot.typeString("Hello World");
```
Now, every time you push that button, it will type Hello World.


####Plans
- Make a GUI app based on electron to make it easy to swap button functions on the fly
- Include a lot of example functions
- Make and sell complete keypads (open source)

####Install
Coming soon.


#####Ubuntu/Linux
**Permissions**
Linux requires some permissions to access the usb devices directly. Create this file `/etc/udev/rules.d/49-magickeys.rules` and add the following line to it to grant the proper permissions.
`SUBSYSTEMS=="usb", ATTRS{idVendor}=="16c0", ATTRS{idProduct}=="05df", MODE:="0666"`
Then you can reload the rules with `sudo udevadm control --reload-rules`
You may need to reboot your system if the rules reload does not work. 