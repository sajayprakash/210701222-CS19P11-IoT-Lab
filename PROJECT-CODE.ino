

// include the library code:
#include <LiquidCrystal.h>
#include<stdio.h>
#include<string.h>
#include <Servo.h> 
Servo myservo1; 
const int ir1_s1 = 2;
const int ir2_s2 = 3;
const int ir3_s3 = 4;
const int ir4_s4 = 5;
const int ir5_s5 = 6;
const int ir6_s6 = 7;
 char inChar;
const int ir_entry = A5;
int pos = 0;  
unsigned int i=0,check;
String slot_1,slot_2,slot_3,slot_4,slot_5,slot_6,gate_command;
int s1,s2,s3,s4,s5,s6;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);  // rs, rw, e , d d d5 d6 d7


void setup() {
 
   myservo1.attach(A4); 
   myservo1.write(0);
   delay(100);
 //  myservo1.detach();
   pinMode(ir1_s1,INPUT); // sets the trigger pin as an input
   pinMode(ir2_s2,INPUT); // sets the trigger pin as an input
   pinMode(ir3_s3,INPUT); // sets the trigger pin as an input
   pinMode(ir4_s4,INPUT); // sets the trigger pin as an input
   pinMode(ir5_s5,INPUT); // sets the trigger pin as an input
   pinMode(ir6_s6,INPUT); // sets the trigger pin as an input
   pinMode(ir_entry,INPUT); // sets the trigger pin as an input
  
  Serial.begin(9600); // Starts the serial communication
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.setCursor(0, 0);

  lcd.print("Digital Car Parking");
  lcd.setCursor(0, 1);
  lcd.print("Slot");
 
  delay(1000);
  delay(1000);
  delay(1000);
  lcd.clear();

}

void loop()
{

   while (Serial.available() > 0)
   {
    inChar = Serial.read();
    if (inChar=='o') 
    {
       lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Gate Open");
  Serial.println("Gate Open");
  delay(1000);
   myservo1.attach(A4);  // attaches the servo on pin 9 to the servo object 
          myservo1.write(90);
        delay(100);
 //         myservo1.detach();
          delay(15);
          lcd.clear();
    }

      if (inChar =='c')
      {

        lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Gate close");
       Serial.println("Gate close");
      delay(1000);
       myservo1.attach(A4);  // attaches the servo on pin 9 to the servo object 
              myservo1.write(180);
            delay(100);
        //      myservo1.detach();
              delay(15);
    
    lcd.clear();
      }
     
    }
  if(digitalRead(ir_entry)== false&& ((s1==false||s2==false||s3==false||s4==false||s5==false||s6==false)))
  {
   lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Gate Open");
    Serial.println("Gate Open-slot available");
  delay(1000);
   myservo1.attach(A4);  // attaches the servo on pin 9 to the servo object 
          myservo1.write(90);
        delay(100);
 //         myservo1.detach();
          delay(15);
          lcd.clear();

  }
  if((s1==true&&s2==true&&s3==true&&s4==true&&s5==true&&s6==true))
  {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Slot is Full");
   lcd.setCursor(0, 1);
  lcd.print("Gate close");
  Serial.println("Gate close-Slot is Full");
  delay(3000);
  myservo1.attach(A4);  // attaches the servo on pin 9 to the servo object 
  myservo1.write(180);
        delay(100);
    //      myservo1.detach();
          delay(15);

lcd.clear();
    
  }
 
  if(digitalRead(ir_entry)== true)
  {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Gate close");
  Serial.println("Gate close");
  delay(1000);
   myservo1.attach(A4);  // attaches the servo on pin 9 to the servo object 
          myservo1.write(180);
        delay(100);
    //      myservo1.detach();
          delay(15);

lcd.clear();
  }
  lcd.setCursor(0, 0);
  lcd.print("Slot1:");
  lcd.print(slot_1);
  lcd.setCursor(0, 1);
  lcd.print("Slot2:");
  lcd.print(slot_2);
  delay(1000);
  lcd.setCursor(0, 0);
  lcd.print("Slot3:");
  lcd.print(slot_3);
  lcd.setCursor(0, 1);
  lcd.print("Slot4:");
  lcd.print(slot_4);
   delay(1000);
  lcd.setCursor(0, 0);
  lcd.print("Slot5:");
  lcd.print(slot_5);
  lcd.setCursor(0, 1);
  lcd.print("Slot6:");
  lcd.print(slot_6);
  delay(1000); 
  if(digitalRead(ir1_s1)== false)
  {
  slot_1=" Fill";
   Serial.println("Slot1: Full");
   s1= true;
  }
  if(digitalRead(ir1_s1)== true)
  {
  slot_1="Empty";
  Serial.println("Slot1: Empty");
   s1= false;
  }
    if(digitalRead(ir2_s2)== false)
  {
  slot_2=" Fill";
   Serial.println("Slot2: Full");
   s2= true;
  }
  if(digitalRead(ir2_s2)== true)
  {
  slot_2="Empty";
  s2= false;
  Serial.println("Slot2: Empty");
  }
  
    if(digitalRead(ir3_s3)== false)
  {
  slot_3=" Fill";
  s3= true;
   Serial.println("Slot3: Full");
  }
  if(digitalRead(ir3_s3)== true)
  {
  slot_3="Empty";
  s3= false;
  Serial.println("Slot3: Empty");
  }                                      
     if(digitalRead(ir4_s4)== false)
  {
  slot_4=" Fill";
  s4= true;
   Serial.println("Slot4: Full");
  }
  if(digitalRead(ir4_s4)== true)
  {
  slot_4="Empty";
  s4= false;
  Serial.println("Slot4: Empty");
  }   

     if(digitalRead(ir5_s5)== false)
  {
  slot_5=" Fill";
  s5= true;
   Serial.println("Slot5: Full");
  }
  if(digitalRead(ir5_s5)== true)
  {
  slot_5="Empty";
  s5= false;
  Serial.println("Slot5: Empty");
  }    
  
  if(digitalRead(ir6_s6)== false)
  {
  slot_6=" Fill";
  s6= true;
   Serial.println("Slot6: Full");
  }
  if(digitalRead(ir6_s6)== true)
  {
  slot_6="Empty";
  s6= false;
  Serial.println("Slot6: Empty");
  }      

    
  
//   Serial.print(level_value);
  //   Serial.print(" ");
 
   //Serial.print("N1 to N2 ");
    ////    Serial.write(21);
    //    delay(10);
   // Serial.write('#');    
   //   delay(3000);   



}
