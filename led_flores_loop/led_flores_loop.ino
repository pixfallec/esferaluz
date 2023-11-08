#include <dht.h>
#include <FastLED.h>


// How many leds in your strip?
#define NUM_LEDS 300 

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806, define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 3
#define DATA_PIN_AUX 9
#define CLOCK_PIN 13

// Define the array of leds
CRGB leds[NUM_LEDS];
CRGB leds_aux[NUM_LEDS];

//cuantas leds van encendidas
#define LED_ON 10

//cuantas leds van apagadas
#define LED_OFF 20

int contador = 0;

dht DHT;
int humedadInicio;
int humedadFin;
int chk;
int diferencia;
int secLuces = 0;
#define DHT11_PIN 7

void setup() { 
  Serial.begin(9600);
  Serial.println("resetting");
  FastLED.addLeds<WS2812,DATA_PIN,GRB>(leds,NUM_LEDS);
  FastLED.addLeds<WS2812,DATA_PIN_AUX,GRB>(leds_aux,NUM_LEDS);
  FastLED.setBrightness(50);
  FastLED.clear();
  FastLED.show();

  chk = DHT.read11(DHT11_PIN);
  humedadFin = DHT.humidity;
  humedadInicio = humedadFin;
}

void fadeall() { for(int i = 0; i < NUM_LEDS; i++) { leds[i].nscale8(250); } }

void(* resetFunc) (void) = 0;

void loop() {
  encenderGuia();
  validarHumedad();
  

  /*if (secLuces == 0) {
    validarHumedad();
  } else {
    encenderLuces();
  }*/

  /*static unsigned long lastMillis = 0;
  unsigned long interval = 2000;
  if (millis() - lastMillis >= interval) {
    lastMillis = millis();
    chk = DHT.read11(DHT11_PIN);
    humedadInicio = DHT.humidity;
    if (secLuces == 0) {
      diferencia = humedadInicio - humedadFin;
      Serial.print("diferencia humedad = ");
      Serial.println(diferencia);
      if (diferencia >= 2 && diferencia <= 8) {
        encenderLuces();
      } else {
        humedadFin = humedadInicio;   
      }
    }
    
    
  }*/
}

  void validarHumedad() {
    static const unsigned long REFRESH_INTERVAL = 2000; // ms
    static unsigned long lastRefreshTime = 0;
    int loop = 22;
    
    if(millis() - lastRefreshTime >= REFRESH_INTERVAL)
    {
      lastRefreshTime += REFRESH_INTERVAL;
      chk = DHT.read11(DHT11_PIN);
      humedadInicio = DHT.humidity;
      diferencia = humedadInicio - humedadFin;
      Serial.print("diferencia humedad = ");
      Serial.println(diferencia);
      if (diferencia >= 6 && diferencia <= 16) {
        //Serial.println("encender luces");
        for(int i = 0; i < loop; i++) {
          Serial.print("loop luces = ");
          Serial.println(i);
          encenderLuces();
          delay(1000);
        }
        resetFunc();
      } else {
        humedadFin = humedadInicio;   
      }
    } 
 }
  
  void encenderLuces() {
    secLuces = 1;
    static const unsigned long REFRESH_INTERVAL = 1000; // ms
    static unsigned long lastRefreshTime = 0;
    
    if(millis() - lastRefreshTime >= REFRESH_INTERVAL)
    {
      lastRefreshTime += REFRESH_INTERVAL;
      contador++;
      refrescarLuces(contador);
      FastLED.show();
      Serial.println(contador);
    }
  }

  void encenderGuia() {
    for(int i = 0; i < NUM_LEDS; i++) {
      if ((i >= 0 && i < 10) || (i >= 30 && i < 40) || (i >= 60 && i < 70) || (i >= 90 && i < 100) || (i >= 120 && i < 130) || 
          (i >= 150 && i < 160) || (i >= 180 && i < 190) || (i >= 210 && i < 220) || (i >= 240 && i < 250) || (i >= 270 && i < 280)) {
        //leds_aux[i] =  CRGB( 2, 6, 10);
        leds_aux[i] =  CRGB( 25, 112, 105);
      } else {
        leds_aux[i] = CRGB::Black;
      }
    }
    FastLED.show();
  }
  
  void refrescarLuces(int contador) {
      if (contador == 1) {
        for(int i = 0; i < NUM_LEDS; i++) {
          if (i >= 0 && i < 10 ) {
            leds[i] = CRGB( 25, 112, 105);
          } else {
            leds[i] = CRGB::Black;
          }
        }
      }
      if (contador == 2) {
        for(int i = 0; i < NUM_LEDS; i++) {
          if ((i >= 0 && i < 10) || (i >= 30 && i < 40)) {
            leds[i] = CRGB( 25, 112, 105);
          } else {
            leds[i] = CRGB::Black;
          }
        }
      }
      if (contador == 3) {
        for(int i = 0; i < NUM_LEDS; i++) {
          if ((i >= 0 && i < 10) || (i >= 30 && i < 40) || (i >= 60 && i < 70)) {
            leds[i] = CRGB( 25, 112, 105);
          } else {
            leds[i] = CRGB::Black;
          }
        }
      }
      if (contador == 4) {
        for(int i = 0; i < NUM_LEDS; i++) {
          if ((i >= 0 && i < 10) || (i >= 30 && i < 40) || (i >= 60 && i < 70) || (i >= 90 && i < 100)) {
            leds[i] = CRGB( 25, 112, 105);
          } else {
            leds[i] = CRGB::Black;
          }
        }
      }
      if (contador == 5) {
        for(int i = 0; i < NUM_LEDS; i++) {
          if ((i >= 0 && i < 10) || (i >= 30 && i < 40) || (i >= 60 && i < 70) || (i >= 90 && i < 100) || (i >= 120 && i < 130)) {
            leds[i] = CRGB( 25, 112, 105);
          } else {
            leds[i] = CRGB::Black;
          }
        }
      }
      if (contador == 6) {
        for(int i = 0; i < NUM_LEDS; i++) {
          if ((i >= 0 && i < 10) || (i >= 30 && i < 40) || (i >= 60 && i < 70) || (i >= 90 && i < 100) || (i >= 120 && i < 130) || 
              (i >= 150 && i < 160)) {
            leds[i] = CRGB( 25, 112, 105);
          } else {
            leds[i] = CRGB::Black;
          }
        }
      }
      if (contador == 7) {
        for(int i = 0; i < NUM_LEDS; i++) {
          if ((i >= 0 && i < 10) || (i >= 30 && i < 40) || (i >= 60 && i < 70) || (i >= 90 && i < 100) || (i >= 120 && i < 130) || 
              (i >= 150 && i < 160) || (i >= 180 && i < 190)) {
            leds[i] = CRGB( 25, 112, 105);
          } else {
            leds[i] = CRGB::Black;
          }
        }
      }
      if (contador == 8) {
        for(int i = 0; i < NUM_LEDS; i++) {
          if ((i >= 0 && i < 10) || (i >= 30 && i < 40) || (i >= 60 && i < 70) || (i >= 90 && i < 100) || (i >= 120 && i < 130) || 
              (i >= 150 && i < 160) || (i >= 180 && i < 190) || (i >= 210 && i < 220)) {
            leds[i] = CRGB( 25, 112, 105);
          } else {
            leds[i] = CRGB::Black;
          }
        }
      }
      if (contador == 9) {
        for(int i = 0; i < NUM_LEDS; i++) {
          if ((i >= 0 && i < 10) || (i >= 30 && i < 40) || (i >= 60 && i < 70) || (i >= 90 && i < 100) || (i >= 120 && i < 130) || 
              (i >= 150 && i < 160) || (i >= 180 && i < 190) || (i >= 210 && i < 220) || (i >= 240 && i < 250)) {
            leds[i] = CRGB( 25, 112, 105);
          } else {
            leds[i] = CRGB::Black;
          }
        }
      }
      if (contador == 10) {
        for(int i = 0; i < NUM_LEDS; i++) {
          if ((i >= 0 && i < 10) || (i >= 30 && i < 40) || (i >= 60 && i < 70) || (i >= 90 && i < 100) || (i >= 120 && i < 130) || 
              (i >= 150 && i < 160) || (i >= 180 && i < 190) || (i >= 210 && i < 220) || (i >= 240 && i < 250) || (i >= 270 && i < 280)) {
            leds[i] = CRGB( 25, 112, 105);
          } else {
            leds[i] = CRGB::Black;
          }
        }
      }
      if (contador == 12) {
        for(int i = 0; i < NUM_LEDS; i++) {
          if ((i >= 0 && i < 10) || (i >= 30 && i < 40) || (i >= 60 && i < 70) || (i >= 90 && i < 100) || (i >= 120 && i < 130) || 
              (i >= 150 && i < 160) || (i >= 180 && i < 190) || (i >= 210 && i < 220) || (i >= 240 && i < 250)) {
            leds[i] = CRGB( 25, 112, 105);
          } else {
            leds[i] = CRGB::Black;
          }
        }
      }
      if (contador == 13) {
        for(int i = 0; i < NUM_LEDS; i++) {
          if ((i >= 0 && i < 10) || (i >= 30 && i < 40) || (i >= 60 && i < 70) || (i >= 90 && i < 100) || (i >= 120 && i < 130) || 
              (i >= 150 && i < 160) || (i >= 180 && i < 190) || (i >= 210 && i < 220)) {
            leds[i] = CRGB( 25, 112, 105);
          } else {
            leds[i] = CRGB::Black;
          }
        }
      }
      if (contador == 14) {
        for(int i = 0; i < NUM_LEDS; i++) {
          if ((i >= 0 && i < 10) || (i >= 30 && i < 40) || (i >= 60 && i < 70) || (i >= 90 && i < 100) || (i >= 120 && i < 130) || 
              (i >= 150 && i < 160) || (i >= 180 && i < 190)) {
            leds[i] = CRGB( 25, 112, 105);
          } else {
            leds[i] = CRGB::Black;
          }
        }
      }
      if (contador == 15) {
        for(int i = 0; i < NUM_LEDS; i++) {
          if ((i >= 0 && i < 10) || (i >= 30 && i < 40) || (i >= 60 && i < 70) || (i >= 90 && i < 100) || (i >= 120 && i < 130) || 
              (i >= 150 && i < 160)) {
            leds[i] = CRGB( 25, 112, 105);
          } else {
            leds[i] = CRGB::Black;
          }
        }
      }
      if (contador == 16) {
        for(int i = 0; i < NUM_LEDS; i++) {
          if ((i >= 0 && i < 10) || (i >= 30 && i < 40) || (i >= 60 && i < 70) || (i >= 90 && i < 100) || (i >= 120 && i < 130)) {
            leds[i] = CRGB( 25, 112, 105);
          } else {
            leds[i] = CRGB::Black;
          }
        }
      }
      if (contador == 17) {
        for(int i = 0; i < NUM_LEDS; i++) {
          if ((i >= 0 && i < 10) || (i >= 30 && i < 40) || (i >= 60 && i < 70) || (i >= 90 && i < 100)) {
            leds[i] = CRGB( 25, 112, 105);
          } else {
            leds[i] = CRGB::Black;
          }
        }
      }
      if (contador == 18) {
        for(int i = 0; i < NUM_LEDS; i++) {
          if ((i >= 0 && i < 10) || (i >= 30 && i < 40) || (i >= 60 && i < 70)) {
            leds[i] = CRGB( 25, 112, 105);
          } else {
            leds[i] = CRGB::Black;
          }
        }
      }
      if (contador == 19) {
        for(int i = 0; i < NUM_LEDS; i++) {
          if ((i >= 0 && i < 10) || (i >= 30 && i < 40)) {
            leds[i] = CRGB( 25, 112, 105);
          } else {
            leds[i] = CRGB::Black;
          }
        }
      }
      if (contador == 20) {
        for(int i = 0; i < NUM_LEDS; i++) {
          if (i >= 0 && i < 10 ) {
            leds[i] = CRGB( 25, 112, 105);
          } else {
            leds[i] = CRGB::Black;
          }
        }
      }
      if (contador == 21) {
        for(int i = 0; i < NUM_LEDS; i++) {
          leds[i] = CRGB::Black;
        }
      }
      /*if (contador == 12) {
        resetFunc();
      }*/
  }
