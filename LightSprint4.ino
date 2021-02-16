#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define BUTTON_PIN   2

#define PIXEL_PIN    6  // Digital IO pin connected to the NeoPixels.

#define PIXEL_COUNT 4  // Number of NeoPixels

Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

boolean oldState = HIGH;


void setup() {
  //https://forums.adafruit.com/viewtopic.php?t=41143 set brightness of neopixels
  strip.setBrightness(25);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  strip.begin(); // Initialize NeoPixel strip object (REQUIRED)
  strip.show();  // Initialize all pixels to 'off'

}

void loop() {

   // Get current button state.
  boolean newState = digitalRead(BUTTON_PIN);
  

  // Check if state changed from high to low (button press).
  if((newState == LOW) && (oldState == HIGH)) {
    // Short delay to debounce button.
    delay(20);
    // Check if button is still low after debounce.
    newState = digitalRead(BUTTON_PIN);
    //https://www.tutorialspoint.com/arduino/arduino_infinite_loop.htm
    for (;;){
      rainbow(5);
    } 
   
        
      
    }
  }


  



  // Rainbow cycle along whole strip. Pass delay time (in ms) between frames.
void rainbow(int wait) {
  // Hue of first pixel runs 3 complete loops through the color wheel.
  // Color wheel has a range of 65536 but it's OK if we roll over, so
  // just count from 0 to 3*65536. Adding 256 to firstPixelHue each time
  // means we'll make 3*65536/256 = 768 passes through this outer loop:
  
  for(long firstPixelHue = 0; firstPixelHue < 3*65536; firstPixelHue += 256) {
    
    for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
      // Offset pixel hue by an amount to make one full revolution of the
      // color wheel (range of 65536) along the length of the strip
      // (strip.numPixels() steps):
      int pixelHue = firstPixelHue + (i * 65536L / strip.numPixels());
      // strip.ColorHSV() can take 1 or 3 arguments: a hue (0 to 65535) or
      // optionally add saturation and value (brightness) (each 0 to 255).
      // Here we're using just the single-argument hue variant. The result
      // is passed through strip.gamma32() to provide 'truer' colors
      // before assigning to each pixel:
      strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue)));
    }
  
    strip.show(); // Update strip with new contents
    delay(wait);  // Pause for a moment
  }

}
