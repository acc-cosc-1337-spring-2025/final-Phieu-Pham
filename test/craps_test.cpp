#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "come_out_phase.h"
#include "point_phase.h"

/*TEST_CASE("Verify Test Configuration", "verification") {
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

TEST_CASE("Verify Shooter Throws Dice") {
    Die die1;
    Die die2;
    Shooter shooter;

    Roll* roll = shooter.throw_dice(die1, die2);
    
    int roll_value = roll->roll_value();
    REQUIRE(roll_value >= 2);
    REQUIRE(roll_value <= 12);
}*/

TEST_CASE("Verify ComeOutPhase get_outcome returns natural, craps, and point") {
    Die die1, die2;
    ComeOutPhase come_out_phase;
    bool has_natural = false, has_craps = false, has_point = false;

    for (int i = 0; i < 100; ++i) { // Increased iterations to ensure all outcomes
        Roll roll(die1, die2);
        roll.roll_dice();
        RollOutcome outcome = come_out_phase.get_outcome(&roll);
        int value = roll.roll_value();

        if (value == 7 || value == 11) {
            REQUIRE(outcome == RollOutcome::natural);
            has_natural = true;
        } else if (value == 2 || value == 3 || value == 12) {
            REQUIRE(outcome == RollOutcome::craps);
            has_craps = true;
        } else {
            REQUIRE(outcome == RollOutcome::point);
            has_point = true;
        }

        if (has_natural && has_craps && has_point) break;
    }

    REQUIRE(has_natural);
    REQUIRE(has_craps);
    REQUIRE(has_point);
}

TEST_CASE("Verify PointPhase get_outcome returns point, seven_out, and nopoint") {
    Die die1, die2;
    bool has_point = false, has_seven_out = false, has_nopoint = false;

    for (int point_value = 4; point_value <= 10; ++point_value) {
        if (point_value == 7) continue; // Skip 7 as it's not a valid point
        PointPhase point_phase(point_value);
        for (int i = 0; i < 100; ++i) { // Increased iterations to ensure all outcomes
            Roll roll(die1, die2);
            roll.roll_dice();
            RollOutcome outcome = point_phase.get_outcome(&roll);
            int value = roll.roll_value();

            if (value == point_value) {
                REQUIRE(outcome == RollOutcome::point);
                has_point = true;
            } else if (value == 7) {
                REQUIRE(outcome == RollOutcome::seven_out);
                has_seven_out = true;
            } else {
                REQUIRE(outcome == RollOutcome::nopoint);
                has_nopoint = true;
            }

            if (has_point && has_seven_out && has_nopoint) break;
        }
        if (has_point && has_seven_out && has_nopoint) break;
    }

    REQUIRE(has_point);
    REQUIRE(has_seven_out);
    REQUIRE(has_nopoint);
}