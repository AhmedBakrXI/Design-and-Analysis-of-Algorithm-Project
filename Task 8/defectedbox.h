#ifndef DEFECTEDBOX_H
#define DEFECTEDBOX_H

#include "box.h"
class DefectedBox : public Box
{
    public:
        DefectedBox();
        DefectedBox(double weight);
        virtual ~DefectedBox();

    double getTotalWeight() override ;

    double pickPiece () override;

};

#endif // DEFECTEDBOX_H
