#include "chessboard.h"
#include "chessbox.h"
#include "game.h"
#include "Square.h"
#include "Graph.h"

#include "knight.h"
#include <QTime>
#include<QCoreApplication>
#include <QEventLoop>
extern Game *game;
ChessBoard::ChessBoard()
{
    setUpBlack();
    setUpWhite();
}
void ChessBoard::drawBoxes(int x,int y)
{
    int SHIFT = 100;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 3; j++)
        {
            ChessBox *box = new ChessBox();
            game->collection[i][j] = box;
            box->rowLoc = i;
            box->colLoc = j;
            box->setPos(x+SHIFT*j,y+SHIFT*i);
            if((i+j)%2==0)
                box->setOriginalColor(Qt::white);
            else
                box->setOriginalColor(Qt::cyan);
            game->addToScene(box);



        }
    }

}

void ChessBoard::delay()
{
    QTime dieTime= QTime::currentTime().addSecs(1);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
void ChessBoard::addChessPiece() {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 3; j++)
        {

            ChessBox *box =game->collection[i][j];
            if(i ==3) {
                static int k;
                box->placePiece(black[k]);
                game->alivePiece.append(black[k]);
                game->addToScene(black[k++]);
            }
            if(i==0) {
                static int h;
                box->placePiece(white[h]);
                game->alivePiece.append(white[h]);
                game->addToScene(white[h++]);
            }

        }
    }
    delay();
    chess_board newBoard;
    Graph *graph = new Graph(newBoard);
    vector<Move>  moves = graph->solvePuzzle();
    string knightName;
    int newPlace;

    for(int i =0; i <(int) moves.size();i++)
    {

        knightName = moves[i].getknight();
        newPlace = moves[i].getNewPos();
        int knightIndex = knightName[1] - '0';
        delay();
        ChessBox *box;
        if((newPlace+1)%3==0)
            box=game->collection[(newPlace+1)/3-1][2];
        else if((newPlace+1)%3==1)
            box =game->collection[(newPlace+1)/3][0];
        else
            box =game->collection[(newPlace+1)/3][1];
        if(knightName[0]=='B')
        {
            box->placePiece(black[knightIndex-1]);
            game->alivePiece.append(black[knightIndex-1]);
            game->addToScene(black[knightIndex-1]);

        }
        else if(knightName[0]=='W')
        {
            box->placePiece(white[knightIndex-1]);
            game->alivePiece.append(white[knightIndex-1]);
            game->addToScene(white[knightIndex-1]);

        }

    }
}

void ChessBoard::setUpWhite()
{
    ChessPiece *piece;
    for(int i = 0; i < 3; i++) {
        piece = new Knight("WHITE");
        white.append(piece);
    }


}

void ChessBoard::setUpBlack()
{
ChessPiece *piece;
    for(int i = 0; i < 8; i++) {
        piece = new Knight("BLACK");
        black.append(piece);
    }
}


void ChessBoard::reset() {
    int k = 0; int h = 0;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 3; j++)
        {

            ChessBox *box =game->collection[i][j];
            box->setHasChessPiece(false);
            box->setChessPieceColor("NONE");
            box->currentPiece = NULL;
            if(i==3) {

                box->placePiece(black[k]);
                black[k]->setIsPlaced(true);
                black[k]->firstMove = true;
                game->alivePiece.append(black[k++]);

            }
            if(i ==0) {

                box->placePiece(white[h]);
                white[h]->setIsPlaced(true);
                white[h]->firstMove = true;
                game->alivePiece.append(white[h++]);

            }

        }
    }
}
