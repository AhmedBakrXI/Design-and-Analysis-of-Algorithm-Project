#ifndef BOX_H
#define BOX_H

#include "Piece.h" // You need to include Piece.h to use the Piece class

// Base class Box
class Box {


protected:
    Piece pieces[50];

public:
    virtual  double getTotalWeight() ;
    virtual double pickPiece();
    ~Box();
    Box();
};

#endif // BOX_H
