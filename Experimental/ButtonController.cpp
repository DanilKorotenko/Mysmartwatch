#include "ButtonController.hpp"

#include <Arduino.h>

ButtonController::ButtonController(int aButtonPin)
  : buttonDidUp(false)
  , didClickCallback(NULL)
{
    buttonPin = aButtonPin;
    pinMode(buttonPin, INPUT_PULLUP);
}

bool ButtonController::isButtonDown()
{
    return digitalRead(buttonPin) == LOW;
}

void ButtonController::process()
{
    if (isButtonDown() && buttonDidUp)
    {
        this->didClickCallback();
        buttonDidUp = false;
    }

    if (!isButtonDown())
    {
        buttonDidUp = true;
    }
}
