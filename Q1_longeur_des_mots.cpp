#include "Q1._longeur_des_mots.h"

void lengthOfWords() {
    string phrase;
    string mot;
    string plusLongMot;
    string plusPetitMot;

    cout << "Saisissez une phrase : ";
    getline(cin, phrase);
    cout << "Votre phrase est: " << phrase << endl;
    istringstream iss(phrase);

    double nombreMot = 0;
    double nombreLettre = 0;

    while (iss >> mot) {
        if (mot.length() > plusLongMot.length()) {
            plusLongMot = mot;
        }
        if (nombreMot == 0) {
            plusPetitMot = mot;
        }
        if (mot.length() < plusPetitMot.length()) {
            plusPetitMot = mot;
        }
        nombreMot++;
        nombreLettre += mot.size();


    }

    cout << "Le mot le plus court est : " << plusPetitMot << endl;
    cout << "Le mot le plus long est : " << plusLongMot << endl;
    cout << "La longueur moyenne est :" << nombreLettre / nombreMot << endl;

}