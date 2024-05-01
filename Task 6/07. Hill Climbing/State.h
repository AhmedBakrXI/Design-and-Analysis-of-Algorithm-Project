//
// Created by eslam on 01/05/2024.
//

#ifndef INC_07__HILL_CLIMBING_STATE_H
#define INC_07__HILL_CLIMBING_STATE_H

#include <vector>

using namespace std;

class State {
private:
    vector<char> state;
    int heuristic;

public:
    vector<char> getState() const { return state; }
    int getHeuristic() const { return heuristic; }
    bool isGoal();
    vector<State> generateStates();
};
#endif //INC_07__HILL_CLIMBING_STATE_H
