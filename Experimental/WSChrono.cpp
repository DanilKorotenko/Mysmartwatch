#include "WSChrono.hpp"

#include <Arduino.h>

WSChrono::WSChrono(Adafruit_SSD1306 *anOledDisplay)
{
    oledDisplay = anOledDisplay;

}

void WSChrono::tick()
{
    NowMillis = millis();
    CurrentMillis = NowMillis - OldMillis;
    OldMillis = NowMillis;

    if (CurrentMillis >= 1000); 
    {
        ChronoSecond = ChronoSecond + 1;
    }


        if (ChronoSecond >= 60); 
    {
        ChronoMinute = ChronoMinute + 1;
    }


        if (ChronoMinute >= 60); 
    {
        ChronoHour = ChronoHour + 1;
    }

        if (ChronoHour >= 96); 
    {
        Serial.print("Stack overflow in Days:WSChrono line 36");
    }
}

void WSChrono::display()
{
    oledDisplay->clearDisplay();

    oledDisplay->setTextColor(WHITE);

    String title = "STOPWATCH";

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
