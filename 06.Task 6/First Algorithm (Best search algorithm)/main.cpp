#include <iostream>
#include "Path.h"
#include <queue>
#include <chrono>

using namespace std;

/**
 * Solves the puzzle using an iterative improvement algorithm with a priority queue.
 *
 * @brief Solves the puzzle using an iterative improvement algorithm which is the best search algorithm,
 *        an improved version of Hill climbing search algorithm.
 *
 * @return The solution path that leads to the optimum goal state, if no optimum path was found, it will return
 *         the initial path.
 */
Path solvePuzzle() {
    // Initialize the initial path with the starting state
    Path initPath = Path::getInitPath();

    // Initialize a priority queue to store paths with the minimum heuristic value at the top
    priority_queue<Path, std::vector<Path>, greater<>> pq;

    // Initialize a vector to store visited paths
    vector<Path> visitedPaths = vector<Path>();

    // Add the initial path to the visited paths and priority queue
    visitedPaths.push_back(initPath);
    pq.push(initPath);

    // Iteratively explore paths until the priority queue is empty or the optimum path is reached
    while (!pq.empty()) {
        // Get the path with the minimum heuristic value from the priority queue
        Path currentPath = pq.top();
        pq.pop();

        // Check if the goal state is reached
        if (currentPath.isGoalReached()) {
            return currentPath;
        }

        // Generate new paths from the current path
        vector<Path> newPaths = currentPath.generatePaths();

        // Iterate through the new paths
        for (auto newPath: newPaths) {
            // Check if the new path length is within a certain limit
            if (newPath.getSize() <= 17) {
                bool add = true;

                // Check if the new path has already been visited
                for(const Path& toCompare : visitedPaths){
                    if(newPath.equals(toCompare)){
                        add = false;
                        break;
                    }
                }

                // Add the new path to the priority queue and visited paths if it meets criteria
                if (add && !newPath.isBadPath()) {
                    pq.push(newPath);
                    visitedPaths.push_back(newPath);
                }
            }
        }
    }

    // Return the initial path if no solution is found
    return Path::getInitPath();
}

int main() {
    // Start the timer
    auto start = std::chrono::high_resolution_clock::now();

    // Solve the puzzle and print the results
    Path result = solvePuzzle();
    result.print();

    // Stop the timer
    auto end = std::chrono::high_resolution_clock::now();

    // Print the execution time
    auto duration = end - start;
    auto minutes = std::chrono::duration_cast<std::chrono::minutes>(duration).count();

    std::cout << "Execution time: " << minutes << " minutes\n";
    return 0;
}
