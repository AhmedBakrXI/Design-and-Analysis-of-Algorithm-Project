#include <iostream>
#include "box.h"
#include "defectedbox.h"
#include "normalbox.h"

using namespace std;

int main()
{
    cout<< "________________________________________________________________________________________________________________________\n";
    cout << "\t\t\t\t\t 50 Pieces in 50 Box Task  " << endl;
    cout<< "________________________________________________________________________________________________________________________\n";

    double weight ;

    cout << " Enter the weight of the metal pieces : ";
    cin>> weight;


    int defectedBox_No ;


    cout << " Enter the number of the defected box : ";
    cin>> defectedBox_No;

   Box* Boxes[50]; // Array of pointers to Box objects

    for (int i = 0; i < 50; i++)
    {
        if (i + 1 == defectedBox_No)
            Boxes[i] = new DefectedBox(weight);
        else
        {

            Boxes[i] = new NormalBox(weight);}
    }



    // Pick a piece from the first box
    cout << " Weight of the first piece in the first box: " << Boxes[0]->pickPiece() << endl;


    cout <<" Grabbing a bigger box an filling it with metal pieces"<<endl;
    cout <<" Taking 1 piece from the first box , 2 pieces from the second box  and so on ...." <<endl;


    double totalMeasuredWeight ;

    // Output total weight of each box
    for (int i = 0; i < 50; i++)
    {
        for(int j = 0 ; j<=i ; j++)
        totalMeasuredWeight += Boxes[i]->pickPiece();
    }

    double totalExpectedWeight = weight * (1 + 50 ) * 50  / 2 ;

    cout<<" The total expected weight if no boxes are defected is: " << totalExpectedWeight << "Kg"<<endl ;

    cout<<" But the measured weight is: "<<totalMeasuredWeight << "Kg"<<endl ;

    double diffrence_in_weight = totalExpectedWeight-totalMeasuredWeight ;

    cout<<" So there is a "<<diffrence_in_weight<<"Kgs difference in weight" <<endl;

    cout<<" And The defected box is the box number : "<< diffrence_in_weight;



    // Clean up memory
    for (int i = 0; i < 50; i++)
    {
        delete Boxes[i];
    }






    return 0;
}
