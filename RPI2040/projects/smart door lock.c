/*
Smart door lock system
Connections:

Servo motor
red pin ->5v
brown pin-> Gnd
orange pin-> any GPIO

IR sensor
Vcc->5v
Gnd->Gnd-
D0-> GPIO
*/
#include <Servo.h>
#define IR 27 // define 27 for Ir sensor

Servo myservo; //create servo object

void setup(){
    pinMode(IR,INPUT); //Ir pin as input
    myservo.attach(28)  //Attaches servo pin on 28
    
}
void loop(){
    if(digitalRead(IR)){//check if value of sensor is 1
        myservo.write(180);// if value is 1 then ture motor 180°
    }
    else{
        myservo.write(0); //turn motor to 0°
        delay(1000);
    }
    delay(100);
}