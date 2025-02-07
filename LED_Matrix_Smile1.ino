#include "LedControl.h"
#include "binary.h"

/*
 * LED 1
 DIN connects to pin 2
 CLK connects to pin 4
 CS connects to pin 3

 LED 2
 DIN connects to pin 5
 CLK connects to pin 7
 CS connects to pin 6

 LED 3
 DIN connects to pin 8
 CLK connects to pin 10
 CS connects to pin 9
*/
LedControl lc=LedControl(13,4,2,1);
LedControl lv=LedControl(5,7,6,1);
LedControl lb=LedControl(8,10,9,1);
int x;
// delay time between faces
unsigned long delaytime=1000;

//Configuration For Ultrasonic sensors
const int TRIG_PIN = 11; // Arduino pin connected to Ultrasonic Sensor's TRIG pin
const int ECHO_PIN = 12; // Arduino pin connected to Ultrasonic Sensor's ECHO pin
const int DISTANCE_THRESHOLD = 10; // centimeters

// variables will change:
float duration_us, distance_cm,duration_uk , distance_cn;

//smile1
byte Smile1[8]= {B00000000,B00000000,B00000000,B00000000,B00000011,B00000111,B00001010,B00010010};
byte Smile2[8]= {B00100100,B01001000,B01001000,B01001000,B01001000,B01001000,B01001000,B00100100};
byte Smile3[8]= {B00010010,B00001010,B00000111,B00000011,B0000000,B0000000,B0000000,B0000000};


//Smile2
byte Smile4[8]= {B00000000,B00000000,B00000000,B00000000,B00000011,B00000111,B00001010,B00010010};
byte Smile5[8]= {B00100100,B01000100,B01000100,B01000100,B01000100,B01000100,B01000100,B00100100};
byte Smile6[8]= {B00010010,B00001010,B00000111,B00000011,B0000000,B0000000,B0000000,B0000000};

//smile3

byte Smile10[8]= {B00100010,B01000010,B01000010,B01000010,B01000010,B01000010,B01000010,B00100010};

//Smile4
byte Smile13[8]= {B00000000,B00000000,B00000000,B00000000,B00000011,B00000111,B00001001,B00010001};
byte Smile14[8]= {B00100001,B01000001,B01000001,B01000001,B01000001,B01000001,B01000001,B00100001};
byte Smile15[8]= {B00010001,B00001001,B00000111,B00000011,B0000000,B0000000,B0000000,B0000000};

//Smile Close
byte Smile7[8]= {B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000};
byte Smile8[8]= {B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000};
byte Smile9[8]= {B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000};

long randNumber;
long randNumber2;
void setup() {
  Serial.begin(9600);
//Smile1
  lc.shutdown(0,false);
  // Set brightness to a medium value
  lc.setIntensity(0,2);
  // Clear the display
  lc.clearDisplay(0);
//Smile2
  lv.shutdown(0,false);
  // Set brightness to a medium value
  lv.setIntensity(0,2);
  // Clear the display
  lv.clearDisplay(0);
//Smile3
  lb.shutdown(0,false);
  // Set brightness to a medium value
  lb.setIntensity(0,2);
  // Clear the display
  lb.clearDisplay(0);
  
  //For UltraSonic Sensor
  pinMode(TRIG_PIN, OUTPUT); // set arduino pin to output mode
  pinMode(ECHO_PIN, INPUT);  // set arduino pin to input mo
}
void BigSmile1(){
     // Display Smile1
  lc.setRow(0,0,Smile1[0]);
  lc.setRow(0,1,Smile1[1]);
  lc.setRow(0,2,Smile1[2]);
  lc.setRow(0,3,Smile1[3]);
  lc.setRow(0,4,Smile1[4]);
  lc.setRow(0,5,Smile1[5]);
  lc.setRow(0,6,Smile1[6]);
  lc.setRow(0,7,Smile1[7]);
    
    
    // Display Smile2
  lv.setRow(0,0,Smile2[0]);
  lv.setRow(0,1,Smile2[1]);
  lv.setRow(0,2,Smile2[2]);
  lv.setRow(0,3,Smile2[3]);
  lv.setRow(0,4,Smile2[4]);
  lv.setRow(0,5,Smile2[5]);
  lv.setRow(0,6,Smile2[6]);
  lv.setRow(0,7,Smile2[7]);
  
    // Display Smile3
  lb.setRow(0,0,Smile3[0]);
  lb.setRow(0,1,Smile3[1]);
  lb.setRow(0,2,Smile3[2]);
  lb.setRow(0,3,Smile3[3]);
  lb.setRow(0,4,Smile3[4]);
  lb.setRow(0,5,Smile3[5]);
  lb.setRow(0,6,Smile3[6]);
  lb.setRow(0,7,Smile3[7]);
}

void BigSmile2(){
     // Display Smile4
  lc.setRow(0,0,Smile4[0]);
  lc.setRow(0,1,Smile4[1]);
  lc.setRow(0,2,Smile4[2]);
  lc.setRow(0,3,Smile4[3]);
  lc.setRow(0,4,Smile4[4]);
  lc.setRow(0,5,Smile4[5]);
  lc.setRow(0,6,Smile4[6]);
  lc.setRow(0,7,Smile4[7]);
    
    
    // Display Smile5
  lv.setRow(0,0,Smile5[0]);
  lv.setRow(0,1,Smile5[1]);
  lv.setRow(0,2,Smile5[2]);
  lv.setRow(0,3,Smile5[3]);
  lv.setRow(0,4,Smile5[4]);
  lv.setRow(0,5,Smile5[5]);
  lv.setRow(0,6,Smile5[6]);
  lv.setRow(0,7,Smile5[7]);
  
    // Display Smile6
  lb.setRow(0,0,Smile6[0]);
  lb.setRow(0,1,Smile6[1]);
  lb.setRow(0,2,Smile6[2]);
  lb.setRow(0,3,Smile6[3]);
  lb.setRow(0,4,Smile6[4]);
  lb.setRow(0,5,Smile6[5]);
  lb.setRow(0,6,Smile6[6]);
  lb.setRow(0,7,Smile6[7]);
}

void BigSmile3(){
     // Display Smile4
  lc.setRow(0,0,Smile4[0]);
  lc.setRow(0,1,Smile4[1]);
  lc.setRow(0,2,Smile4[2]);
  lc.setRow(0,3,Smile4[3]);
  lc.setRow(0,4,Smile4[4]);
  lc.setRow(0,5,Smile4[5]);
  lc.setRow(0,6,Smile4[6]);
  lc.setRow(0,7,Smile4[7]);
    
    
    // Display Smile10
  lv.setRow(0,0,Smile10[0]);
  lv.setRow(0,1,Smile10[1]);
  lv.setRow(0,2,Smile10[2]);
  lv.setRow(0,3,Smile10[3]);
  lv.setRow(0,4,Smile10[4]);
  lv.setRow(0,5,Smile10[5]);
  lv.setRow(0,6,Smile10[6]);
  lv.setRow(0,7,Smile10[7]);
  
    // Display Smile6
  lb.setRow(0,0,Smile6[0]);
  lb.setRow(0,1,Smile6[1]);
  lb.setRow(0,2,Smile6[2]);
  lb.setRow(0,3,Smile6[3]);
  lb.setRow(0,4,Smile6[4]);
  lb.setRow(0,5,Smile6[5]);
  lb.setRow(0,6,Smile6[6]);
  lb.setRow(0,7,Smile6[7]);
}

void BigSmile4(){
     // Display Smile4
  lc.setRow(0,0,Smile13[0]);
  lc.setRow(0,1,Smile13[1]);
  lc.setRow(0,2,Smile13[2]);
  lc.setRow(0,3,Smile13[3]);
  lc.setRow(0,4,Smile13[4]);
  lc.setRow(0,5,Smile13[5]);
  lc.setRow(0,6,Smile13[6]);
  lc.setRow(0,7,Smile13[7]);
    
    
    // Display Smile10
  lv.setRow(0,0,Smile14[0]);
  lv.setRow(0,1,Smile14[1]);
  lv.setRow(0,2,Smile14[2]);
  lv.setRow(0,3,Smile14[3]);
  lv.setRow(0,4,Smile14[4]);
  lv.setRow(0,5,Smile14[5]);
  lv.setRow(0,6,Smile14[6]);
  lv.setRow(0,7,Smile14[7]);
  
    // Display Smile15
  lb.setRow(0,0,Smile15[0]);
  lb.setRow(0,1,Smile15[1]);
  lb.setRow(0,2,Smile15[2]);
  lb.setRow(0,3,Smile15[3]);
  lb.setRow(0,4,Smile15[4]);
  lb.setRow(0,5,Smile15[5]);
  lb.setRow(0,6,Smile15[6]);
  lb.setRow(0,7,Smile15[7]);
}


void SmileShut(){
  // Display Smile7
  lc.setRow(0,0,Smile7[0]);
  lc.setRow(0,1,Smile7[1]);
  lc.setRow(0,2,Smile7[2]);
  lc.setRow(0,3,Smile7[3]);
  lc.setRow(0,4,Smile7[4]);
  lc.setRow(0,5,Smile7[5]);
  lc.setRow(0,6,Smile7[6]);
  lc.setRow(0,7,Smile7[7]);
  
  
  // Display Smile8
  lv.setRow(0,0,Smile8[0]);
  lv.setRow(0,1,Smile8[1]);
  lv.setRow(0,2,Smile8[2]);
  lv.setRow(0,3,Smile8[3]);
  lv.setRow(0,4,Smile8[4]);
  lv.setRow(0,5,Smile8[5]);
  lv.setRow(0,6,Smile8[6]);
  lv.setRow(0,7,Smile8[7]);

  // Display Smile3
  lb.setRow(0,0,Smile9[0]);
  lb.setRow(0,1,Smile9[1]);
  lb.setRow(0,2,Smile9[2]);
  lb.setRow(0,3,Smile9[3]);
  lb.setRow(0,4,Smile9[4]);
  lb.setRow(0,5,Smile9[5]);
  lb.setRow(0,6,Smile9[6]);
  lb.setRow(0,7,Smile9[7]);
}

void mainSmile()
{
  do{    
    randNumber = random(100, 3000);
    randNumber2 = random(40, 50);
    
    BigSmile1();
    delay(10);
    BigSmile2();
    delay(10);
    BigSmile3();
    delay(10);
    BigSmile4();
    delay(10);
    BigSmile4();
    delay(100);  
    BigSmile3();
    delay(10);  
    BigSmile2();
    delay(10);  
    BigSmile1();    
        
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
    duration_uk = pulseIn(ECHO_PIN, HIGH);
    distance_cn = 0.017 * duration_uk;
    delay(100);
  }
  while(distance_cn > DISTANCE_THRESHOLD);
  SmileShut();

}
void loop(){
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration_us = pulseIn(ECHO_PIN, HIGH);
  distance_cm = 0.017 * duration_us;
  if(distance_cm < DISTANCE_THRESHOLD)
  {    
    mainSmile();
    delay(1000);
  }
  else
  {
    Serial.begin("");
  }

  
}
