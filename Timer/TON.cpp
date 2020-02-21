#include "Arduino.h"
#include "PLCTimer.h"

TON::TON(int p){
    pre = p;
    ret = false;
    dn = false;
    en = false;
    tt = false;
    acc = 0;
    res = false;
    previousMillis = 0;
    currentMillis = 0;
}

TON::TON(int p, bool r){
    pre = p;
    ret = r;
    dn = false;
    en = false;
    tt = false;
    acc = 0;
    res = false;
    previousMillis = 0;
    currentMillis = 0;
}

void TON::update(){
    if (en && !dn){
        tt = true;
        if (previousMillis == 0){
            currentMillis = millis();
            previousMillis = currentMillis;
        }
        else {
            currentMillis = millis();
        }
        acc += currentMillis - previousMillis;
        previousMillis = currentMillis;
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

    if (res){
        acc = 0;
    }
}
