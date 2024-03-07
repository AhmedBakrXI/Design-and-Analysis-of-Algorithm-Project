#include "Graph.h"

vector<Move*>* Graph::solvePuzzle()
{
	deque<int> queue;
	queue.push_back(9);
	queue.push_back(11);

	int doneSwapping = 0;
	int movesNo = 0;
	vector<Move*>* moves = new vector<Move*>(16);

	while (doneSwapping != 6) {
		int focusedPos = queue.at(0);
		queue.pop_front();

		Square* focusedSquare = this->board->getSquare(focusedPos);
		vector<pair<Cost, Square*>>* focusedList = &this->nodes.at(focusedPos);

		// If empty add its neighbors to the queue
		if (focusedSquare->getKnight() == nullptr) {
			for (auto& node : this->nodes.at(focusedPos)) {
				queue.push_back(node.second->getPosNo());
			}
			continue;
		}

		// If not empty, check if it can move to another position or not.
		// To move to another position, the cost must not be inf (represented by -1),
		// and the other node we will move to must be empty, also the prevValue of the 
		// other node must be different from the knight we need to move.
		//
		// Then after transferring, we must check if it arrive to its final destination,
		// to check that it must be transferred to a node that has only one edge and it
		// can't be transferred to another node.
		// if that happened, increment the "doneSwapping" counter.
		// Either ways, we will add the new position to the front of the queue.
		
		//get the color of knight, 0 for white, 1 for black
		int color = focusedSquare->getKnight()->at(0) == 'B';
		//flag to know if any movement happened
		bool moved = false;
		//flag to know if it arrive to its final destination.
		bool finalDest = true;
		// destination position in the focused list, so it could be added for only 
		// one time to the queue.
		int destPos = -1;
		//check if it can move to another position or not, and move to the 1st 
		//available position.
		for (int i = 0; i < focusedList->size(); i++) {
			pair<Cost, Square*>* focusedPair = &focusedList->at(i);
			if (focusedPair->second->getKnight() == nullptr) {
				if (
					focusedPair->first.getCost(color) != -1 &&
					(
						focusedPair->second->getPrevValue() == nullptr ||
						*focusedPair->second->getPrevValue() != *focusedSquare->getKnight()
						)
					) {
					focusedPair->second->placeKnight(focusedSquare->removeKnight());
					moved = true;
					destPos = i;


					//check for final destination
					int pos = focusedPair->second->getPosNo();

					//destination list
					vector<pair<Cost, Square*>>* destList = &this->nodes.at(pos);
					for (auto& pairX : *destList) {
						if (pairX.first.getCost(color) != -1) {
							finalDest = false;
							break;
						}
					}
					if (finalDest) {
						doneSwapping++;
					}

					//store the move data
					int oldPos = focusedSquare->getPosNo();
					int newPos = focusedPair->second->getPosNo();
					string knightMoved = *focusedPair->second->getKnight();
					moves->push_back(new Move(oldPos, newPos, knightMoved));


					break;
				}



			}
		}

		//add neighbors to the queue
		for (int i = 0; i < focusedList->size(); i++) {
			if (i == destPos) {
				queue.push_front(i);
				continue;
			}

			queue.push_back(focusedList->at(i).second->getPosNo());
		}

		//increment the moved counter and print the board
		if (moved) {
			//print move number
			movesNo++;
			cout << "step number: " << movesNo << endl;
			//print board
			this->board->printBoard();
			//print the move details
			moves->back()->printMove();
			cout << endl;
		}
	}

	// print the total number of moves
	cout << endl << "Total number of moves: " << movesNo;
	return moves;
}

Graph::Graph(ChessBoard& board)
{
	this->board = &board;

	//initialization according to the pattern
	vector<pair<Cost, Square*>> row;
	// square 0:
	
	//connect to square 5
	row.push_back(
		pair<Cost, Square*>(
			Cost(0, -1),
			board.getSquare(5)
			)
	);

	// Add row to the adj list.
	this->nodes.push_back(row);
	//////////////////////////////////////////////
	

	// square 1:
	row.clear();
	//connect to square 8
	row.push_back(
		pair<Cost, Square*>(
			Cost(0, -1),
			board.getSquare(8)
			)
	);
	// Add row to the adj list.
	this->nodes.push_back(row);
	//////////////////////////////////////////////
	 
	// square 2:
	row.clear();
	//connect to square 3
	row.push_back(
		pair<Cost, Square*>(
			Cost(0, -1),
			board.getSquare(3)
			)
	);
	// Add row to the adj list.
	this->nodes.push_back(row);
	//////////////////////////////////////////////

	// square 3:
	row.clear();
	//connect to square 2
	row.push_back(
		pair<Cost, Square*>(
			Cost(-1, 0),
			board.getSquare(2)
			)
	);

	//connect to square 8
	row.push_back(
		pair<Cost, Square*>(
			Cost(-1, 1),
			board.getSquare(8)
			)
	);

	//connect to square 10
	row.push_back(
		pair<Cost, Square*>(
			Cost(0, -1),
			board.getSquare(10)
			)
	);
	// Add row to the adj list.
	this->nodes.push_back(row);
	//////////////////////////////////////////////

	// square 4:
	row.clear();
	
	// Add row to the adj list.
	this->nodes.push_back(row);
	//////////////////////////////////////////////

	// square 5:
	row.clear();
	//connect to square 0
	row.push_back(
		pair<Cost, Square*>(
			Cost(-1, 0),
			board.getSquare(0)
			)
	);

	//connect to square 6
	row.push_back(
		pair<Cost, Square*>(
			Cost(0, -1),
			board.getSquare(6)
			)
	);
	// Add row to the adj list.
	this->nodes.push_back(row);
	//////////////////////////////////////////////

	// square 6:
	row.clear();
	//connect to square 1
	row.push_back(
		pair<Cost, Square*>(
			Cost(-1, 0),
			board.getSquare(1)
			)
	);

	//connect to square 11
	row.push_back(
		pair<Cost, Square*>(
			Cost(0, -1),
			board.getSquare(11)
			)
	);
	// Add row to the adj list.
	this->nodes.push_back(row);
	//////////////////////////////////////////////	

	// square 7:
	row.clear();
	// Add row to the adj list.
	this->nodes.push_back(row);
	//////////////////////////////////////////////	


	// square 8:
	row.clear();
	//connect to square 3
	row.push_back(
		pair<Cost, Square*>(
			Cost(-1, 0),
			board.getSquare(3)
			)
	);

	//connect to square 9
	row.push_back(
		pair<Cost, Square*>(
			Cost(0, -1),
			board.getSquare(9)
			)
	);
	// Add row to the adj list.
	this->nodes.push_back(row);
	//////////////////////////////////////////////


	// square 9:
	row.clear();
	//connect to square 8
	row.push_back(
		pair<Cost, Square*>(
			Cost(-1, 0),
			board.getSquare(8)
			)
	);
	// Add row to the adj list.
	this->nodes.push_back(row);
	//////////////////////////////////////////////

	// square 10:
	row.clear();
	//connect to square 5
	row.push_back(
		pair<Cost, Square*>(
			Cost(-1, 0),
			board.getSquare(5)
			)
	);
	// Add row to the adj list.
	this->nodes.push_back(row);
	//////////////////////////////////////////////


	// square 11:
	row.clear();
	//connect to square 6
	row.push_back(
		pair<Cost, Square*>(
			Cost(-1, 0),
			board.getSquare(6)
			)
	);
	// Add row to the adj list.
	this->nodes.push_back(row);
	//////////////////////////////////////////////

}

void Graph::printGraph()
{
	for (size_t i = 0; i < nodes.size(); ++i) {
		cout << "Node " << i << ":" << endl;
		for (size_t j = 0; j < nodes[i].size(); ++j) {
			cout << "  Cost: White - " << nodes[i][j].first.whiteCost;
			cout << ", Black - " << nodes[i][j].first.blackCost << endl;
			cout << "  Square: " << nodes[i][j].second->getPosNo();
			cout << ", Value: ";
			if (nodes[i][j].second->getKnight() == nullptr) {
				cout << "EM";
			}
			else {
				cout << *nodes[i][j].second->getKnight();
			}
			cout << endl << endl;
		}
		cout << endl;
	}
}


