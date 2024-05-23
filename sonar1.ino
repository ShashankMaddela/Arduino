// C++ code
//
#include<LiquidCrystal.h>
#include<Servo.h>
const int rs=2, en =3, d4=4, d5=5, d6=6, d7=7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int buttonState = 0, Prev_buttonState=0;
const int trigPin = 12;  
const int echoPin = 11; 
Servo myservo;

void setup()
{
  pinMode(trigPin, OUTPUT);  
  pinMode(echoPin, INPUT); 
  pinMode(10,OUTPUT);
  pinMode(8,OUTPUT);
  Serial.begin(9600);  
  lcd.begin(16,2);
  //lcd.print("Hello World!");
  //delay(1000);
  myservo.attach(9);
}
 void loop()
 {
   buttonState= digitalRead(8);
   if(buttonState != Prev_buttonState)
   {
     if(buttonState == 1)
       lcd.scrollDisplayLeft();
     delay(500);
    
   }
   lcd.setCursor(0,0);
   //lcd.print(millis()/1000);
   
   digitalWrite(trigPin, LOW);  
   delayMicroseconds(2);  
   digitalWrite(trigPin, HIGH);  
   delayMicroseconds(10);  
   digitalWrite(trigPin, LOW);
   float duration = pulseIn(echoPin, HIGH); 
   float distance = (duration*.0343)/2; 
   lcd.print("Distance: ");  
   lcd.println(distance);  
   delay(200);  
   /*for(int i=0; i<=180; i++)   
   {
     myservo.write(i);
     delay(10); 
   }*/
   if(distance<150)
     myservo.write(90);
   else
     myservo.write(0);
   if(distance<150)
     tone(10,500,200);
   if(distance<150)
     digitalWrite(8,HIGH);
   
     


 }
               
               
               