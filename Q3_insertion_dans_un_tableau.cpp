#include "Q3_insertion_dans_un_tableau.h"

void insertionInATable() {
    const int ARRAY_SIZE = 5;
    array<int, ARRAY_SIZE> arrayInitial = {1, 3, 4, 7, 9 };
    array<int, ARRAY_SIZE + 1> arrayFinal{};

    int value;
    cout << "Entrez un entier : ";
    cin >> value;

    int index = 0;
    bool inserted = false;

    for (int iterator = 0; iterator < ARRAY_SIZE + 1; iterator++) {
        if (!inserted && (iterator == ARRAY_SIZE || arrayInitial[index] > value)) {
            arrayFinal[iterator] = value;
            inserted = true;
        }
        else {
            arrayFinal[iterator] = arrayInitial[index];
            index++;
        }
    }

    cout << "Tableau final après insertion : ";
    for (auto item : arrayFinal) {
        cout << item << " ";
    }
    cout << '\n';

}