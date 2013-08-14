#include "SPI.h"
#include "Adafruit_WS2801.h"

uint8_t dataPin = 2;
uint8_t clockPin = 3;
int wait = 2;
Adafruit_WS2801 strip = Adafruit_WS2801(25, dataPin, clockPin);

void setup(){
  strip.begin();
  strip.show();
  randomSeed(analogRead(0));
  startNight();
  
  Serial.begin(9600);
  delay(2000); // wait a couple of seconds to get serial monitor running.
  Serial.print("starting up... ");

}

void loop(){
  starNight();
}

void startNight(){
  int brightness = random(9);
  int i;
  int chance;
  int pixels = strip.numPixels();

  for( i = 0; i < pixels; i++ ){
    chance = random(4);
    if( chance == 1 ) strip.setPixelColor( i, brightness, brightness, brightness);  
    strip.show();  
  }

}

void fadeDown(int star, int brightness, int curr){
 int diff;
 int i;
 
 diff = (curr - brightness)*.8;
 for( i = 0; i < 5; i++ ){ // increase the iterations to make dimming in more shallow steps.
        strip.setPixelColor( star, diff, diff, diff );
        strip.show();
        diff = diff*.8;
        delay(25);
 }
      strip.setPixelColor( star, brightness, brightness, brightness);
      strip.show();
}

void fadeUp(int star, int brightness, int curr){
  int i;
  int diff = (brightness - curr)*.1;
      for( i = 0; i < 3; i++ ){ // increase the iterations to make dimming in more shallow steps.
        diff = diff*2;
        strip.setPixelColor( star, diff, diff, diff );
        strip.show();
        delay(25);
      }
      strip.setPixelColor( star, brightness, brightness, brightness );
      strip.show();
  
}

void starNight(){
  int shootingStar = 0;
  int star = random(26);
  int brightness = random(8);
  int chance = random(3); // Too many stars were on so this helps
  int curr, diff;
  int i;


  if( chance == 1 ){ // prevent that by only allowing so many to even turn on.

    curr = (strip.getPixelColor(star) >> 16); // grab past brightness.

    if( curr > brightness ){
      fadeDown(star, brightness, curr);
    }
    
    else if( curr <= brightness && curr != 0  ){
      fadeUp(star, brightness, curr);
    }

    strip.show();
    delay(wait);
    wait = 300;
  }
  else{ // else turn a star off, helps with 'twinkle' effect.
    strip.setPixelColor( star, 0, 0, 0 );
    delay(wait);
  }

  shootingStar = random(50);
  if( shootingStar == 1 ) shootStar();
}

// The shooting star function is very much primitive and needs much work.
void shootStar(){
  int bright = 150;
  int i;
  int defaultBright = 2;
  int time = 15;
  for(i = 0; i < 5; i++){
    strip.setPixelColor(i, bright, bright, bright);
    strip.setPixelColor(i-1, bright-150, bright-150, bright-150);
    strip.show();
    delay(time);
  }
  // now we need to put the values back to what they were.
  for( i = 0; i < 5; i++ ){
    strip.setPixelColor( i, defaultBright, defaultBright, defaultBright );
  } 
}

