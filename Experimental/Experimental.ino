#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <TimeLib.h>

#include "WatchState.hpp"
#include "WSClock.hpp"

#include "WSChrono.hpp"

#include "ButtonController.hpp"
#include "EncoderController.hpp"

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(128, 64, &Wire, OLED_RESET); //Declaration for the size,setting,etc. of the OLED

const int EncoderSW = 5;
const int EncoderDT = 4;
const int EncoderCLK = 3;

WatchState *currentState = NULL;

WSClock clockState(&display);
WSChrono chronoState(&display);

ButtonController buttonController(2); // ButtonPin = 2;  // Pin connected to button
EncoderController encoderController(EncoderCLK, EncoderDT, EncoderSW);

void initStates()
{
    chronoState.nextState = &clockState;
    clockState.nextState = &chronoState;
    currentState = &clockState;
}

void switchState()
{
    Serial.println("switch state");
    currentState = currentState->nextState;
    currentState->reset();
}

void encoderDidClick()
{
    Serial.println("encoder did click");
    currentState->encoderDidClick();
}

void encoderDidUp()
{
    Serial.println("encoder did up");
    currentState->encoderDidUp();
}

void encoderDidDown()
{
    Serial.println("encoder did down");
    currentState->encoderDidDown();
}

void setup() 
{
    Serial.begin(9600); // Start serial communication at 9600 baud
    Serial.println("Debugging started...");

    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) 
    {
        Serial.println(F("SSD1306 allocation failed"));
        for(;;);
    }

    initStates();

    buttonController.didClickCallback = switchState;
    
    encoderController.didClickCallback = encoderDidClick;
    encoderController.didUpCallback = encoderDidUp;
    encoderController.didDownCallback = encoderDidDown;
}

void loop() 
{
    buttonController.process();
    encoderController.process();

    currentState->tick();
    currentState->display();

    delay(100);
}

