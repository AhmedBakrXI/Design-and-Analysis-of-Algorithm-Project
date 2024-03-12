#include <iostream>
#include "defectedbox.h"
using namespace std;
DefectedBox::DefectedBox()
{
    //ctor
}

  DefectedBox:: DefectedBox(double weight) {
        for (int i = 0; i < 50; ++i) {
            pieces[i] = Piece(weight - 1); // Defected pieces weigh 1 kg less
        }
    }

double DefectedBox:: getTotalWeight () {
        double totalWeight = 0;
        for (int i = 0; i < 50; ++i) {
            totalWeight += pieces[i].Getweight();
        }
        return totalWeight;
    }

    double DefectedBox:: pickPiece ()
    { return pieces[0].Getweight();
    }


DefectedBox::~DefectedBox()
{
    //dtor
}
