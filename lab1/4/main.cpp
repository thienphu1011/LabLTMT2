#include <iostream>
#include "Die.h"

using namespace std;

int main() {
    Die myDie(6);
    char choice;
    int totalPoints = 0;
    int itemPoints = 0;

    cout << "Welcome to the Fishing Game!\n";

    do {
        cout << "Do you want to fish? (Y/N): ";
        cin >> choice;

        if (choice == 'Y' || choice == 'y') {
            myDie.roll();
            int result = myDie.getValue();

            switch (result) {
                case 1:
                    cout << "You caught a huge fish!\n";
                    itemPoints = 60;
                    break;
                case 2:
                    cout << "You caught an old shoe.\n";
                    itemPoints = 1;
                    break;
                case 3:
                    cout << "You caught a little fish.\n";
                    itemPoints = 10;
                    break;
                case 4:
                    cout << "You caught a shark!\n";
                    itemPoints = 100;
                    break;
                case 5:
                    cout << "You caught seaweed.\n";
                    itemPoints = 2;
                    break;
                case 6:
                    cout << "You caught a treasure chest!\n";
                    itemPoints = 500;
                    break;
            }
            totalPoints += itemPoints;
        }

    } while (choice == 'Y' || choice == 'y');

    cout << "\nGame Over!\n";
    cout << "Total fishing points: " << totalPoints << endl;

    if (totalPoints < 50) {
        cout << "Better luck next time. Keep practicing!\n";
    } else if (totalPoints >= 50 && totalPoints < 200) {
        cout << "Good job! You had a decent fishing trip.\n";
    } else {
        cout << "Wow! You are a master angler!\n";
    }

    return 0;
}