//
// Created by eslam on 01/05/2024.
//

#include "State.h"

 vector<State> State::moveChess(int position,vector<char>currentState)
{
   vector<State> ret;

   vector<pair<int,int>> possibleMoves={ {-1, -2}, {-1 ,2}, {-2, -1}, {-2, 1},
			 {1, -2}, {1, 2},{2, -1}, {2, 1}};
   for(auto val:possibleMoves)
   {
       vector<char> temp = currentState;

		int rowMove = (position/3) + val.first;
		int colMove = (position%3)+ val.second;
       if(isValidMove(rowMove,colMove,3,4))
		{
			if(currentState[colMove+rowMove*3]=='E')
			{
				temp[colMove+rowMove*3]=temp[position];
				temp[position] = 'E';
                State container  = State(temp);
               container.calculateHeuristic();
				ret.push_back(container);

			}
       }
   }



return ret;
}

void State::calculateHeuristic()
{
	int sum=0;
  for(int idx =0; idx<(int)state.size();idx++)
  {
   if(state[idx]=='W')
   {

       sum +=(3-((idx)/3));

   }else if(state[idx]=='B')
   {
       sum+= (idx/3);

   }
  }
  heuristic=sum;
  //cout << endl;
}

   bool State::isGoal() const {
       vector<char> reference = {'B','B','B','E','E','E','E','E','E','W','W','W'};
       for(int idx = 0; idx <(int) reference.size();idx++)
       {
           if(reference[idx] != getState()[idx])
           return false;
       }
       return true;
   }
   bool State::isValidMove(int row, int col,int actualCol,int actualRow) {
	// Check if the move is within the bounds of the chessboard
	return (row >= 0 && row < actualRow && col >= 0 && col < actualCol);
}
   vector<State> State::generateStates() {
      vector<State> returnVal,whiteKnights,blackKnights;

      for(int idx=0; idx<(int)getState().size();idx++)
      {

       if(state[idx]=='W')
       {
           whiteKnights = moveChess(idx,getState());

           for(auto val:whiteKnights)
			returnVal.push_back(val);

       }else if(state[idx]=='B')
       {

              blackKnights = moveChess(idx,getState());
               for(auto val:blackKnights)
			    returnVal.push_back(val);

       }
      }
      return returnVal;



   }