#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <TimeLib.h>

#include "WatchState.hpp"
#include "WSClock.hpp"

#include "WSChrono.hpp"

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(128, 64, &Wire, OLED_RESET); //Declaration for the size,setting,etc. of the OLED


const int ButtonPin = 2;  // Pin connected to button
int ButtonState = 0;      // Variable to store button state
int ButtonPressed = 0;

WatchState *currentState = NULL;
WSClock *clockState = NULL;
WatchState *chronoState = NULL;

void initStates()
{
    clockState = new WSClock(&display);
    chronoState = new WSChrono(&display);
    chronoState->nextState = clockState;
    clockState->nextState = chronoState;
    currentState = clockState;
}

void setup() 
{
    pinMode(ButtonPin, INPUT_PULLUP); 

    Serial.begin(9600); // Start serial communication at 9600 baud
    Serial.println("Debugging started...");

    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) 
    {
        Serial.println(F("SSD1306 allocation failed"));
        for(;;);
    }

    initStates();
}

bool isButtonPressed()
{
    return digitalRead(ButtonPin) == LOW;
}

void loop() 
{
    // Serial.println("loop");

    if (isButtonPressed())
    {
        Serial.println("button pressed");
        currentState = currentState->nextState;
        currentState->reset();
    }

    currentState->tick();
    currentState->display();

    delay(100);
}

