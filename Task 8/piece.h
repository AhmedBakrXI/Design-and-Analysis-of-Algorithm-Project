#ifndef PIECE_H
#define PIECE_H


class Piece
{
    public:
        Piece();
        Piece(double w) ;

        virtual ~Piece();

        double Getweight() { return weight; }
        void Setweight(double val) { weight = val; }

    protected:

    private:
        double weight;
};

#endif // PIECE_H
