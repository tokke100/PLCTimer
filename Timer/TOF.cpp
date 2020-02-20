#include "Arduino.h"
#include "Timer.h"

TOF::TOF(int p){
    pre = p;
}

void TOF::loop(){
    if(en && !dn){
        dn = true;
        tt = false;
        acc = 0;
        previousMillis = 0;
      }

      if(dn && !en){
        tt = true;
        if (previousMillis == 0){
          currentMillis = millis();
          previousMillis = currentMillis;
        }else {
          currentMillis = millis();
        }
        acc = currentMillis - previousMillis;
        if(acc >= pre){
          dn = false;
          tt = false;
          previousMillis = 0;
          acc = 0;
        }
      }
}