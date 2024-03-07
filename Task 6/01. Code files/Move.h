#pragma once

#ifndef MOVE_H
#define MOVE_H

#include <string>
#include <iostream>
using namespace std;

class Move
{
public:
	Move(int oldPos, int newPos, string knight): oldPos(oldPos), newPos(newPos), knight(knight) {}
	string getknight() {
		return this->knight;
	}

	int getOldPos() {
		return this->oldPos;
	}

	int getNewPos() {
		return this->newPos;
	}

	void printMove() {
		cout << "Move: " << knight << " from " << oldPos << " to " << newPos << endl;
	}
private:
	int oldPos;
	int newPos;
	string knight;
};



#endif // !MOVE_H


