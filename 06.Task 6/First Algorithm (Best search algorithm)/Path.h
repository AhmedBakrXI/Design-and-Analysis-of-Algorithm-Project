#ifndef INC_07_HILL_CLIMBING_PATH_H
#define INC_07_HILL_CLIMBING_PATH_H

#include <iostream>
#include "State.h"
#include <random>

using namespace std;

/**
 * Represents a path consisting of multiple states in a hill-climbing search.
 *
 * @details The Path class encapsulates a sequence of states traversed during a hill-climbing search algorithm.
 * It provides methods to manipulate and analyze the path, such as adding new states, checking if the goal state
 * has been reached, computing the heuristic value of the path, generating successor paths, and determining
 * the size of the path.
 */
class Path {
private:
    ///
    /// A vector containing the states in the path.
    ///
    vector<State> path;

    /**
     * Default constructor for the Path class.
     *
     * @brief Constructs a new path with the initial state only.
     *
     * @details This constructor initializes a new path with the initial state only. It creates a new instance
     * of the State class to represent the initial state and adds it to the path.
     */
    Path();

public:

    /**
     * Constructor for creating a new path by extending an existing path with a new state.
     *
     * @brief Constructs a new path by appending a new state to an existing path.
     *
     * @param oldPath The previous path to be extended.
     * @param newState The new state to be added to the path.
     *
     * @details This constructor creates a new path by copying the states from the provided old path
     * and then appending the new state to it. It constructs a new instance of the Path class based on
     * the combination of the old path and the new state.
     */
    Path(const Path &oldPath, const State &newState);

    /**
     * Destructor.
     */
    ~Path();

    /**
     * Checks if the goal state has been reached in the path.
     *
     * @brief Determines whether the goal state has been reached in the path.
     *
     * @return True if the goal state has been reached, false otherwise.
     */
    [[nodiscard]] bool isGoalReached() const;

    /**
     * Retrieves the heuristic value of the current state in the path.
     *
     * @brief Gets the heuristic value of the current state in the path.
     *
     * @return The heuristic value of the current state.
     */
    [[nodiscard]] int getHeuristic() const;

    /**
     * Generates successor paths by adding possible next states to the current path.
     *
     * @brief Expands the current path by generating successor paths.
     *
     * @return A vector of successor paths generated from the current path.
     */
    vector<Path> generatePaths();

    /**
     * Retrieves the number of states in the path.
     *
     * @brief Gets the size of the path.
     *
     * @note The size = the number of moves + 1.
     *
     * @return The number of states in the path.
     */
    [[nodiscard]] int getSize() const;

    /**
     * Generates a path containing only the initial state.
     *
     * @brief Creates a new path with the initial state only.
     *
     * @return A path containing the initial state only.
     */
     static Path getInitPath();

    /**
     * Overloaded greater than operator for comparing paths based on heuristic values.
     *
     * @brief Compares two paths based on their heuristic values.
     *
     * @param p1 The first path to compare.
     * @param p2 The second path to compare.
     *
     * @return True if the heuristic value of p1 is greater than that of p2, false otherwise.
     */
    friend bool operator>(const Path &p1, const Path &p2);

    /**
     * Prints the states in the path.
     *
     * @brief Displays the states in the path.
     */
    void print() const;


    /**
     * Checks if this path is equal to another path.
     *
     * @brief Determines whether this path is equal to another path.
     *
     * @param obj The path to compare with.
     *
     * @return True if the paths are equal, false otherwise.
     */
    bool equals(Path obj);

    /**
     * Checks if the path exhibits characteristics of a potentially inefficient or suboptimal solution path.
     *
     * @brief Determines if the path is potentially suboptimal or inefficient.
     *
     * @return True if the path is considered potentially inefficient or suboptimal, false otherwise.
     *
     * @details This method analyzes various aspects of the path to determine if it exhibits characteristics
     *          of inefficiency or suboptimal. It checks if the path length exceeds a threshold and if the
     *          heuristic value increases at any point along the path, which may indicate a non-ideal solution
     *          path.
     *
     */
    [[nodiscard]] bool isBadPath() const;
};


#endif //INC_07_HILL_CLIMBING_PATH_H
