//
// Created by AHMED BAKR on 3/1/2024.
//

#ifndef CLOSEDCHESSTOUR_TOUR_H
#define CLOSEDCHESSTOUR_TOUR_H
#define N 8

void initializeTheBoard();

bool searchClosedKnightTour(int x_init, int y_init);

/**<_ Helper Methods */
bool isOnBoardSquare(int x, int y);

bool isEmptySquare(int x, int y);

bool isNeighbourSquare(int x1, int y1, int x2, int y2);

bool pickNextMove(int &x, int &y);

int getSquareDegree(int x, int y);

void printChessBoard();

#endif //CLOSEDCHESSTOUR_TOUR_H
