#include "WSChrono.hpp"

#include <Arduino.h>

WSChrono::WSChrono(Adafruit_SSD1306 *anOledDisplay)
{
    oledDisplay = anOledDisplay;

}

void WSChrono::tick()
{
    NowMillis = Millis();
    CurrentMillis = NowMillis - OldMillis;
    OldMillis = NowMillis

    if (CurrentMillis => 1000); 
    {
        ChronoSecond = ChronoSecond + 1
    }


        if (ChronoSecond => 60); 
    {
        ChronoMinute = ChronoMinute + 1
    }


        if (ChronoMinute => 60); 
    {
        ChronoHour = ChronoHour + 1
    }

        if (ChronoHour => 96); 
    {
        Serial.print("Chrono > 4 days")
    }
}

void WSChrono::display()
{
    display.clearDisplay();

    display.setTextColor(WHITE);

    String title = "STOPWATCH";

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
