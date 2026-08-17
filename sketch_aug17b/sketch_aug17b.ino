#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <TimeLib.h>
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(128, 64, &Wire, OLED_RESET);

void displayTime()
{
  display.clearDisplay();

  // Variables for each line of text/numbers
  String title = "TIME";

  int hours = hour();
  int minutes = minute();
  int seconds = second();

  display.setTextColor(WHITE);

  // "TIME" at (0,0), size 2
  display.setTextSize(2);
  display.setCursor(0,0);
  display.print(title);

  // "16" at (0,18), size 5
  display.setTextSize(4);
  display.setCursor(0,18);
  display.print(hours,10);

display.drawChar(52, 18, ':', WHITE, BLACK, 4);


  // "45" at (78,18), size 5
  display.setTextSize(4);
  display.setCursor(78,18);
  display.print(minutes,10);

  // Small "45" at (52,50), size 2
  display.setTextSize(2);
  display.setCursor(52,50);
  display.print(seconds,10);

  display.display();

}

void setup() 
{
    Serial.begin(9600); // Start serial communication at 9600 baud
  Serial.println("Debugging started...");
  setTime(16, 34, 0, 17, 8, 2026); // hour, min, sec, day, month, year
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

}

void loop() 
{
  // Serial.print("Current time: ");
  // Serial.print(h);
  // Serial.print(":");
  // Serial.print(m);
  // Serial.print(":");
  // Serial.println(s);
displayTime();
  delay(1000);
}

