#include <FastLED.h>
 
#define LED_PIN 3
#define NUM_LEDS 300
#define COLOR_ORDER GRB
#define LED_TYPE WS2812B
#define MAX_BRIGHTNESS 64    
 
struct CRGB leds[NUM_LEDS];
 
void setup() {
  Serial.begin(9600);
  LEDS.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(MAX_BRIGHTNESS);
  FastLED.clear();
}



void loop() {

  EVERY_N_MILLIS(8000) {
    triggered(1);
  }

  EVERY_N_MILLIS(10) {
    triggered(0);
  }

  FastLED.show();
} // loop()



void triggered(uint8_t trigger) {

  static uint16_t counte = 256;     // High count.

    if (trigger) {counte=0;}
    if (counte < 256) {
      uint8_t breathing = cubicwave8(counte++);
      fill_solid(leds, NUM_LEDS, CHSV(40, 250, breathing));
      if (counte == 128) {
        Serial.println("esperar 4seg");
        fill_solid(leds, NUM_LEDS, CHSV(40, 250, breathing));
        delay(4000);
        
      }
    }
} // triggered()
