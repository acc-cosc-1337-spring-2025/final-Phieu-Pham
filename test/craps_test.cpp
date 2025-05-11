#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify Die Rolls Return Values Between 1 and 6") {
    Die die;

    for (int i = 0; i < 10; ++i) {
        int roll_result = die.roll();
        REQUIRE(roll_result >= 1);
        REQUIRE(roll_result <= 6);
    }
}

TEST_CASE("Verify Roll Class Rolls Two Dice and Returns Valid Sum") {
    Die die1;
    Die die2;
    Roll roll(die1, die2);

    for (int i = 0; i < 10; ++i) {
        roll.roll_dice();
        int roll_result = roll.roll_value();
        
        REQUIRE(roll_result >= 2); // Minimum possible roll (1+1)
        REQUIRE(roll_result <= 12); // Maximum possible roll (6+6)
    }
}
