/*
 Created by Rui Santos
 
 All the resources for this project:
 https://randomnerdtutorials.com/
*/

#include "LedControl.h"
#include "binary.h"

/*
 DIN connects to pin 12
 CLK connects to pin 11
 CS connects to pin 10 
*/
LedControl lc=LedControl(12,11,10,1);
LedControl lv=LedControl(7,8,9,1);
int x;
// delay time between faces
unsigned long delaytime=1000;

//Configuration For Ultrasonic sensors
const int TRIG_PIN = 4; // Arduino pin connected to Ultrasonic Sensor's TRIG pin
const int ECHO_PIN = 3; // Arduino pin connected to Ultrasonic Sensor's ECHO pin
const int DISTANCE_THRESHOLD = 10; // centimeters
const int LED_PIN  = 2; // Arduino pin connected to LED's pin

// variables will change:
float duration_us, distance_cm,duration_uk , distance_cn;


// happy face
byte Eyes1[8]= {B0000000,B01111110,B10000001,B10110001,B10110001,B10000001,B01111110,B0000000};
byte Eyes2[8]= {B0000000,B01111110,B10000001,B10110001,B10110001,B10000001,B01111110,B0000000};

byte Eyes3[8]= {B0000000,B01111100,B10000010,B10110010,B10110010,B10000010,B01111100,B0000000};
byte Eyes4[8]= {B0000000,B01111100,B10000010,B10110010,B10110010,B10000010,B01111100,B0000000};

byte Eyes5[8]= {B0000000,B01111000,B10000100,B10110100,B10110100,B10000100,B01111000,B0000000};
byte Eyes6[8]= {B0000000,B01111000,B10000100,B10110100,B10110100,B10000100,B01111000,B0000000};

byte Eyes7[8]= {B0000000,B00110000,B01001000,B01111000,B01111000,B01001000,B00110000,B0000000};
byte Eyes8[8]= {B0000000,B00110000,B01001000,B01111000,B01111000,B01001000,B00110000,B0000000};

byte Eyes9[8]= {B0000000,B00100000,B01010000,B01110000,B01110000,B01010000,B00100000,B0000000};
byte Eyes10[8]= {B0000000,B00100000,B01010000,B01110000,B01110000,B01010000,B00100000,B0000000};

byte Eyes11[8]= {B0000000,B00100000,B01100000,B01100000,B01100000,B01100000,B00100000,B0000000};
byte Eyes12[8]= {B0000000,B00100000,B01100000,B01100000,B01100000,B01100000,B00100000,B0000000};\

byte Eyes13[8]= {B0000000,B0000000,B0000000,B0000000,B0000000,B0000000,B0000000,B0000000};
byte Eyes14[8]= {B0000000,B0000000,B0000000,B0000000,B0000000,B0000000,B0000000,B0000000};

byte Eyes15[8]= {B00111100,B01000010,B10000001,B10000001,B10000001,B10000001,B01000010,B00111100};
byte Eyes16[8]= {B00111100,B01000010,B10000001,B10000001,B10000001,B10000001,B01000010,B00111100};

long randNumber;
long randNumber2;
void setup() {
  Serial.begin(9600);
  lc.shutdown(0,false);
  // Set brightness to a medium value
  lc.setIntensity(0,2);
  // Clear the display
  lc.clearDisplay(0);

  lv.shutdown(0,false);
  // Set brightness to a medium value
  lv.setIntensity(0,2);
  // Clear the display
  lv.clearDisplay(0);

  //For UltraSonic Sensor
  pinMode(TRIG_PIN, OUTPUT); // set arduino pin to output mode
  pinMode(ECHO_PIN, INPUT);  // set arduino pin to input mode
  pinMode(LED_PIN, OUTPUT);  // set arduino pin to input mode
}

void drawFaces1(){
  // Display Eyes1
  lc.setRow(0,0,Eyes1[0]);
  lc.setRow(0,1,Eyes1[1]);
  lc.setRow(0,2,Eyes1[2]);
  lc.setRow(0,3,Eyes1[3]);
  lc.setRow(0,4,Eyes1[4]);
  lc.setRow(0,5,Eyes1[5]);
  lc.setRow(0,6,Eyes1[6]);
  lc.setRow(0,7,Eyes1[7]);
  
  
  // Display Eyes2
  lv.setRow(0,0,Eyes2[0]);
  lv.setRow(0,1,Eyes2[1]);
  lv.setRow(0,2,Eyes2[2]);
  lv.setRow(0,3,Eyes2[3]);
  lv.setRow(0,4,Eyes2[4]);
  lv.setRow(0,5,Eyes2[5]);
  lv.setRow(0,6,Eyes2[6]);
  lv.setRow(0,7,Eyes2[7]);
}

void drawFaces2(){
  // Display Eyes1
  lc.setRow(0,0,Eyes3[0]);
  lc.setRow(0,1,Eyes3[1]);
  lc.setRow(0,2,Eyes3[2]);
  lc.setRow(0,3,Eyes3[3]);
  lc.setRow(0,4,Eyes3[4]);
  lc.setRow(0,5,Eyes3[5]);
  lc.setRow(0,6,Eyes3[6]);
  lc.setRow(0,7,Eyes3[7]);
  
  // Display Eyes2
  lv.setRow(0,0,Eyes4[0]);
  lv.setRow(0,1,Eyes4[1]);
  lv.setRow(0,2,Eyes4[2]);
  lv.setRow(0,3,Eyes4[3]);
  lv.setRow(0,4,Eyes4[4]);
  lv.setRow(0,5,Eyes4[5]);
  lv.setRow(0,6,Eyes4[6]);
  lv.setRow(0,7,Eyes4[7]);
}

void drawFaces3(){
  // Display Eyes1
  lc.setRow(0,0,Eyes5[0]);
  lc.setRow(0,1,Eyes5[1]);
  lc.setRow(0,2,Eyes5[2]);
  lc.setRow(0,3,Eyes5[3]);
  lc.setRow(0,4,Eyes5[4]);
  lc.setRow(0,5,Eyes5[5]);
  lc.setRow(0,6,Eyes5[6]);
  lc.setRow(0,7,Eyes5[7]);
  
  // Display Eyes2
  lv.setRow(0,0,Eyes6[0]);
  lv.setRow(0,1,Eyes6[1]);
  lv.setRow(0,2,Eyes6[2]);
  lv.setRow(0,3,Eyes6[3]);
  lv.setRow(0,4,Eyes6[4]);
  lv.setRow(0,5,Eyes6[5]);
  lv.setRow(0,6,Eyes6[6]);
  lv.setRow(0,7,Eyes6[7]);
}

void drawFaces4(){
  // Display Eyes1
  lc.setRow(0,0,Eyes7[0]);
  lc.setRow(0,1,Eyes7[1]);
  lc.setRow(0,2,Eyes7[2]);
  lc.setRow(0,3,Eyes7[3]);
  lc.setRow(0,4,Eyes7[4]);
  lc.setRow(0,5,Eyes7[5]);
  lc.setRow(0,6,Eyes7[6]);
  lc.setRow(0,7,Eyes7[7]);
  
  
  // Display Eyes2
  lv.setRow(0,0,Eyes8[0]);
  lv.setRow(0,1,Eyes8[1]);
  lv.setRow(0,2,Eyes8[2]);
  lv.setRow(0,3,Eyes8[3]);
  lv.setRow(0,4,Eyes8[4]);
  lv.setRow(0,5,Eyes8[5]);
  lv.setRow(0,6,Eyes8[6]);
  lv.setRow(0,7,Eyes8[7]);
}

void drawFaces5(){
  // Display Eyes1
  lc.setRow(0,0,Eyes9[0]);
  lc.setRow(0,1,Eyes9[1]);
  lc.setRow(0,2,Eyes9[2]);
  lc.setRow(0,3,Eyes9[3]);
  lc.setRow(0,4,Eyes9[4]);
  lc.setRow(0,5,Eyes9[5]);
  lc.setRow(0,6,Eyes9[6]);
  lc.setRow(0,7,Eyes9[7]);
  
  // Display Eyes2
  lv.setRow(0,0,Eyes10[0]);
  lv.setRow(0,1,Eyes10[1]);
  lv.setRow(0,2,Eyes10[2]);
  lv.setRow(0,3,Eyes10[3]);
  lv.setRow(0,4,Eyes10[4]);
  lv.setRow(0,5,Eyes10[5]);
  lv.setRow(0,6,Eyes10[6]);
  lv.setRow(0,7,Eyes10[7]);
}

void drawFaces6(){
  // Display Eyes1
  lc.setRow(0,0,Eyes11[0]);
  lc.setRow(0,1,Eyes11[1]);
  lc.setRow(0,2,Eyes11[2]);
  lc.setRow(0,3,Eyes11[3]);
  lc.setRow(0,4,Eyes11[4]);
  lc.setRow(0,5,Eyes11[5]);
  lc.setRow(0,6,Eyes11[6]);
  lc.setRow(0,7,Eyes11[7]);
  
  // Display Eyes2
  lv.setRow(0,0,Eyes12[0]);
  lv.setRow(0,1,Eyes12[1]);
  lv.setRow(0,2,Eyes12[2]);
  lv.setRow(0,3,Eyes12[3]);
  lv.setRow(0,4,Eyes12[4]);
  lv.setRow(0,5,Eyes12[5]);
  lv.setRow(0,6,Eyes12[6]);
  lv.setRow(0,7,Eyes12[7]);
}

void drawFaces7(){
  // Display Eyes1
  lc.setRow(0,0,Eyes15[0]);
  lc.setRow(0,1,Eyes15[1]);
  lc.setRow(0,2,Eyes15[2]);
  lc.setRow(0,3,Eyes15[3]);
  lc.setRow(0,4,Eyes15[4]);
  lc.setRow(0,5,Eyes15[5]);
  lc.setRow(0,6,Eyes15[6]);
  lc.setRow(0,7,Eyes15[7]);
  
  // Display Eyes2
  lv.setRow(0,0,Eyes16[0]);
  lv.setRow(0,1,Eyes16[1]);
  lv.setRow(0,2,Eyes16[2]);
  lv.setRow(0,3,Eyes16[3]);
  lv.setRow(0,4,Eyes16[4]);
  lv.setRow(0,5,Eyes16[5]);
  lv.setRow(0,6,Eyes16[6]);
  lv.setRow(0,7,Eyes16[7]);
}


void ShutEyes(){
  // Display Eyes1
  lc.setRow(0,0,Eyes13[0]);
  lc.setRow(0,1,Eyes13[1]);
  lc.setRow(0,2,Eyes13[2]);
  lc.setRow(0,3,Eyes13[3]);
  lc.setRow(0,4,Eyes13[4]);
  lc.setRow(0,5,Eyes13[5]);
  lc.setRow(0,6,Eyes13[6]);
  lc.setRow(0,7,Eyes13[7]);
  
  // Display Eyes2
  lv.setRow(0,0,Eyes14[0]);
  lv.setRow(0,1,Eyes14[1]);
  lv.setRow(0,2,Eyes14[2]);
  lv.setRow(0,3,Eyes14[3]);
  lv.setRow(0,4,Eyes14[4]);
  lv.setRow(0,5,Eyes14[5]);
  lv.setRow(0,6,Eyes14[6]);
  lv.setRow(0,7,Eyes14[7]);
}

void Blink(){
  do{
    
    randNumber = random(100, 3000);
    randNumber2 = random(40, 50);
    drawFaces1();
    delay(randNumber);
    drawFaces2();
    delay(randNumber2);
    drawFaces3();
    delay(randNumber2);
    drawFaces4();
    delay(randNumber2);
    drawFaces5();
    delay(randNumber2);
    drawFaces6();
    delay(randNumber2);
    drawFaces5();
    delay(randNumber2);
    drawFaces4();
    delay(randNumber2);
    drawFaces3();
    delay(randNumber2);
    drawFaces2();
    delay(randNumber2);
    drawFaces1();
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
    duration_uk = pulseIn(ECHO_PIN, HIGH);
    distance_cn = 0.017 * duration_uk;
  }
  while(distance_cn > DISTANCE_THRESHOLD);
  ShutEyes();
}

void loop(){
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration_us = pulseIn(ECHO_PIN, HIGH);
  distance_cm = 0.017 * duration_us;
  if(distance_cm < DISTANCE_THRESHOLD)
  {
    Blink();
    delay(1000);    
  }
   

   
}
