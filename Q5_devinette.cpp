#include "Q5_devinette.h"

void riddle() {
    const int MAX = 1000;
    int guess;
    srand(time(NULL));
    int number = (rand() % MAX) + 1;
    int numberOfTries = 0;
    while (true) {
        cout << "Entrez un nombre entier : ";
        cin >> guess;
        if (guess != number) {
            if (guess > number) {
                cout << "Trop grand." << endl;
                numberOfTries++;
            }
            if (guess < number) {
                cout << "Trop bas." << endl;
                numberOfTries++;
            }
        }
        if (guess == number) {
            cout << "Bravo! Vous avez reussi en " << numberOfTries << " tentatives! " << endl;
            break;
        }

    }

}