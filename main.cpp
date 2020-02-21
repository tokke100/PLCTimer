#include <Arduino.h>
#include <PLCTimer.h>

#define START_BUTTON 2
#define STOP_BUTTON 3
#define RESET_BUTTON 4
#define LED1_PIN 10
#define LED2_PIN 11
#define LED3_PIN 12

//timer1: TON timer without retentive function
TON timer1(500);
//timer2: TOF timer
TOF timer2(1000);
//timer3: TON timer with retentive function
TON timer3(2000, true);

void setup() {
  //some buttons and leds
  pinMode(START_BUTTON, INPUT);
  pinMode(STOP_BUTTON, INPUT);
  pinMode(RESET_BUTTON, INPUT);
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);
}

void loop() {
  //add the updates for the timer
  timer1.update();
  timer2.update();
  timer3.update();

  if(digitalRead(START_BUTTON) == HIGH){
    //timer1 TON enable true
    timer1.en = true;
  } else {
    //timer1 TON enable false
    timer1.en = false;
  }

  //timer1 done bit
  if(timer1.dn){
    digitalWrite(LED1_PIN, HIGH);
  }

  if(digitalRead(STOP_BUTTON) == HIGH){
    //timer2 enable true
    timer2.en = true;
    //timer3 enable true
    timer3.en = true;
  } else {
    //timer2 enable false
    timer2.en = false;
    //timer3 enable false
    timer3.en = false;
  }

  //timer2 done bit
  if(timer2.dn){
    digitalWrite(LED2_PIN, HIGH);
  } else {
    digitalWrite(LED2_PIN, LOW);
    digitalWrite(LED1_PIN, LOW);
  }

  if(digitalRead(RESET_BUTTON) == HIGH){
    //reset timer3 accumulate value with reset bit
    timer3.res = true;
  } else {
    timer3.res = false;
  }

  //timer3 done bit
  if(timer3.dn){
    digitalWrite(LED3_PIN, HIGH);
  } else {
    digitalWrite(LED3_PIN, LOW);
  }
}
