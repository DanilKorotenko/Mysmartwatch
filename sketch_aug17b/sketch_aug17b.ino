#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <TimeLib.h>
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(128, 64, &Wire, OLED_RESET); //Declaration for the size,setting,etc. of the OLED

void displayTime()
{
  display.clearDisplay();

    // Variables for each line of text/numbers
    String title = "TIME";

    int Hours = hour();
    int Minutes = minute();
    int Seconds = second();

  display.setTextColor(WHITE);

  display.setTextSize(2);
  display.setCursor(0,0);
  display.print(title);

  display.setTextSize(4);
  display.setCursor(0,18);
  display.print(Hours,10);

  display.drawChar(52, 18, ':', WHITE, BLACK, 4);

  display.setTextSize(4);
  display.setCursor(78,18);
  display.print(Minutes,10);

  display.setTextSize(2);
  display.setCursor(52,50);
  display.print(Seconds,10);

  display.display();

}

void setup() 
{
  Serial.begin(9600); // Start serial communication at 9600 baud
  Serial.println("Debugging started...");
  setTime(16, 34, 0, 17, 8, 2026); // hour, min, sec, day, month, year
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) 
  {
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

