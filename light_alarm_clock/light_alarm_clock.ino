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
int count = 0; // number on display

int buttonPressed;
int buttonReleased;


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

    // will always be less than buttonReleased b/c this is recorded first in the time line
    buttonPressed = millis(); 
    // while button is held down do nothing
    while(digitalRead(buttonPin) == HIGH){}
    buttonReleased = millis();

    // checking how long user holds button. If over 3s, time will save
    if(buttonReleased - buttonPressed >= 3000)
    {
      Serial.print("Count: ");
      Serial.println(count);
      Serial.println("pressed for 3 seconds, saving time");
      Serial.print("Count: ");
      Serial.println(count);
      saveTimeAndCountdown(count, millis());
      
    }else
    {
      count++;
      if(count == 10)
        count = 1; // reset count    
        
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
      
       
  
      
      
     }// end of else

    
    }// end of if
    
  }// end of loop
 



/***
 * will save time user input and count down
 */
void saveTimeAndCountdown(int numHours, int previous)
{
  int currentTime = millis();
  int previousTime = previous;  // set preveous time as rn
  int eventInterval = 1000; // is 1 sec into future
  
//  int numSeconds = numHours * 3600; // convert hours to seconds
  int numSeconds = numHours * 3600;   // for testing. count will be * by 5 for seconds

  Serial.print("numSeconds: ");
  Serial.print(numSeconds);
  
//  while(numSeconds > 0)
//  {
//    if(currentTime - previousTime >= eventInterval)
//      numSeconds--;
//
//    Serial.println(numSeconds);
//    previousTime = currentTime;
//    
//  }

  // saved time has passed and code below will run

  // make it so servo will end with lights on
//  for(int x = 0; x < 5; x++)
//  {
//    servo.write(180);
//    delay(1000);
//    servo.write(360);
//    delay(1000);
//  }
  
  //Serial.println("Moving servo");
  
  
}// end of saveTime()






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
