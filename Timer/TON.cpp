#include "Arduino.h"
#include "Timer.h"

TON::TON(int p, bool r){
    pre = p;
    ret = r;
}

void TON::loop(){
    if (en && !dn){
        tt = true;
        if (previousMillis == 0){
            currentMillis = millis();
            previousMillis = currentMillis;
        }
        else {
            currentMillis = millis();
        }
        acc = currentMillis - previousMillis;
        if(acc >= pre){
            dn = true;
            tt = false;
        }
    }
    if (ret){
        if (!en && acc >= pre){
            previousMillis = 0;
            acc = 0;
            dn = false;
            tt = false;
        } else if(!en && acc < pre){
            tt = false;
            previousMillis = millis()-acc;
        }
    } else {
        if (!en){
            previousMillis = 0;
            acc = 0;
            dn = false;
            tt = false;
        }
    }
}