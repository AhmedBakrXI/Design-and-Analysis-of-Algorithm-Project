/*****************************************************************//**
 * @file   Square.cpp
 * @brief  Implementation of the Square class.
 * 
 * @author eslam
 * @date   March 2024
 *********************************************************************/

#include "Square.h"

// counter initialization
int Square::counter = 0;

bool Square::placeKnight(const string* knight)
{
    ///
    /// Check if the square already contains a knight
    /// no more than one piece in the square.
    /// no piece takes other piece.
    /// 
    if (this->knight != nullptr)
        return false;

    // Place the knight on the square
    this->knight = knight;
    return true;
}// placeKnight()

const string* Square::getKnight() const
{
    return this->knight;
}// getKnight()

const string* Square::removeKnight()
{
    // If the square is empty, return nullptr
    if (this->knight == nullptr)
        return nullptr;

    // Save the value of the previous knight
    this->prevValue = this->knight;

    // Remove the knight from the square
    this->knight = nullptr;
    // Return pointer to the removed knight
    return this->prevValue;
}// removeKnight()

const string* Square::getPrevValue() const
{
    return this->prevValue;
}// getPrevValue()

int Square::getPosNo() const
{
    return this->posNo;
}

int Square::getHeuristicCost(bool isBlack) const {
    return isBlack ? this->heuristicCost.second : this->heuristicCost.first;
}

void Square::setHeuristicCost(pair<int, int> heuristicCost) {
    this->heuristicCost = heuristicCost;
}
// getPosNo()