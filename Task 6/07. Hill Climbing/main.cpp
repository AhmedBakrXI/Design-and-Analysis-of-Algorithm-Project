#include <iostream>
#include "Path.h"
#include <queue>
#include <chrono>

using namespace std;

Path solvePuzzle() {
    Path initPath = Path::getInitPath();
    priority_queue<Path, std::vector<Path>, greater<Path>> pq;

    pq.push(initPath);
    while (!pq.empty()) {
        Path currentPath = pq.top();
        pq.pop();

        // for testing
        /*if(currentPath.getSize() == 15){
            currentPath.print();
            cout << "**********************************************************\n";
        }*/
        if (currentPath.isGoalReached()) {
            return currentPath;
        }

        vector<Path> newPaths = currentPath.generatePaths();
        for (auto const newPath: newPaths) {
            if (newPath.getSize() <= 17) {
                bool add = true;
                // Copy elements to a vector
                std::vector<Path> vec;
                priority_queue<Path, vector<Path>, greater<Path>> copy = pq;
                while (!copy.empty()) {
                    vec.push_back(copy.top());
                    copy.pop();
                }
                for (Path path : vec) {
                    if (path.isSameEnd(newPath) && newPath.getSize() == path.getSize()) {
                        add = false;
                        break;
                    }
                }
                if (add) {
                    pq.push(newPath);
                }
            }
        }
    }

    return Path::getInitPath();
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    Path result = solvePuzzle();
    result.print();
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = end - start;
    auto minutes = std::chrono::duration_cast<std::chrono::minutes>(duration).count();

    std::cout << "Execution time: " << minutes << " minutes\n";
    return 0;
}
