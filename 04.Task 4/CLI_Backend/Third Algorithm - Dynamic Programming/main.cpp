#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <cmath>

using namespace std;

// Structure to represent a node in the search tree
struct TreeNode {
    vector<int> state;
    TreeNode* parent;
    int lastMovedDisk;
    int cost; // Heuristic cost
};

// Function to move a single disk from one peg to another
void moveDisk(int disk, int source, int destination) {
    cout << "Move disk " << disk << " from peg " << source << " to peg " << destination << endl;
}

// Function to check if a move is valid
bool isValidMove(int disk, int source, int destination) {
    return disk != -1 && source != -1 && destination != -1 && source != destination;
}

// Custom hash function for vector<int>
struct VectorHash {
    size_t operator()(const std::vector<int>& vec) const {
        size_t hash = 0;
        for (int value : vec) {
            hash ^= std::hash<int>{}(value) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};

// Heuristic function: Number of disks not yet in final position
int heuristic(const vector<int>& state, const vector<int>& goalState) {
    int count = 0;
    for (size_t i = 0; i < state.size(); ++i) {
        if (state[i] != goalState[i]) {
            count++;
        }
    }
    return count;
}

// Function to generate child nodes from a parent node
vector<TreeNode*> generateChildren(TreeNode* parent, int numPegs, const vector<int>& goalState) {
    vector<TreeNode*> children;
    for (int source = 1; source <= numPegs; ++source) {
        for (int destination = 1; destination <= numPegs; ++destination) {
            if (isValidMove(parent->lastMovedDisk, source, destination)) {
                TreeNode* child = new TreeNode();
                child->state = parent->state;
                child->state[parent->lastMovedDisk] = destination;
                child->parent = parent;
                child->lastMovedDisk = parent->lastMovedDisk - 1;
                child->cost = parent->cost - 1 + heuristic(child->state, goalState); // Update heuristic cost
                moveDisk(parent->lastMovedDisk, source, destination);
                children.push_back(child);
            }
        }
    }
    return children;
}

// Function to perform A* search
void aStar(TreeNode* initialState, const vector<int>& goalState, int numPegs) {
    unordered_set<vector<int>, VectorHash> visited; // Use custom hash function
    priority_queue<pair<int, TreeNode*>, vector<pair<int, TreeNode*>>, greater<pair<int, TreeNode*>>> frontier;
    frontier.push({initialState->cost, initialState});

    while (!frontier.empty()) {
        TreeNode* current = frontier.top().second;
        frontier.pop();

        if (current->state == goalState) {
            cout << "Goal state reached." << endl;
            return;
        }

        if (visited.find(current->state) == visited.end()) {
            visited.insert(current->state);
            vector<TreeNode*> children = generateChildren(current, numPegs, goalState);
            for (TreeNode* child : children) {
                frontier.push({child->cost, child});
            }
        }
    }

    cout << "Goal state not reachable." << endl;
}

int main() {
    // Example usage
    int numDisks = 3;
    int numPegs = 3;

    // Assuming pegs are numbered 1, 2, 3, ...
    TreeNode* initialState = new TreeNode();
    initialState->state = vector<int>(numDisks, 1);  // All disks on peg 1
    initialState->parent = nullptr;
    initialState->lastMovedDisk = numDisks - 1;
    initialState->cost = heuristic(initialState->state, vector<int>(numDisks, numPegs)); // Heuristic cost for initial state

    vector<int> goalState(numDisks, numPegs);  // All disks on peg numPegs

    aStar(initialState, goalState, numPegs);

    return 0;
}
