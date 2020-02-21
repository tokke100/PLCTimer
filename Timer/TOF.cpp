#include "Arduino.h"
#include "PLCTimer.h"

TOF::TOF(int p){
    pre = p;
    dn = false;
    en = false;
    tt = false;
    acc = 0;
    previousMillis = 0;
    currentMillis = 0;
}

void TOF::update(){
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
        acc += currentMillis - previousMillis;
        previousMillis = currentMillis;
        if(acc >= pre){
          dn = false;
          tt = false;
          previousMillis = 0;
          acc = 0;
        }
      }
}
