#include "Q3_insertion_dans_un_tableau.h"

void insertionInATable() {
    const int arraySize = 5;
    array<int, arraySize> Array = { 1, 3, 4, 7, 9 };
    array<int, arraySize + 1> arrayFinal{};

    int value;
    cout << "Entrez un entier : ";
    cin >> value;

    int index = 0;
    bool inserted = false;

    for (int iterator = 0; iterator < arraySize + 1; iterator++) {
        if (!inserted && (iterator == arraySize || Array[index] > value)) {
            arrayFinal[iterator] = value;
            inserted = true;
        }
        else {
            arrayFinal[iterator] = Array[index];
            index++;
        }
    }

    cout << "Tableau final après insertion : ";
    for (auto item : arrayFinal) {
        cout << item << " ";
    }
}