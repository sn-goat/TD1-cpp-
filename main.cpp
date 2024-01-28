#include "Q1._longeur_des_mots.h"
#include "Q2_suite_reel.h"
#include "Q3_insertion_dans_un_tableau.h"
#include "Q4_multiplication_russe.h"
#include "Q5_devinette.h"
#include "Q6_tic_tac_toe.h"
#include <filesystem>

namespace fs = filesystem;

void q1(){
    cout << "****************************Q1****************************" << '\n';
    lengthOfWords();
    cout << "**********************************************************" << '\n';
}
void q2(int precision){
    cout << "****************************Q2****************************" << '\n';
    showLimitOfSequence(precision);
    cout << "**********************************************************" << '\n';


}
void q3(){
    cout << "****************************Q3****************************" << '\n';
    insertionInATable();
    cout << "**********************************************************" << '\n';
}
void q4(int firstNumber, int secondNumber){
    cout << "****************************Q4****************************" << '\n';
    applyRussianMultiplication(firstNumber,secondNumber);
    executeRussianMultiplicationTests();
    cout << "**********************************************************" << '\n';

}
void q5(){
    cout << "****************************Q5****************************" << '\n';
    riddle();
    cout << "**********************************************************" << '\n';
}
void q6(){
    fs::path currentPath = fs::current_path();
    string grid_file = string(currentPath) + "/INF1015-TD1-H24-Fichiers/";

    cout << "****************************Q6****************************" << '\n';
    outcomeOfTicTacToeGame(grid_file);
    cout << "**********************************************************" << '\n';
}

int main()
{
    const int PRECISION = 5;
    const int FIRST_MULTIPLIER = 37;
    const int SECOND_MULTIPLIER = 129;

    q6();
    q1();
    q2(PRECISION);
    q3();
    q4(FIRST_MULTIPLIER,SECOND_MULTIPLIER);
    q5();





    return 0;

}