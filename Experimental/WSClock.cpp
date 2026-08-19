#include "WSClock.hpp"

#include <Arduino.h>

WSClock::WSClock(Adafruit_SSD1306 *anOledDisplay)
{
    oledDisplay = anOledDisplay;
    setTime(16, 34, 0, 17, 8, 2026); // hour, min, sec, day, month, year // delete from here
}

void WSClock::tick()
{
    hours = hour();
    minutes = minute();
    seconds = second();
}

void WSClock::display()
{
    oledDisplay->clearDisplay();

    oledDisplay->setTextColor(WHITE);

    String title = "TIME";

    oledDisplay->setTextSize(2);
    oledDisplay->setCursor(0,0);
    oledDisplay->print(title);

    oledDisplay->setTextSize(4);
    oledDisplay->setCursor(0,18);
    oledDisplay->print(hours,10);

    oledDisplay->drawChar(52, 18, ':', WHITE, BLACK, 4);

    oledDisplay->setTextSize(4);
    oledDisplay->setCursor(78,18);
    oledDisplay->print(minutes,10);

    oledDisplay->setTextSize(2);
    oledDisplay->setCursor(52,50);
    oledDisplay->print(seconds,10);

    oledDisplay->display();
}
