#ifndef SHOOTER_H
#define SHOOTER_H

#include "roll.h"
#include <vector>

class Shooter {
private:
    std::vector<Roll*> rolls;

public:
    Roll* throw_dice(Die& die1, Die& die2);
    void display_rolled_values();
    ~Shooter();
};

#endif