#include <IRremote.h>
#include "Servo.h"
#define SERVOP 8
#define SERVOP2 9
const int buttonpin = 9;
const int buttonpin1 = 10;

int buttonstate = 0;
int buttonstate1 = 0;

IRrecv IR(5);
Servo servo;
int pos;
void setup(){
  servo.attach(SERVOP);
  servo.write(90);
  IR.enableIRIn();
  Serial.begin(9600);
  pinMode(buttonpin,INPUT);
  pinMode(buttonpin1,INPUT);
}

void loop(){
  unsigned long valor = 0x00000000 ;
  buttonstate = digitalRead(buttonpin);
  buttonstate1 = digitalRead(buttonpin1);
  if(IR.decode()){
    Serial.println(IR.decodedIRData.decodedRawData, HEX);
    valor = IR.decodedIRData.decodedRawData ;}
    if(valor == 0xE718FF00 or buttonstate == HIGH)
    
    {
      servo.write(0);
      delay(400);
      servo.write(-90);
      
      
    }
    
    if(valor == 0xAD52FF00 or buttonstate1 == HIGH) 
    {    
        servo.write(180);
        delay(400);
        servo.write(90);
      }
      
    
    
    IR.resume();
  }
