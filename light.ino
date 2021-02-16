#include <Adafruit_NeoPixel.h>

#define BUTTON_PIN   6    // Digital IO pin connected to the button.  This will be
// driven with a pull-up resistor so the switch should
// pull the pin to ground momentarily.  On a high -> low
// transition the button press logic will execute.

#define PIXEL_PIN    13   // Digital IO pin connected to the NeoPixels.

#define PIXEL_COUNT 3   // number of neopixel (change this accordingly)

// Parameter 1 = number of pixels in strip,  neopixel stick has 8
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_RGB     Pixels are wired for RGB bitstream
//   NEO_GRB     Pixels are wired for GRB bitstream, correct for neopixel stick
//   NEO_KHZ400  400 KHz bitstream (e.g. FLORA pixels)
//   NEO_KHZ800  800 KHz bitstream (e.g. High Density LED strip), correct for neopixel stick
Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

bool oldState = HIGH;
int showType = 0;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Serial.begin(9600);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW) 
  {
    showType++;
    switch (showType) {
      case 1:
        startShow(1);
        break;
      case 2:
        startShow(2);
        break;
      case 3:
        startShow(3);
        break;
      case 4:
        startShow(1);
        delay(100);
        startShow(2);
        delay(100);
        startShow(3);
        delay(100);
        startShow(1);
        delay(100);
        startShow(2);
        delay(100);
        startShow(3);
        delay(100);
        startShow(1);
        delay(100);
        startShow(2);
        delay(100);
        startShow(3);
        delay(100);
        startShow(1);
        delay(100);
        startShow(2);
        delay(100);
        startShow(3);
        delay(100);
        startShow(1);
        delay(200);
        startShow(2);
        delay(200);
        startShow(3);
        delay(200);
        startShow(1);
        delay(200);
        startShow(2);
        delay(200);
        startShow(3);
        delay(200);
        startShow(1);
        delay(200);
        startShow(2);
        delay(200);
        startShow(3);
        delay(200);
        startShow(1);
        delay(200);
        startShow(2);
        delay(200);
        startShow(3);
        delay(200);
        startShow(1);
        delay(200);
        startShow(2);
        delay(200);
        startShow(3);
        delay(200);
        startShow(1);
        delay(200);
        startShow(2);
        delay(200);
        startShow(3);
        delay(200);
        startShow(1);
        delay(200);
        startShow(2);
        delay(200);
        startShow(3);
        delay(200);
        startShow(1);
        delay(200);
        startShow(2);
        delay(200);
        startShow(3);
        delay(200);
        startShow(1);
        delay(200);
        startShow(2);
        delay(200);
        startShow(3);
        delay(200);
        startShow(1);
        delay(200);
        startShow(2);
        delay(200);
        startShow(3);
        delay(200);
        break;
      case 5:
        startShow(0);
        showType = 0;
        break;
    }
    while (!digitalRead(BUTTON_PIN)); 
  }
}

void startShow(int i) {
  switch (i) {
    case 0: colorWipe(strip.Color(0, 0, 0), 50);    // Black/off
      break;
    case 1: colorWipe(strip.Color(239, 55, 251), 50);  // Red
      break;
    case 2: colorWipe(strip.Color(87, 151, 198), 50);  // Green
      break;
    case 3: colorWipe(strip.Color(0, 182, 148), 50);  // Blue
      break;
  }
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}
