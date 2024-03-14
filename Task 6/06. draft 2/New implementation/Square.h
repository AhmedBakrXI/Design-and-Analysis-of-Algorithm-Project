/*****************************************************************//**
 * @file   Square.h
 * @brief Declaration of the Square class.
 * 
 * @author eslam
 * @date   March 2024
 *********************************************************************/

#pragma once
#ifndef SQUARE_H
#define SQUARE_H

#include <string>

using namespace std;

/**
 * @brief Represents a square on the chessboard.
 */
class Square
{
public:
    /**
     * @brief Constructor for the Square class.
     * Initialize the position number of the square as its declaration order.
     */
    Square() : posNo(counter++), knight(nullptr), prevValue(nullptr), heuristicCost({0,0}) {}

    /**
     * @brief Places a knight on the square.
     * @param knight Pointer to the knight to be placed.
     * @return True if the knight was successfully placed, false otherwise.
     * @details Returns false if the square already contains a knight.
     */
    bool placeKnight(const string* knight);

    /**
     * @brief Retrieves the knight on the square.
     * @return Pointer to the knight on the square, or nullptr if no knight is present.
     */
    const string* getKnight() const;

    /**
     * @brief Removes the knight from the square.
     * @return Pointer to the removed knight.
     * @details If a knight is present on the square, it is removed, and its value is stored as the previous value.
     */
    const string* removeKnight();

    /**
     * @brief Removes the knight from the square.
     * @return Pointer to the removed knight.
     * @details If a knight is present on the square, it is removed, and its value is stored as the previous value.
     */  
    const string* getPrevValue() const;

    /**
     * @brief Retrieves the position number of the square.
     * @return The position number of the square.
     */
    int getPosNo() const;

private:
    //Static counter for numbering the squares.
    static int counter;
    //The position number of the square.
    int posNo;
    /**
     * @brief Pointer to the knight placed on the square.
     *
     * The name of the piece is constructed from a character ('B' for black knight, 'W' for white knight)
     * followed by a number representing the piece according to the documentation.
     *
     * The value is nullptr if the square is empty.
     *
     * Note: The number is in the range [1,3], where 1 represents the most left piece at the beginning.
     */
    const string* knight;

    // The name of the last piece entered the square, used for certain conditions.
    const string* prevValue;

    pair<int, int> heuristicCost;
public:
    // 0 for white, 1 for black
    int getHeuristicCost(bool isBlack) const;

    void setHeuristicCost(pair<int, int> heuristicCost);

};// class Square
#endif // !SQUARE_H