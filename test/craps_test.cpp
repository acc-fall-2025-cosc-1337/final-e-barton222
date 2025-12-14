#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "come_out_phase.h"

TEST_CASE("Roll returns value from 2 to 12", "[Roll]") {
    Die die1;
    Die die2;
    Roll roll(die1, die2);

    for (int i = 0; i < 10; i++) {
        roll.roll_dice();
        int value = roll.roll_value();
        REQUIRE(value >= 2);
        REQUIRE(value <= 12);
    }
}

TEST_CASE("Die rolls values from 1 to 6", "[Die]") {
    Die die;

    for (int i = 0; i < 10; i++) {
        int value = die.roll();
        REQUIRE(value >= 1);
        REQUIRE(value <= 6);
    }
}

TEST_CASE("Shooter throws dice and returns valid Roll", "[Shooter]") {
    Die die1;
    Die die2;
    Shooter shooter;

    for (int i = 0; i < 10; i++) {
        Roll* roll = shooter.throw_dice(die1, die2);
        int value = roll->roll_value();
        REQUIRE(value >= 2);
        REQUIRE(value <= 12);
    }
}

TEST_CASE("ComeOutPhase outcomes", "[ComeOutPhase]") {
    Die d1, d2;
    Roll roll(d1, d2);
    ComeOutPhase phase;

    roll.roll_dice();
    int value = roll.roll_value();

    RollOutcome outcome = phase.get_outcome(&roll);

    REQUIRE(
        outcome == RollOutcome::natural ||
        outcome == RollOutcome::craps ||
        outcome == RollOutcome::point
    );
}

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}
