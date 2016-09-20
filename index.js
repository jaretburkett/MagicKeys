var robot = require("robotjs");
var HID = require('node-hid');
var fs = require('fs');

// robot.typeString("Hello World");

var attached = false;
var magickeypad;
var device;

console.log("Looking for Device");

// Device Scanner
var scanner = setInterval(function() {
    var devices = HID.devices();
    var found = false;
    devices.forEach(function(item) {
        // console.log(item);
        // console.log('VID:'+ item.vendorId + '  PID:' + item.productId);
        if(item.vendorId == 5824 && item.productId == 1503){
            // device found
            magickeypad = item;

            found = true;
            if(!attached){
                console.log("Device Found:");
                console.log(magickeypad);
                attached = true;
                device = new HID.HID(magickeypad.path);
                device.setNonBlocking(1);
                device.on("data", function(something) {
                    read();
                }).on("error", function(data) {
                    console.log(data);
                });
            }
        }
    }); // each device
    // echo disconnect of device
    if(attached && !found){
        attached = false;
        console.log("Device Disconnected");
        device.pause();
        device.removeAllListeners('data');
        device.removeAllListeners('error');
        device.close();
        console.log("Looking for Device");
    }
}, 1000); // - Device Scanner

function read(){
    if(attached){
        // try to get data. Handles errors if unplugged halfway through.
        try {
            var str = '';
            var instr = false;
            var run = true;
            while (run) {
                var buff = new Buffer(device.getFeatureReport(0, 254));
                if (buff.length > 1) {
                    var char = buff.toString();

                    if (char.indexOf('>') > -1) {
                        instr = false;
                        run = false;
                    } else if (instr) {
                        str += char.replace(/\D/g,'');
                    }
                    else if (char.indexOf('<') > -1) {
                        instr = true;
                    }
                } // if has buffer
            } // while string
            processCMD(str);
        } // try
        catch (e) {
            console.log(e);
        } // error
    } // if attached
}

function processCMD(str){
    // remove any whitespace
    console.log(str);
    // call key script
    var int = parseInt(str);
    if(int > 0 && int < 50){
        try {
            eval(fs.readFileSync('keys/'+str+'.js')+'');
        }
        catch(e){
            console.log(error);
        }
    }
}



