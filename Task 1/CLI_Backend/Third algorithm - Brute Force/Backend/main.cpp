#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;


class Tromino {
public:
    Tromino() : form(-1), pos(pair<int, int>(-1, -1)) {}

    pair<pair<int, int>, pair<int, int>> formPlacement() const;

    int form;
    pair<int, int> pos;
};

void printBoard(vector<vector<int>> &board);

void solve(vector<vector<int>> &board);

int main(int argc, char *argv[]) {
    if (argc < 4) {
        cerr << "Usage: " << argv[0] << " <gridSize> <holeRow> <holeCol>" << endl;
        return 1;
    }

    // Parse command-line arguments
    int boardSize = strtol(argv[1], nullptr, 10);
    int xCoordinate = strtol(argv[2], nullptr, 10) - 1;
    int yCoordinate = strtol(argv[3], nullptr, 10) - 1;


    vector<vector<int>> board(boardSize, vector<int>(boardSize, 0));
    board[xCoordinate][yCoordinate] = -1;

    solve(board);

    printBoard(board);

    return 0;
}

void solve(vector<vector<int>> &board) {
    auto numberOfTrominos = (board.size() * board.size() - 1) / 3;

    vector<Tromino> trominos(numberOfTrominos, Tromino());
    int trominosCounter = 0;
    while (trominosCounter < numberOfTrominos) {
        Tromino &tromino = trominos[trominosCounter];


        // 1. Remove the current tromino from the board, advance to the next form, and attempt placement.
        //
        // 2. Iterate through each position on the board:
        //    - Identify an empty position and attempt to place the tromino there.
        //    - Test each form until a suitable one is found, indicating successful placement.
        //    - Record the successful placement's position and form in the tromino object and update the board.
        //
        // 3. If the tromino cannot be placed at the current position using any form, it implies a prior tromino
        //    may be incorrectly placed. Backtrack to the previous tromino and try alternative forms.
        //
        // 4. Repeat step 3 until all forms for the previous tromino have been attempted.


        // delete the tromino from the board

        if (tromino.pos.first != -1 && tromino.pos.second != -1 && tromino.form != -1) {
            if (tromino.form > 11) {
                tromino.form = 0;
            }
            auto formPositions = tromino.formPlacement();
            board[tromino.pos.first][tromino.pos.second] = 0;
            board[tromino.pos.first + formPositions.first.first][tromino.pos.second +
                                                                 formPositions.first.second] = 0;
            board[tromino.pos.first + formPositions.second.first][tromino.pos.second +
                                                                  formPositions.second.second] = 0;
        } else {
            tromino.pos.first = 0;
            tromino.pos.second = 0;
        }

        if (tromino.pos.first == board.size()) {
            tromino.pos.first = 0;
        }
        for (; tromino.pos.first < board.size(); tromino.pos.first++) {
            bool breakLoop = false;

            if (tromino.pos.second == board.size()) {
                tromino.pos.second = 0;
            }

            for (; tromino.pos.second < board.size(); tromino.pos.second++) {

                // if the missing square skip it or contains another tromino
                if (board[tromino.pos.first][tromino.pos.second] != 0) {
                    continue;
                }


                tromino.form++;

                bool canBePlaced = false;
                // Try all the other forms
                for (; tromino.form < 12; tromino.form++) {
                    auto formPositions = tromino.formPlacement();
                    // Try to place it

                    if (
                            tromino.pos.first < board.size() &&
                            tromino.pos.second < board.size() &&
                            tromino.pos.first + formPositions.first.first < board.size() &&
                            tromino.pos.second +
                            formPositions.first.second < board.size() &&
                            tromino.pos.first + formPositions.second.first < board.size() &&
                            tromino.pos.second +
                            formPositions.second.second < board.size()
                            )
                        if (
                                board[tromino.pos.first][tromino.pos.second] == 0 &&
                                board[tromino.pos.first + formPositions.first.first][tromino.pos.second +
                                                                                     formPositions.first.second] ==
                                0 &&
                                board[tromino.pos.first + formPositions.second.first][tromino.pos.second +
                                                                                      formPositions.second.second] ==
                                0
                                ) {
                            // It can be placed
                            canBePlaced = true;
                            // Add the piece into the board at these positions
                            board[tromino.pos.first][tromino.pos.second] = trominosCounter + 1;
                            board[tromino.pos.first + formPositions.first.first][tromino.pos.second +
                                                                                 formPositions.first.second] =
                                    trominosCounter + 1;
                            board[tromino.pos.first + formPositions.second.first][tromino.pos.second +
                                                                                  formPositions.second.second] =
                                    trominosCounter + 1;
                            break;
                        }

                }

                // if it can't be placed, return to the previous position
                if (canBePlaced) {
                    trominosCounter++;
                    breakLoop = true;
                    break;
                } else {
                    trominosCounter--;
                    tromino.form = -1;
                    tromino.pos = {-1, -1};
                    breakLoop = true;
                    break;
                }
            }


            if (breakLoop) {
                break;
            }
        }
    }
}


void printBoard(vector<vector<int>> &board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            cout << board[i][j] << " \t";
        }
        cout << "\n";
    }
}

pair<pair<int, int>, pair<int, int>> Tromino::formPlacement() const {
    switch (form) {
        // [#] means the base square of tromino
        // # means relative square of tromino.
        case 0:
            //Form 0: [#] #
            //         #
            return {{0, 1},
                    {1, 0}};
        case 1:
            // Form 1: [#] #
            //             #
            return {{0, 1},
                    {1, 1}};
        case 2:
            // Form 2: [#]
            //          #  #
            return {{1, 0},
                    {1, 1}};
        case 3:
            // Form 3:    [#]
            //          #  #
            return {{1, -1},
                    {1, 0}};
        case 4:
            // Form 4:  # [#]
            //          #
            return {{0, -1},
                    {1, -1}};
        case 5:
            // Form 5:  # [#]
            //             #
            return {{0, -1},
                    {1, 0}};
        case 6:
            // Form 6:   #  #
            //          [#]
            return {{-1, 0},
                    {-1, 1}};
        case 7:
            // Form 7:      #
            //          [#] #
            return {{-1, 1},
                    {0,  1}};
        case 8:
            // Form 8:   #
            //          [#] #
            return {{0,  1},
                    {-1, 0}};
        case 9:
            // Form 9:   #  #
            //             [#]
            return {{-1, -1},
                    {-1, 0}};
        case 10:
            // Form 10:   #
            //            # [#]
            return {{-1, -1},
                    {0,  -1}};
        case 11:
            // Form 11:      #
            //            # [#]
            return {{-1, 0},
                    {0,  -1}};
        default:
            cerr << "Invalid form number." << endl;
            return {};
    }
}