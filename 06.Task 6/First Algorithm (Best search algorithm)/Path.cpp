#include "Path.h"

Path::Path() {
    State initState = State();
    path.push_back(initState);
}

Path::Path(const Path &oldPath, const State &newState) {
    // Copy the old path
    path = oldPath.path;

    // Append the new state to the path
    path.push_back(newState);
}

Path::~Path() {
    // Clear the list without deleting the states
    path.clear();
}

bool Path::isGoalReached() const {
    return path.back().isGoal();
}

int Path::getHeuristic() const {
    return path.back().getHeuristic();
}

vector<Path> Path::generatePaths() {
    std::vector<State> newStates = path.back().generateStates();
    std::vector<Path> resultPaths;

    for (auto &newState: newStates) {
        resultPaths.emplace_back(*this, newState);
    }
    return resultPaths;
}

int Path::getSize() const {
    return (int)path.size();
}

Path Path::getInitPath() {
    static Path initPath;
    return initPath;
}

bool operator>(const Path &p1, const Path &p2) {
    return p1.getHeuristic() > p2.getHeuristic();
}

void Path::print() const {
    for (size_t i = 0; i < path.size(); ++i) {
        std::cout << "Step " << i + 1 << ":" << std::endl;
        path[i].print();
        std::cout << std::endl;
    }
}

bool Path::equals(Path obj) {
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

bool Path::isBadPath() const {
    if (path.size() >= 16) {
        if (path[15].getHeuristic() >= 3) {
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