#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(128, 64, &Wire, OLED_RESET);

void setup() {
  // Initialize with the I2C addr 0x3C (for the 128x64)
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Clear the buffer
  display.clearDisplay();

  // Draw a single pixel in white
display.drawChar(0, 0, 'T', WHITE, BLACK, 2);
display.drawChar(12, 0, 'I', WHITE, BLACK, 2);
display.drawChar(24, 0, 'M', WHITE, BLACK, 2);
display.drawChar(36, 0, 'E', WHITE, BLACK, 2);

display.drawChar(0, 18, '1', WHITE, BLACK, 5);
display.drawChar(26, 18, '6', WHITE, BLACK, 5);

display.drawChar(52, 18, ':', WHITE, BLACK, 5);

display.drawChar(78, 18, '4', WHITE, BLACK, 5);
display.drawChar(104, 18, '5', WHITE, BLACK, 5);

display.drawChar(52, 50, '4', WHITE, BLACK, 2);
display.drawChar(64, 50, '5', WHITE, BLACK, 2);

  // Display the drawing
  display.display();
}

void loop() {
  // put your main code here, to run repeatedly:
}
