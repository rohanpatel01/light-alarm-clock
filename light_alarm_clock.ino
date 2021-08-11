#include <Servo.h>
#include <SPI.h>





/*
 *    A
 *    -
 * F |  |B
 * G  -
 * E |  | C
 *    -
 *    D
 * 
 */

// HIGH means the light for that spot will not blink
// pins for 4 digit timer
int pinA = 13;
int pinB = 12;
int pinC = 2;
int pinD = 3;
int pinE = 4;
int pinF = 11;
int pinG = 10;

int buttonPin = 5;
int buzzerPin = 6;

int servoPin = 9;
int rotate = 0;
int count = 1; // number on display

Servo servo;

void zero()
{
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, HIGH);

}

void one()
{
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);   

}

void two()
{
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, LOW);     
   
}

void three()
{
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, LOW);     

}

void four()
{
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW); 
}

void five()
{
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);     
}

void six()
{
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);  
}

void seven()
{
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);
}

void eight()
{
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);  
}

void nine()
{
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);  
}


void setup() 
{
  // put your setup code here, to run once:

  
  servo.attach(servoPin);

  // 4 digit pins

  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(buttonPin, OUTPUT);
  Serial.begin(9600);

  zero();
  
}// end of setup



void loop() 
{
    // may look like it repeats
  // put your main code here, to run repeatedly:
  
  
  
  if(digitalRead(buttonPin) == HIGH)
  {
    while(digitalRead(buttonPin) == HIGH){}

    
    switch(count)
    {
       case 0:
         zero();
         break;
       case 1:
         one();
         break;

       case 2:
         two();
         break;

       case 3:
         three();
         break;
  
       case 4:
         four();
         break;
  
       case 5:
         five();
         break;
       
       case 6:
         six();
         break;

       case 7:
         seven();
         break;

       case 8:
         eight();
         break;

       case 9:
         nine();
         break;

       default:
         zero();
    }

    Serial.println(count);
    
    count++; 
    
    if(count == 10)
      count = 1; // reset count
  }

  
    
 
}// end of loop
