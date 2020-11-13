#include "timer.h"
#include "timerManager.h"

Timer timer1;
Timer timer2;
Timer timer3;
Timer timer4;
Timer timer5;

Timer timer6;

void Toggle1() {
  Serial.println("LED 1 toggled");
  //digitalWrite(port, !digitalRead(port)); //delete first '//' and replace with needed port
}

void Toggle2() {
  Serial.println("LED 2");
  //digitalWrite(port, !digitalRead(port)); //delete first '//' and replace with needed port
}

void Toggle3() {
  Serial.println("LED 3");
  //digitalWrite(port, !digitalRead(port)); //delete first '//' and replace with needed port
}

void Toggle4() {
  Serial.println("LED 4");
  //digitalWrite(port, !digitalRead(port)); //delete first '//' and replace with needed port
}

void Toggle5() {
  Serial.println("LED 5");
  //digitalWrite(port, !digitalRead(port)); //delete first '//' and replace with needed port
}

int counter = 0;
void Handle1() {
  Serial.println("Handle 1");
  if(counter == 0) digitalWrite(13, 1);
  else digitalWrite(port, 0);
  counter++; 
  if(counter == 10) counter = 0;
}

void setup() {
  Serial.begin(9600);

  //Set the interval in milliseconds
  timer1.setTimeout(1000);
  timer2.setTimeout(2000);
  timer3.setTimeout(3000);
  timer4.setTimeout(4000);
  timer5.setInterval(5000);
  timer6.setInterval(5000);

  //Set our callback function
  timer1.setCallback(Toggle1);
  timer2.setCallback(Toggle2);
  timer3.setCallback(Toggle3);
  timer4.setCallback(Toggle4);
  timer5.setCallback(Toggle5);
  timer6.setCallback(Handle1);

  //Start all the timers
  TimerManager::instance().start();
}

void loop()
{
  //Update all the timers at once
  TimerManager::instance().update();
}