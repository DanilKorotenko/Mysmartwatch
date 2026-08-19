#pragma once

#include "WatchState.hpp"

class WSClock : public WatchState
{
public:
    WSClock();

    void tick();
    void display();

private:
    int hours;
    int minutes;
    int seconds;
};