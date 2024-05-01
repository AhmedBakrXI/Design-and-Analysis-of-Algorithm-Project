#include <iostream>
using namespace std;

int main(int argc, char *argv[] )
{
    int box_weight = stoi(argv[1]);

    int defected_box = stoi(argv[2]);

    int total_expected = 50 * 50 * box_weight  ;

    int total_defected = total_expected - defected_box;

    cout<< "The total expected weight of the boxes is "<< total_expected << endl;
    cout<< "The measured weight is "<<  total_defected << endl;
    cout<< " The is a difference is "<<defected_box<< "kgs" << "between them" <<endl ;
    cout<< "So, The defected Box is "<< defected_box << endl;


    return 0;
}
