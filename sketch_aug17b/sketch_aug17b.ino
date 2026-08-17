#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(128, 64, &Wire, OLED_RESET);

void setup() {
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  display.clearDisplay();

  // Variables for each line of text/numbers
  String title = "TIME";
  String hours = "16";
  String minutes = "45";
  String seconds = "45";

  display.setTextColor(WHITE);

  // "TIME" at (0,0), size 2
  display.setTextSize(2);
  display.setCursor(0,0);
  display.print(title);

  // "16" at (0,18), size 5
  display.setTextSize(4);
  display.setCursor(0,18);
  display.print(hours);

display.drawChar(52, 18, ':', WHITE, BLACK, 4);


  // "45" at (78,18), size 5
  display.setTextSize(4);
  display.setCursor(78,18);
  display.print(minutes);

  // Small "45" at (52,50), size 2
  display.setTextSize(2);
  display.setCursor(52,50);
  display.print(seconds);

  display.display();
}

void loop() {
  // put your main code here, to run repeatedly:
}

