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
        //return 5 * path.back().getHeuristic() / 7 + 2 * (17 - getSize() - 1) / 7;
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


    bool operator==(const Path &obj) {
        if (obj.path.size() != this->path.size()) {
            return false;
        }

        for (int i = 0; i < path.size(); ++i) {
            if (!path[i].equals(obj.path[i])) {
                return false;
            }
        }
        return true;
    }

    bool equals(Path obj) {
        if (obj.path.size() != this->path.size()) {
            return false;
        }

        for (int i = 0; i < path.size(); ++i) {
            if (!path[i].equals(obj.path[i])) {
                return false;
            }
        }
        return true;
    }

    bool isBadPath() const {

/*
        if(path.size() >= 4){
            if(path[3].getHeuristic() >= 17) {
                return true;
            }
        }



        if(path.size()>=9){
            if(path[8].getHeuristic() >= 10){
                return true;
            }
        }

        if(path.size()>=11){
            if (path[10].getHeuristic() >= 10) {
                return true;
            }
        }

        if(path.size()>=13){
            if(path[12].getHeuristic() >= 7){
                return true;
            }
        }
*/
        if(path.size()>=16){
            if(path[15].getHeuristic() >= 3){
                return true;
            }
        }

        // Check condition for decreasing heuristic values
        bool increasingHeuristic = false;
        for (size_t i = 0; i < path.size() - 1; ++i) {
            int currentHeuristic = path[i].getHeuristic();
            int nextHeuristic = path[i + 1].getHeuristic();
            if (currentHeuristic < nextHeuristic) {
                if (increasingHeuristic) {
                    return true; // Heuristic has increased for more than one step
                }
                increasingHeuristic = true;
            }
        }
        return false; // Path is not bad
    }
};


#endif //INC_07__HILL_CLIMBING_PATH_H
