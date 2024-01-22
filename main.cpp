#include "Q2_suite_reel.cpp"
#include "Q4_multiplication_russe.cpp"
#include "Q6_tic_tac_toe.cpp"
#include <filesystem>
namespace fs = filesystem;



void q2(int precision){
    cout << "****************************Q2****************************" << '\n';
    showLimitOfSequence(precision);
    cout << "**********************************************************" << '\n';


}
void q4(int firstNumber, int secondNumber){
    cout << "****************************Q4****************************" << '\n';
    applyRussianMultiplication(firstNumber,secondNumber);
    executeRussianMultiplicationTest();
    cout << "**********************************************************" << '\n';

}

int main()
{
    const int PRECISION = 5;
    const int FIRST_MULTIPLIER = 37;
    const int SECOND_MULTIPLIER = 129;

    filesystem::path currentPath = filesystem::current_path();
    const string GRID_FILE_ONE = string(currentPath) + "/INF1015-TD1-H24-Fichiers/grille1.txt";

    determineWinner(GRID_FILE_ONE);




//    q2(PRECISION);
//    q4(FIRST_MULTIPLIER,SECOND_MULTIPLIER);





    return 0;

}