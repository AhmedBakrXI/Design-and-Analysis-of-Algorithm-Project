#include "Box.h"

/**
 * @breif it draws balls from the box
 * @param count the number of balls to be drawn
 * @return the weight of drawn balls
 */
int Box::drawBalls(int count) {
    this->ballCount -= count;
    return (count * weightOfBall);
}

/**
 * A constructor for creating a new Box object
 * @param fake defines if the box is a fake one or not
 * @param id   defines the id of the new Box
 * @param weightOfBall defines the weight of each non fake ball
 */
Box::Box(bool fake, int id, int weightOfBall) {
    this->fake = fake;
    this->id = id;
    // if this box is fake then the weight of the balls is
    // less than the weight of the real ball by 1 KG
    if (fake)
        this->weightOfBall = weightOfBall - 1;
    else
        this->weightOfBall = weightOfBall;
}

/**
 * A non parameterized Constructor to initialize the box with default values
 */
Box::Box() {
    this->fake = false;
    this->id = 0;
    this->weightOfBall = 10;
}

/**
 * Checks whether the box is fake or not
 * @return true if the box is fake, false otherwise
 */
bool Box::isFake() const {
    return this->fake;
}

/**
 * Gets the ID of the box
 * @return the ID of the box
 */
int Box::getId() const {
    return this->id;
}
