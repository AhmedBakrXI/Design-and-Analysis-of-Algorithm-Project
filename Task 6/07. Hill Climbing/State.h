//
// Created by eslam on 01/05/2024.
//

#ifndef INC_07__HILL_CLIMBING_STATE_H
#define INC_07__HILL_CLIMBING_STATE_H

#include <vector>
#include <iostream>

using namespace std;


class State {
private:
    vector<char> state;
    int heuristic;

    bool isValidMove(int row, int col, int actualCol, int actualRow);

    vector<State> moveChess(int position, vector<char> currentState);

    void calculateHeuristic();


public:
    State() {
        state = {'W', 'W', 'W', 'E', 'E', 'E', 'E', 'E', 'E', 'B', 'B', 'B'};
        //state = {'B', 'B', 'B', 'E', 'E', 'E', 'W', 'E', 'W', 'E', 'W', 'E'};
        calculateHeuristic();
    }

    State(vector<char> _state) : heuristic(0) {
        for (int idx = 0; idx < (int) _state.size(); idx++) {
            state.push_back(_state[idx]);
        }
    }

    vector<char> getState() const { return state; }

    int getHeuristic() const { return heuristic; }

    bool isGoal() const;

    vector<State> generateStates();

    void print() const {
        // Assuming the state is a 2D array with 4 rows and 4 columns
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 3; ++j) {
                std::cout << " " << state[i * 3 + j] << " ";
            }
            std::cout << std::endl;
        }
    }

    bool operator==(const State &other) const {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                if (state[i * 3 + j] != other.state[i * 3 + j]) {
                    return false;
                }
            }
        }
        return true;
    }
};


#endif //INC_07__HILL_CLIMBING_STATE_H
