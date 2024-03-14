//
// Created by eslam on 14/03/2024.
//

#include "PossibleMoves.h"

vector<Move> PossibleMoves::allMoves() {
    vector<Move> result;
    for(int i = 0; i<12; i++){
        // get the square
        Square& square = *board.getSquare(i);
        // check if the square if empty go to the next square
        if(square.getKnight() == nullptr){
            continue;
        }

        // go through each edge of the graph, check if possible move, then get the difference in score and store it.
        for(const auto& adjSquare :graph.nodes[i]){
            // Can't move there, a knight is already in this place
            if(adjSquare->getKnight() == nullptr){
                continue;
            }

            // get difference in heuristic score and store it
            result.push_back(
                    Move(
                            i,
                            adjSquare->getPosNo(),
                            *square.getKnight(),
                            square.getHeuristicCost(square.getKnight()[0] == "B") - adjSquare->getHeuristicCost(adjSquare->getKnight()[0] == "B")
                                  )
                                  );


        }

    }
    sort(result.begin(), result.end(), [](const Move& a, const Move& b) {
        return a.getTotalHeuristicDifference() < b.getTotalHeuristicDifference();
    });
    return result;
}
