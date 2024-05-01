#include <iostream>
#include <random>
#include "Box.h"

using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distribution(1, 1000);
    int fakeBoxIndex = distribution(gen) % 50;
    int weightOfBall = distribution(gen) % 99 + 1;

    Box boxes[50];

    for (int i = 0; i < 50; i++) {
        boxes[i] = Box(false, i, weightOfBall);
    }

    boxes[fakeBoxIndex] = Box(true, fakeBoxIndex, weightOfBall);


    int weightCollected = 0;
    for (int i = 0; i < 50; i++) {
        weightCollected += boxes[i].drawBalls(i + 1);
    }

    int expectedWeight = 1275 * weightOfBall;
    int fakeBoxCalculated = expectedWeight - weightCollected - 1;
    cout << "Entered Fake Box Index: " << fakeBoxIndex << endl;
    cout << "Entered Weight of Each Ball: " << weightOfBall << endl;

    cout << "================================================================" << endl;
    cout << "Expected Weight: " << expectedWeight << endl;
    cout << "Sum of weights drawn from each Box weighed on digital balance: " << weightCollected << endl;
    cout << "Calculated Fake Box Index: " << fakeBoxCalculated << endl;
    cout << "Checking if it is a fake box by asking the box it self and it said: "
         << (boxes[fakeBoxCalculated].isFake() ? "True" : "False") << ", I am the "
         << (boxes[fakeBoxCalculated].isFake() ? "" : "not") << " the fake box and my id is "
         << boxes[fakeBoxCalculated].getId() << endl;
    return 0;
}
