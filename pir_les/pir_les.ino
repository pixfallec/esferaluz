#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 90
#define DATA_PIN_1 3
#define DATA_PIN_2 4
#define DATA_PIN_3 5
#define DATA_PIN_4 6
#define DATA_PIN_5 7
#define DATA_PIN_6 8
#define DATA_PIN_7 9
#define DATA_PIN_8 10
#define DATA_PIN_9 11

CRGB leds_1[NUM_LEDS];
CRGB leds_2[NUM_LEDS];
CRGB leds_3[NUM_LEDS];
CRGB leds_4[NUM_LEDS];
CRGB leds_5[NUM_LEDS];
CRGB leds_6[NUM_LEDS];
CRGB leds_7[NUM_LEDS];
CRGB leds_8[190];
CRGB leds_9[NUM_LEDS];
 
int ledPin = 13;                // choose the pin for the LED
int inputPin = 2;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status
int cont = 0;
 
void setup() {
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare sensor as input
  FastLED.addLeds<WS2812, DATA_PIN_1, RGB>(leds_1, NUM_LEDS);  // GRB ordering is typical
  FastLED.addLeds<WS2812, DATA_PIN_2, RGB>(leds_2, NUM_LEDS);  // GRB ordering is typical
  FastLED.addLeds<WS2812, DATA_PIN_3, RGB>(leds_3, NUM_LEDS);  // GRB ordering is typical
  FastLED.addLeds<WS2812, DATA_PIN_4, RGB>(leds_4, NUM_LEDS);  // GRB ordering is typical
  FastLED.addLeds<WS2812, DATA_PIN_5, RGB>(leds_5, NUM_LEDS);  // GRB ordering is typical
  FastLED.addLeds<WS2812, DATA_PIN_6, RGB>(leds_6, NUM_LEDS);  // GRB ordering is typical
  FastLED.addLeds<WS2812, DATA_PIN_7, RGB>(leds_7, NUM_LEDS);  // GRB ordering is typical
  FastLED.addLeds<WS2812, DATA_PIN_8, RGB>(leds_8, 190);  // GRB ordering is typical
  FastLED.addLeds<WS2812, DATA_PIN_9, RGB>(leds_9, NUM_LEDS);  // GRB ordering is typical
  
  Serial.begin(9600);
}
 
void loop(){
  val = digitalRead(inputPin);  // read input value
  if (val == HIGH) {            // check if the input is HIGH
    //digitalWrite(ledPin, HIGH);  // turn LED ON
    if (pirState == LOW) {
      // we have just turned on
      Serial.println("Motion detected!");
      // We only want to print on the output change, not state
      pirState = HIGH;
      juegoLuces();
      //juegoLuces();
      //juegoLuces();
      //juegoLuces();
      //juegoLuces();
      //juegoLuces();
      //juegoLuces();
      //juegoLuces();
      //juegoLuces();
      //juegoLuces();
    }
  } else {
    //digitalWrite(ledPin, LOW); // turn LED OFF
    if (pirState == HIGH){
      // we have just turned of
      Serial.println("Motion ended!");
      // We only want to print on the output change, not state
      pirState = LOW;
    }
  }
}

void juegoLuces() {
  //segmento 1
  for (int i = 0; i < NUM_LEDS; i++) {
    leds_1[i] = CRGB(120, 40, 140);
    //FastLED.show();
    //delay(5);
  }
  FastLED.show();
  delay(300);
  //segmento 2
  for (int i = 0; i < NUM_LEDS; i++) {
    leds_2[i] = CRGB(120, 40, 140);
    //FastLED.show();
    //delay(5);
  }
  FastLED.show();
  delay(300);
  //segmento 3
  for (int i = 0; i < NUM_LEDS; i++) {
    leds_3[i] = CRGB(120, 40, 140);
    //FastLED.show();
    //delay(5);
  }
  FastLED.show();
  delay(300);
  //segmento 4
  for (int i = 0; i < NUM_LEDS; i++) {
    leds_4[i] = CRGB(120, 40, 140);
    //FastLED.show();
    //delay(5);
  }
  FastLED.show();
  delay(300);
  juegoLucesParte2();
  //delay(5000);
  //FastLED.clear();
  //FastLED.show();
}

void juegoLucesParte2() {
  //segmento 5
  for (int i = 0; i < NUM_LEDS; i++) {
    leds_5[i] = CRGB(120, 40, 140);
    //FastLED.show();
    //delay(5);
  }
  FastLED.show();
  //apagar segmento 1
  for (int i = 0; i < NUM_LEDS; i++) {
    leds_1[i] = CRGB::Black;
    //FastLED.show();
    //delay(5);
  }
  FastLED.show();
  delay(300);
  //segmento 6
  for (int i = 0; i < NUM_LEDS; i++) {
    leds_6[i] = CRGB(120, 40, 140);
    //FastLED.show();
    //delay(5);
  }
  FastLED.show();
  //apagar segmento 2
  for (int i = 0; i < NUM_LEDS; i++) {
    leds_2[i] = CRGB::Black;
    //FastLED.show();
    //delay(5);
  }
  FastLED.show();
  delay(300);
  //segmento 7
  for (int i = 0; i < NUM_LEDS; i++) {
    leds_7[i] = CRGB(120, 40, 140);
    //FastLED.show();
    //delay(5);
  }
  FastLED.show();
  //apagar segmento 3
  for (int i = 0; i < NUM_LEDS; i++) {
    leds_3[i] = CRGB::Black;
    //FastLED.show();
    //delay(5);
  }
  FastLED.show();
  delay(300);
  //segmento 8
  for (int i = 0; i < 190; i++) {
    leds_8[i] = CRGB(120, 40, 140);
    //FastLED.show();
    //delay(5);
  }
  FastLED.show();
  //apagar segmento 4
  for (int i = 0; i < NUM_LEDS; i++) {
    leds_4[i] = CRGB::Black;
    //FastLED.show();
    //delay(5);
  }
  FastLED.show();
  delay(300);
  //segmento 9
  for (int i = 0; i < NUM_LEDS; i++) {
    leds_9[i] = CRGB(120, 40, 140);
    //FastLED.show();
    //delay(5);
  }
  FastLED.show();
  //apagar segmento 5
  for (int i = 0; i < NUM_LEDS; i++) {
    leds_5[i] = CRGB::Black;
    //FastLED.show();
    //delay(5);
  }
  FastLED.show();
  //encender segmento 1
  for (int i = 0; i < NUM_LEDS; i++) {
    leds_1[i] = CRGB(120, 40, 140);
    //FastLED.show();
    //delay(5);
  }
  FastLED.show();
  //apagar segmento 6
  for (int i = 0; i < NUM_LEDS; i++) {
    leds_6[i] = CRGB::Black;
    //FastLED.show();
    //delay(5);
  }
  FastLED.show();
  delay(300);

  //encender segmento 2
  for (int i = 0; i < NUM_LEDS; i++) {
    leds_2[i] = CRGB(120, 40, 140);
    //FastLED.show();
    //delay(5);
  }
  FastLED.show();
  //apagar segmento 7
  for (int i = 0; i < NUM_LEDS; i++) {
    leds_7[i] = CRGB::Black;
    //FastLED.show();
    //delay(5);
  }
  FastLED.show();
  delay(300);

  //encender segmento 3
  for (int i = 0; i < NUM_LEDS; i++) {
    leds_3[i] = CRGB(120, 40, 140);
    //FastLED.show();
    //delay(5);
  }
  FastLED.show();
  //apagar segmento 8
  for (int i = 0; i < 190; i++) {
    leds_8[i] = CRGB::Black;
    //FastLED.show();
    //delay(5);
  }
  FastLED.show();
  delay(300);

  //encender segmento 4
  for (int i = 0; i < NUM_LEDS; i++) {
    leds_4[i] = CRGB(120, 40, 140);
    //FastLED.show();
    //delay(5);
  }
  FastLED.show();
  //apagar segmento 9
  for (int i = 0; i < NUM_LEDS; i++) {
    leds_9[i] = CRGB::Black;
    //FastLED.show();
    //delay(5);
  }
  FastLED.show();
  delay(300);

  //encender segmento 5
  for (int i = 0; i < NUM_LEDS; i++) {
    leds_5[i] = CRGB(120, 40, 140);
    //FastLED.show();
    //delay(5);
  }
  FastLED.show();
  //apagar segmento 1
  for (int i = 0; i < NUM_LEDS; i++) {
    leds_1[i] = CRGB::Black;
    //FastLED.show();
    //delay(5);
  }
  FastLED.show();
  delay(300);

  //encender segmento 6
  for (int i = 0; i < NUM_LEDS; i++) {
    leds_6[i] = CRGB(120, 40, 140);
    //FastLED.show();
    //delay(5);
  }
  FastLED.show();
  //apagar segmento 2
  for (int i = 0; i < NUM_LEDS; i++) {
    leds_2[i] = CRGB::Black;
    //FastLED.show();
    //delay(5);
  }
  FastLED.show();
  delay(300);

  //encender segmento 7
  for (int i = 0; i < NUM_LEDS; i++) {
    leds_7[i] = CRGB(120, 40, 140);
    //FastLED.show();
    //delay(5);
  }
  FastLED.show();
  //apagar segmento 3
  for (int i = 0; i < NUM_LEDS; i++) {
    leds_3[i] = CRGB::Black;
    //FastLED.show();
    //delay(5);
  }
  FastLED.show();
  delay(300);

  //encender segmento 8
  for (int i = 0; i < 190; i++) {
    leds_8[i] = CRGB(120, 40, 140);
    //FastLED.show();
    //delay(5);
  }
  FastLED.show();
  //apagar segmento 4
  for (int i = 0; i < NUM_LEDS; i++) {
    leds_4[i] = CRGB::Black;
    //FastLED.show();
    //delay(5);
  }
  FastLED.show();
  delay(300);

  //encender segmento 9
  for (int i = 0; i < NUM_LEDS; i++) {
    leds_9[i] = CRGB(120, 40, 140);
    //FastLED.show();
    //delay(5);
  }
  FastLED.show();
  //apagar segmento 5
  for (int i = 0; i < NUM_LEDS; i++) {
    leds_5[i] = CRGB::Black;
    //FastLED.show();
    //delay(5);
  }
  FastLED.show();
  delay(300);

  //apagar segmento 6
  for (int i = 0; i < NUM_LEDS; i++) {
    leds_6[i] = CRGB::Black;
    //FastLED.show();
    //delay(5);
  }
  FastLED.show();
  delay(300);

  //apagar segmento 7
  for (int i = 0; i < NUM_LEDS; i++) {
    leds_7[i] = CRGB::Black;
    //FastLED.show();
    //delay(5);
  }
  FastLED.show();
  delay(300);

  //apagar segmento 8
  for (int i = 0; i < 190; i++) {
    leds_8[i] = CRGB::Black;
    //FastLED.show();
    //delay(5);
  }
  FastLED.show();
  delay(300);

  //apagar segmento 9
  for (int i = 0; i < NUM_LEDS; i++) {
    leds_9[i] = CRGB::Black;
    //FastLED.show();
    //delay(5);
  }
  FastLED.show();
  delay(300);
  
  }
