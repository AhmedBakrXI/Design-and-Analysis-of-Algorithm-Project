#include "chesspiece.h"
#include "game.h"
#include <QDebug>

extern Game *game;
ChessPiece::ChessPiece(QString team, QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    side = team;
    isPlaced = true;
    firstMove = true;
}



void ChessPiece::setCurrentBox(ChessBox *box)
{

    currentBox = box;
}

ChessBox *ChessPiece::getCurrentBox()
{
    return currentBox;
}

QString ChessPiece::getSide()
{
    return side;
}

void ChessPiece::setSide( QString value)
{
    side = value;
}

bool ChessPiece::getIsPlaced()
{
    return isPlaced;
}

void ChessPiece::setIsPlaced(bool value)
{
    isPlaced = value;

}
QList<ChessBox *> ChessPiece::moveLocation()
{
    return location;
}
void ChessPiece::decolor()
{
    for(size_t i = 0, n = location.size(); i < n;i++) {
         location[i]->resetOriginalColor();
    }
}


