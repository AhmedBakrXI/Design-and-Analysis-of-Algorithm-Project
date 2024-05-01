//
// Created by eslam on 01/05/2024.
//

#ifndef INC_07__HILL_CLIMBING_PATH_H
#define INC_07__HILL_CLIMBING_PATH_H

#include <iostream>
#include "State.h"
#include <random>

using namespace std;

class Path {
private:
    vector<State> path;

    Path() {
        State initState = State();
        path.push_back(initState);
    }

public:
    // Constructor takes a Path object and a const reference to the new state
    Path(Path oldPath, State newState) {
        // Copy the old path
        path = oldPath.path;

        // Append the new state to the path
        path.push_back(newState);
    }

    ~Path() {
        // Clear the list without deleting the states
        path.clear();
    }

    bool isGoalReached() const {
        return path.back().isGoal();
    }

    int getHeuristic() const {
        return path.back().getHeuristic();
    }

    std::vector<Path> generatePaths() {
        std::vector<State> newStates = path.back().generateStates();
        std::vector<Path> resultPaths;

        for (auto &newState: newStates) {
            resultPaths.push_back(Path(*this, newState));
        }

        return resultPaths;
    }

    int getSize() const {
        return path.size();
    }

    // Method to generate a Path with the initial state only
    // Method to generate a Path with the initial state only
    static Path getInitPath() {
        static Path initPath;
        return initPath;
    }

    // Overload > operator
    friend bool operator>(const Path &p1, const Path &p2) {
        return p1.getHeuristic() > p2.getHeuristic();
        /*return rand() & 1;*/
    }

    // Print method for Path class
    void print() const {
        for (size_t i = 0; i < path.size(); ++i) {
            std::cout << "Step " << i + 1 << ":" << std::endl;
            path[i].print();
            std::cout << std::endl;
        }
    }

    bool isSameEnd(Path p){
        if(this->path.back() == p.path.back()){
            return true;
        } else {
            return false;
        }
    }

};


#endif //INC_07__HILL_CLIMBING_PATH_H
