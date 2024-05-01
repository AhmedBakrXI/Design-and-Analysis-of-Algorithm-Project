#include <iostream>
#include "Path.h"
#include <queue>
#include <chrono>
#include <algorithm>

using namespace std;

Path solvePuzzle() {
    Path initPath = Path::getInitPath();
    vector<Path> q = vector<Path>();

    q.push_back(initPath);

    while (!q.empty()) {
        Path currentPath = q.front();
        q.erase(q.begin());
        // generate new paths
        vector<Path> newPaths = currentPath.generatePaths();
        //remove any paths larger than 16 node
        int index = 0;
        for (auto newPath: newPaths) {
            if (newPath.getSize() > 17) {
                newPaths.erase(newPaths.begin() + index);
                continue;
            }
            index++;
            q.push_back(newPath);
        }

        // check for any duplicates in the last state of every path in q, keep the best one based on h.
        vector<Path> newValidPaths = vector<Path>();
        while (!q.empty()) {
            Path toCompare = q.back();
            q.pop_back();
            // compare the toCompare with all the paths in the queue, if any duplicate found add the new Valid paths.
            int i = 0;
            bool addToCompare = true;
            for (Path p: q) {
                if (toCompare.isSameEnd(p)) {
                    if (toCompare.getHeuristic() < p.getHeuristic()) {
                        q.erase(q.begin() + i);
                        continue;
                    } else {
                        addToCompare = false;
                        break;
                    }
                }
                i++;
            }
            if(addToCompare){
                newValidPaths.push_back(toCompare);
            }
        }
        // add all newValid paths into the queue
        for (Path p: newValidPaths){
            q.push_back(p);
        }

        // sort the q based on the h, best (smallest in the first)
        sort(q.begin(), q.end(), greater<Path>());
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
