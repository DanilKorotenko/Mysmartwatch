#pragma once

#include "WatchState.hpp"

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <TimeLib.h>

class WSClock : public WatchState
{
public:
    WSClock(Adafruit_SSD1306 *anOledDisplay);

    void tick() override;
    void display() override;

private:
    Adafruit_SSD1306 *oledDisplay;

    int hours;
    int minutes;
    int seconds;
};