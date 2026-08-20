#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <TimeLib.h>

#include "WatchState.hpp"
#include "WSClock.hpp"

#include "WSChrono.hpp"

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(128, 64, &Wire, OLED_RESET); //Declaration for the size,setting,etc. of the OLED
unsigned long OldestMillis;
unsigned long NewMillis;
const int ButtonPin = 2;  // Pin connected to button
int ButtonState = 0;      // Variable to store button state
int ButtonPressed = 0;

WatchState *currentState = NULL;
WSClock *clockState = NULL;
WatchState *chronoState = NULL;

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

    clockState = new WSClock(&display);
    chronoState = new WSChrono(&display);
    currentState = chronoState;
}

void loop() 
{
    // ButtonState = digitalRead(ButtonPin);
    // OldestMillis = millis();

    // if (ButtonState == LOW)
    // {
    //     ButtonPressed = 1;
    // }

    // Serial.print("Current time: ");
    // Serial.print(h);
    // Serial.print(":");
    // Serial.print(m);
    // Serial.print(":");
    // Serial.println(s);
    Serial.println("loop");
    
    currentState->tick();
    currentState->display();

    // displayChrono();
    // displayTime();
    delay(1000);
}

