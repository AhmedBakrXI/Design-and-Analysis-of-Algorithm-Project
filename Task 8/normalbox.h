#ifndef NORMALBOX_H
#define NORMALBOX_H

#include "box.h"


class NormalBox : public Box
{
   public:
    NormalBox(double weight) ;
    virtual ~NormalBox();

    double getTotalWeight() override;

    double pickPiece () override ;

};

#endif // NORMALBOX_H
