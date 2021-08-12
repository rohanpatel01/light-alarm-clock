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
int numHours;
int secondsCount = 0; // for setting the time. After 3 seconds time will save

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

void save() // will show S on screen to show that it was saved
{
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
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
  // put your main code here, to run repeatedly:
  
  if(digitalRead(buttonPin) == HIGH)
  {
    while(digitalRead(buttonPin) == HIGH)
    {
//      // count seconds go by
//      if(digitalRead(buttonPin) == LOW)
//      {
//        increaseNumber(); // will increase the number shown
//        break;
//      }
//      
//      // check if 3 seconds have passed
//      delay(1000);  // delay 1 second
//      secondsCount++;
//
//      // if button is pressed for 3 or more seconds, numHours will save
//      if(secondsCount >= 3)
//      {
//        Serial.println("3 seconds have passed");
//        //while(Serial.available() == 0){}
//        
//        //saveTime(Serial.parseInt()); // int numHours
//        //Serial.print(Serial.parseInt());
//        //Serial.println(" was saved into numHours");
//        break;  // to make sure user doesn't just keep holding button
//      } // might have to use boolean didBreak if issue occurs because of this ^
    }
        
  

//   if(secondsCount < 3) // to make sure they did or didn't save and we don't go next
//    {
    increaseNumber();
    
      
  }// end of if

  
  
 
}// end of loop

void increaseNumber()
{
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
           
      }// end of switch

    Serial.println(count);
    
    count++;
    
    if(count == 10)
      count = 1; // reset count

    secondsCount = 0;
}// end of increaseNumber()



//void countTime()
//{
//  // convert hours to seconds
//
//  int numSeconds = numHours * 3600;
//  
//  while(numSeconds > 0)
//  {
//    delay(1000);
//    numSeconds--;
//  }
//  Serial.println("Waaakeeee Upppp");
//}
//
//
//void saveTime(int timeVal)
//{
//  numHours = timeVal;
//  save(); // display S on screen to show it saved
//}
