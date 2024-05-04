//
// Created by eslam on 01/05/2024.
//

#ifndef INC_07_HILL_CLIMBING_STATE_H
#define INC_07_HILL_CLIMBING_STATE_H

#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

/***
 * The State class represents a configuration of knights on a 3x4 chessboard. It encapsulates the current state
 * of the board along with methods for calculating the heuristic score, generating possible successor states,
 * and performing other operations related to the problem of exchanging knights.
 *
 */
class State {
private:
    ///
    /// A vector representing the current configuration of knights on the chessboard. Each element of the vector
    /// corresponds to a square on the board, where 'W' represents a white knight, 'B' represents a black knight, and
    /// 'E' represents an empty square.
    ///
    vector<char> state;
    ///
    /// An integer representing the heuristic score of the current state. This score is used to estimate the cost of
    /// reaching the goal state from the current state.
    /// The smaller the score, the closer to the goal state.
    ///
    int heuristic;

    /***
     * Method to check if a move to a given position on the board is valid.
     *
     * @brief
     *
     * @param row
     * @param col
     * @param actualCol
     * @param actualRow
     * @return
     */
    bool isValidMove(int row, int col, int actualCol, int actualRow);

    vector<State> moveChess(int position, vector<char> currentState);

    void calculateHeuristic();


public:
    explicit State();

    explicit State(const vector<char> &_state) : heuristic(0) {
        for (char idx: _state) {
            state.push_back(idx);
        }
    }

    [[nodiscard]] vector<char> getState() const;

    [[nodiscard]] int getHeuristic() const;

    [[nodiscard]] bool isGoal() const;

    vector<State> generateStates();

    void print() const;


    bool equals(State state);
};


#endif //INC_07_HILL_CLIMBING_STATE_H
