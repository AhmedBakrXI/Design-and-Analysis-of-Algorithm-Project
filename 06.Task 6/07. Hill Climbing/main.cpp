#include <iostream>
#include "Path.h"
#include <queue>
#include <chrono>

using namespace std;

Path solvePuzzle() {
    Path initPath = Path::getInitPath();
    priority_queue<Path, std::vector<Path>, greater<Path>> pq;
    vector<Path> visitedPaths = vector<Path>();
    visitedPaths.push_back(initPath);
    pq.push(initPath);
    while (!pq.empty()) {

        Path currentPath = pq.top();
        pq.pop();

        cout << "path: " << currentPath.getSize() << "\t";
        cout << "h: " << currentPath.getHeuristic() << "\t";

        if (currentPath.isGoalReached()) {
            return currentPath;
        }

        if(currentPath.getSize()  == 11){
            cout << "\n**************************************************************\n";
        }
        vector<Path> newPaths = currentPath.generatePaths();

        for (auto newPath: newPaths) {
            if (newPath.getSize() <= 17) {
                bool add = true;

                // check if the new path is visited already, if yes don't add it to the queue
                for(const Path& toCompare : visitedPaths){
                    if(newPath.equals(toCompare)){
                        add = false;
                        break;
                    }
                }
                if (add && !newPath.isBadPath()) {
                    pq.push(newPath);
                    visitedPaths.push_back(newPath);
                }
            }
        }
        cout << "pq: " << pq.size() << endl;
        cout << "visited: " << visitedPaths.size() << endl;
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
