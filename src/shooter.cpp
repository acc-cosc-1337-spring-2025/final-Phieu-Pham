#include "shooter.h"
#include <iostream>

Roll* Shooter::throw_dice(Die& die1, Die& die2) {
    Roll* roll = new Roll(die1, die2);
    roll->roll_dice();
    rolls.push_back(roll);
    return roll;
}

void Shooter::display_rolled_values() {
    for (const auto& roll : rolls) {
        std::cout << roll->roll_value() << std::endl;
    }
}

Shooter::~Shooter() {
    for (auto roll : rolls) {
        delete roll;
    }
}