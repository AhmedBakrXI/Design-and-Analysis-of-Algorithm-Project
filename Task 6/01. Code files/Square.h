#pragma once
#ifndef SQUARE_H
#define SQUARE_H

#include <string>
using namespace std;


class Square
{
public:
	Square() {
		posNo = counter;
		counter++;
		knight = nullptr;
		prevValue = nullptr;
	}

	bool placeKnight(const string* knight);
	const string* getKnight();
	const string* removeKnight();
	const string* getPrevValue();
	int getPosNo();

private:
	// Help with numbering the squares at initialization.
	static int counter;

	// The number given to the square according to the documentation, where zero is the left upper position
	int posNo;

	/**
	 * The name of the piece, It is constructed from a Char with a number.
	 * Char:
	 *	- 'B' for black knight.
	 *	- 'W' for white knight.
	 * 
	 * Number: the number of the piece according to the documentation.
	 * 
	 * The value will be nullptr if the square is empty.
	 * @note the number is in this range : {1,3}, which one is the most left piece at beginning.
	 */
	const string* knight;

	// The name of the last piece entered the square, used for some conditions.
	const string* prevValue;
};


#endif // !SQUARE_H
