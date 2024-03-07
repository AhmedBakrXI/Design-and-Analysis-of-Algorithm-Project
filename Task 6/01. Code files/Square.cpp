#include "Square.h"

// counter initialization
int Square::counter = 0;

bool Square::placeKnight(const string* knight)
{
	// no more than one piece in the square.
	// no piece takes other piece.
	if (this->knight != nullptr) {
		return false;
	}

	this->knight = knight;
	return true;
}

const string* Square::getKnight()
{
	return this->knight;
}

const string* Square::removeKnight()
{
	// empty case
	if (this->knight == nullptr) {
		return nullptr;
	}

	// mark the knight as the prev one.
	this->prevValue = this->knight;

	//get and remove the knight value
	const string* result = this->knight;
	this->knight = nullptr;

	return result;
}

const string* Square::getPrevValue()
{
	return this->prevValue;
}

int Square::getPosNo()
{
	return this->posNo;
}
