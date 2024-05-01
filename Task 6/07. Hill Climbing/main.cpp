#include <iostream>
#include "Path.h"
#include <queue>

using namespace std;

Path solvePuzzle() {
    Path initPath = Path::getInitPath();
    priority_queue<Path, std::vector<Path>, greater<Path>> pq;

    pq.push(initPath);
    while (!pq.empty()) {
        Path currentPath = pq.top();
        pq.pop();

        if (currentPath.isGoalReached()) {
            return currentPath;
        }

        vector<Path> newPaths = currentPath.generatePaths();
        for (auto const path: newPaths) {
            if (path.getSize() <= 17) {
                pq.push(path);
            }
        }
    }

    return Path::getInitPath();
}

int main() {
    Path result = solvePuzzle();
    result.print();
    return 0;
}
