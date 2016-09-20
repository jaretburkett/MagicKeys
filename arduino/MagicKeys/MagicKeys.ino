/*
 * Made for Digispark Attiny85. The DigiStump Arduino
 * package is required for this to work. 
 */

#include <DigiUSB.h>

// put number of keys here (12 or 16)
#define KEYS 12

#define BUTS PB2

bool pressed = false;
int reading = 0;

void setup() {
  pinMode(BUTS,INPUT);
  DigiUSB.begin();
}

void loop() {
  int key = getKey();
  if(key > 0 && !pressed){
    DigiUSB.delay(100); // wait for it to stabalize
    if(key == getKey()){
      // key debounced and pressed send command
      DigiUSB.print("<");
      DigiUSB.print(key);
      DigiUSB.print(">");
      pressed = true;
    }
  } else {
    pressed = false;
  }
  DigiUSB.delay(1);
}

int getKey(){
  int val = analogRead(BUTS);
  if(KEYS == 12){
    if     (val > 980) return 1;
    else if(val > 880) return 2;
    else if(val > 810) return 3;
    else if(val > 760) return 4;
    else if(val > 710) return 5;
    else if(val > 660) return 6;
    else if(val > 620) return 7;
    else if(val > 585) return 8;
    else if(val > 560) return 9;
    else if(val > 525) return 10;
    else if(val > 500) return 11;
    else if(val > 490) return 12;
    else return 0;
  }// 12 key
/* 12 key
 * 1 -  1023
 * 2 -  930
 * 3 -  850
 * 4 -  790
 * 5 -  730
 * 6 -  680
 * 7 -  640
 * 8 -  600
 * 9 -  570
 * 10 - 540
 * 11 - 510
 * 12 - 490
 * 
 */
  else if (KEYS == 16){
    if     (val > 980) return 1;
    else if(val > 880) return 2;
    else if(val > 830) return 3;
    else if(val > 720) return 4;
    else if(val > 660) return 5;
    else if(val > 620) return 6;
    else if(val > 585) return 7;
    else if(val > 550) return 8;
    else if(val > 500) return 9;
    else if(val > 475) return 10;
    else if(val > 455) return 11;
    else if(val > 425) return 12;
    else if(val > 360) return 13;
    else if(val > 300) return 14;
    else if(val > 255) return 15;
    else if(val > 200) return 16;
    else return 0;
  }// 16 keys
}
/* 16 key
 * 1 - 1023
 * 2 - 930
 * 3 - 850
 * 4 - 790
 * 5 - 680
 * 6 - 640
 * 7 - 600
 * 8 - 570
 * 9 - 512
 * 10 - 487
 * 11 - 465
 * 12 - 445
 * 13 - 410
 * 14 - 330
 * 15 - 277
 * 16 - 238
 */
