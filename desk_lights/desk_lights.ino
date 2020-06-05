/*
Original code from: Grensom LED-Audio Spectrum
*/
// for my own reference: I used Arduino Uno on COM7
#include <FastLED.h>
#define brightness 90 // adjust brightness to your liking
#define num_leds 300 // adjust according to your setup
#define pin 5

CRGB leds[num_leds];

void setup() {
  Serial.begin(9600);
  FastLED.addLeds<WS2811, pin, GRB>(leds, num_leds);
  FastLED.setBrightness(brightness);
}

void loop() {
  
  int sensitivity = (analogRead(1)*0.009);
  int x = analogRead(A0);
  x = x * sensitivity;
  
  int y = analogRead(3);
  int midpoint = 60; //num_leds/2; //typically
  Serial.print("x: ");
  Serial.println(x);
  int c = 0;

  // music reactive color mode (change colors to your liking
  if (y < 100) {
   /* 
    // LED Set 1: Vaporwave (Blue, Magenta)
    if (x < 71) {
      //leds[(midpoint)] = CRGB(98,80,85); // pink
      //leds[(midpoint)] = CRGB(56,100,98); // light blue
      //leds[(midpoint)] = CRGB(117,199,169); // white-ish
      leds[(midpoint)] = CRGB(243,180,66); // yellow
      //Serial.print("\t green");
    }
    else if (x > 71 && x <= 142) {
      leds[(midpoint)] = CRGB(106,198,223);
      //Serial.print("\t lightblue");
    }
    else if (x > 142 && x <= 213) {
      leds[(midpoint)] = CRGB(73,109,180);
      //Serial.print("\t blue");
    }
    else if (x > 213 && x <= 284) {
      leds[(midpoint)] = CRGB(178,109,173);
      //Serial.print("\t violet");
    }
    else if (x > 284 && x <= 355) {
      leds[(midpoint)] = CRGB(185,82,159);
      //Serial.print("\t magenta");
    }
    else if (x > 355 && x <= 426) {
      leds[(midpoint)] = CRGB(106,198,223);
      //Serial.print("\t lightblue");
    }
    else {
      leds[(midpoint)] = CRGB(0,255,170);
      //Serial.print("\t green");
    }

*/
    // LED Set 2: Orange and Pink
    if (x < 71) {
      leds[(midpoint)] = CRGB(243,180,66); // yellow
  
    }
    else if (x > 71 && x <= 142) {
      leds[(midpoint)] = CRGB(93,87,51);
   
    }
    else if (x > 142 && x <= 213) {
      leds[(midpoint)] = CRGB(98,63,42); // coral
   
    }
    else if (x > 213 && x <= 284) {
      leds[(midpoint)] = CRGB(100,39,28);
      
    }
    else if (x > 284 && x <= 355) {
      leds[(midpoint)] = CRGB(100,76,76);
     
    }
    else if (x > 355 && x <= 426) {
      leds[(midpoint)] = CRGB(95,50,50);
   
    }
    else {
      leds[(midpoint)] = CRGB(100,83,61);
   
    }

  }

  // static color modes
  else if (y > 100 && y <= 1000) {
    //Serial.println(y);
    //Serial.print("color: ");
    
    if (y >= 100 && y < 250) { //2nd up
      c = ((y - 100) * (255 / 150));
      leds[(midpoint)] = CRGB(106,198,223);
    }
    else if (y >= 250 && y < 400) { //1st down
      c = ((y - 400) * (-255 / 150));
      leds[(midpoint)] = CRGB(c, 255, 0);
    }
    else if (y >= 400 && y < 550) { //3rd up
      c = ((y - 400) * (255 / 150));
      leds[(midpoint)] = CRGB(0, 255, c);
    }
    else if (y >= 550 && y < 700) {//2nd down
      c = ((y - 700) * (-255 / 150));
      leds[(midpoint)] = CRGB(0, c, 255);
    }
    else if (y >= 700 && y < 850) {//1st up
      c = ((y - 700) * (255 / 150));
      leds[(midpoint)] = CRGB(c, 0, 255);
    }
    else if (y >= 850 && y < 1000) {//3rd down
      c = ((y - 1000) * (-255 / 150));
      leds[(midpoint)] = CRGB(255, 0, c);
    }
    else {
      leds[(midpoint)] = CRGB(255, 0, 0);
    }
    //Serial.println(c);
  }
  else {
    int a = y;
    int d;
    while (y > 1000) {
      y = analogRead(1);
      if (a >= 100 && a < 250) { //2nd up
        d = ((a - 100) * (255 / 150));
        leds[(midpoint)] = CRGB(255, d, 0);
      }
      else if (a >= 250 && a < 400) { //1st down
        d = ((a - 400) * (-255 / 150));
        leds[(midpoint)] = CRGB(d, 255, 0);
      }
      else if (a >= 400 && a < 550) { //3rd up
        d = ((a - 400) * (255 / 150));
        leds[(midpoint)] = CRGB(0, 255, d);
      }
      else if (a >= 550 && a < 700) {//2nd down
        d = ((a - 700) * (-255 / 150));
        leds[(midpoint)] = CRGB(0, d, 255);
      }
      else if (a >= 700 && a < 850) {//1st up
        d = ((a - 700) * (255 / 150));
        leds[(midpoint)] = CRGB(d, 0, 255);
      }
      else if (a >= 850 && a < 1000) {//3rd down
        d = ((a - 1000) * (-255 / 150));
        leds[(midpoint)] = CRGB(255, 0, d);
      }
      else {
        leds[(midpoint)] = CRGB(255, 0, 0);
      }
      FastLED.show();
      //delay(60);
      fill_solid( leds, num_leds, leds[(midpoint)]);
      a = a + 1;
      if (a > 1023){
        a = 0;
      }
    }
  }
  FastLED.show();
  //delay(10);
  for (int z = num_leds; z > (midpoint); z--) {
    leds[z] = leds[z - 1];   
  }
  for (int z = 0; z < (midpoint); z++) {
    leds[z] = leds[z + 1];
  }
  
}
