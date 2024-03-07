#include "ChessBoard.h"

ChessBoard::ChessBoard()
{
	
	// construct and add squares
	for (int rowNo = 0; rowNo < 4; rowNo++) {
		vector<Square> row;
		for (int i = 0; i < 3; i++) {
			row.push_back(Square());
		}
		this->squars.push_back(row);
	}

	//construct knights
	//Black values
	this->knights.push_back("B1"); //0
	this->knights.push_back("B2"); //1
	this->knights.push_back("B3"); //2

	// White values
	this->knights.push_back("W1"); //3
	this->knights.push_back("W2"); //4
	this->knights.push_back("W3"); //5



	// add white knights to the first row
	for (int i = 0; i < 3; i++) {
		this->squars[0][i].placeKnight(&this->knights[3 + i]);
	}

	// add black knights to the last row
	for (int i = 0; i < 3; i++) {
		this->squars[3][i].placeKnight(&this->knights[i]);
	}
}

void ChessBoard::printBoard()
{
	for (vector<Square> row : this->squars) {
		for (Square square : row) {
			const string* value = square.getKnight();
			if (value == nullptr) {
				cout << "Em ";
				continue;
			} 

			cout << *value << " ";
		}
		cout << endl;
	}
	cout << endl;
}

Square* ChessBoard::getSquare(int row, int col)
{
	return &this->squars[row][col];
}

Square* ChessBoard::getSquare(int posNo)
{
	int row = posNo / 3;
	int col = posNo % 3;
	return this->getSquare(row, col);
}
