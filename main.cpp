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
    executeRussianMultiplicationTests();
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



    q2(PRECISION);
    q4(FIRST_MULTIPLIER,SECOND_MULTIPLIER);
    q6();





    return 0;

}