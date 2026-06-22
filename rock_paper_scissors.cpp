#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int user, computer;

    srand(time(0));

    cout << "Rock Paper Scissors Game\n";
    cout << "1. Rock\n2. Paper\n3. Scissors\n";
    cout << "Enter your choice (1-3): ";
    cin >> user;

    computer = rand() % 3 + 1;

    cout << "Computer chose: ";

    if (computer == 1)
        cout << "Rock\n";
    else if (computer == 2)
        cout << "Paper\n";
    else
        cout << "Scissors\n";

    if (user == computer)
        cout << "It's a Draw!\n";
    else if ((user == 1 && computer == 3) ||
             (user == 2 && computer == 1) ||
             (user == 3 && computer == 2))
        cout << "You Win!\n";
    else
        cout << "Computer Wins!\n";

    return 0;
}
