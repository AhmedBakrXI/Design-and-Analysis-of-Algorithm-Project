#include "normalbox.h"
#include <iostream>
using namespace std ;
NormalBox::NormalBox(double weight)
{

        for (int i = 0; i < 50; ++i) {
            pieces[i] = Piece(weight);

        }


    //ctor
}

double NormalBox :: getTotalWeight()   {
        double totalWeight = 0;
        for (int i = 0; i < 50; ++i) {
            totalWeight += pieces[i].Getweight();

        }
        return totalWeight;
    }

    double NormalBox:: pickPiece ()
    { return pieces[0].Getweight();
    }


NormalBox::~NormalBox()
{
    //dtor
}
