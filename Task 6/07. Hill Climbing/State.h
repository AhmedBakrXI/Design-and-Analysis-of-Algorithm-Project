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
    bool isValidMove(int row, int col,int actualCol,int actualRow);
    vector<State> moveChess(int position,vector<char>currentState);
    void calculateHeuristic();


public:
    State(vector<char>_state):heuristic(0){
    	for(int idx = 0; idx< (int)_state.size();idx++)
    	{
    		state.push_back(_state[idx]);
    	}
    }
    vector<char> getState()  const { return state; }
    int getHeuristic() const { return heuristic; }
    bool isGoal();
    vector<State> generateStates();
};


#endif //INC_07__HILL_CLIMBING_STATE_H
