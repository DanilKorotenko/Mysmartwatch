#pragma once

class WatchState
{
public:
    WatchState();

    virtual void tick();
    virtual void display();
    virtual void reset();

    WatchState *nextState;
};