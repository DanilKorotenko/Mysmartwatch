#include "WSClock.hpp"

#include <Arduino.h>

WSClock::WSClock(Adafruit_SSD1306 *anOledDisplay)
{
    oledDisplay = anOledDisplay;
    setTime(16, 34, 0, 17, 8, 2026); // hour, min, sec, day, month, year // delete from here
}

void WSClock::tick()
{

}

void WSClock::display()
{
    oledDisplay->clearDisplay();

    oledDisplay->setTextColor(WHITE);

    String title = "TIME";

    int Hours = hour();
    int Minutes = minute();
    int Seconds = second();

    Serial.print("Current time: ");
    Serial.print(Hours);
    Serial.print(":");
    Serial.print(Minutes);
    Serial.print(":");
    Serial.println(Seconds);

    oledDisplay->setTextSize(2);
    oledDisplay->setCursor(0,0);
    oledDisplay->print(title);

    oledDisplay->setTextSize(4);
    oledDisplay->setCursor(0,18);
    oledDisplay->print(Hours,10);

    oledDisplay->drawChar(52, 18, ':', WHITE, BLACK, 4);

    oledDisplay->setTextSize(4);
    oledDisplay->setCursor(78,18);
    oledDisplay->print(Minutes,10);

    oledDisplay->setTextSize(2);
    oledDisplay->setCursor(52,50);
    oledDisplay->print(Seconds,10);

    oledDisplay->display();
}
