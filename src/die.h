#ifndef DIE_H
#define DIE_H

#include <cstdlib>
#include <ctime>

class Die {
private:
    int sides = 6;

public:
    Die();
    int roll();
};

#endif