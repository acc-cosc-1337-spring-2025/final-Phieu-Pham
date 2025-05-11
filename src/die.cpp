#include "die.h"

Die::Die(){
    std::srand(std::time(nullptr));
}

int Die::roll() {
    return (std::rand() % sides) + 1;
}