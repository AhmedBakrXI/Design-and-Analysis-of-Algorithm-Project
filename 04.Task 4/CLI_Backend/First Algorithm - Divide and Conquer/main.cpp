#include <iostream>
#include <string>
using namespace std;

int number_of_moves = 0;

 void hanoi4(int n, string peg_start, string peg_interm1, string peg_interm2, string peg_end)
{
	if (n == 0)
		return;
	if (n == 1)
	{
		number_of_moves++;
		cout << peg_start << " to " << peg_end<<endl;
		return;
	}
	hanoi4(n - 2, peg_start, peg_end, peg_interm2, peg_interm1);
	cout << peg_start << " to " << peg_interm2<<endl;
	cout << peg_start << " to " << peg_end<<endl;
	cout << peg_interm2 << " to " << peg_end<<endl;
	number_of_moves = number_of_moves + 3;
	hanoi4(n - 2, peg_interm1, peg_start, peg_interm2, peg_end);

}

int main()
{
	cout << "Enter number of disks: ";
	int number_of_disks; cin >> number_of_disks;
	cout << "The moves needed to transfer " << number_of_disks << " disks from one peg to another using 2 intermediary ones are:" << endl;
	string peg_start = "peg 1",peg_interm1 = "peg 2", peg_interm2 = "peg 3", peg_end = "target peg";
	hanoi4(number_of_disks , peg_start, peg_interm1, peg_interm2, peg_end);
	cout <<endl<< "Number of moves are: " << number_of_moves<<endl;
}
