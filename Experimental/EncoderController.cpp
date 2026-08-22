#include "EncoderController.hpp"

#include <Arduino.h>

EncoderController::EncoderController(int aCLKPin, int aDTPin, int aSWPin)
    : clkPin(aCLKPin)
    , dtPin(aDTPin)
    , swPin(aSWPin)
    , buttonDidUp(false)
    , didClickCallback(NULL)
{
    pinMode(swPin, INPUT_PULLUP);
}

bool EncoderController::isButtonDown()
{
    return digitalRead(swPin) == LOW;
}

void EncoderController::process()
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
