#pragma once

typedef void (*EncoderCallback)();

class EncoderController
{
public:
    EncoderController(int aCLKPin, int aDTPin, int aSWPin);

    void process();

    EncoderCallback didClickCallback;
    EncoderCallback didUpCallback;
    EncoderCallback didDownCallback;

private:
    bool isButtonDown();

    int clkPin;
    int dtPin;
    int swPin;

    bool buttonDidUp;
};
