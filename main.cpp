#include "Q2_suite_reel.cpp"
#include "Q4_multiplication_russe.cpp"
#include "Q6_tic_tac_toe.cpp"
#include <filesystem>
#include <utility>
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
void q6(string file){
    cout << "****************************Q6****************************" << '\n';
    outcomeOfTicTacToeGame(std::move(file));
    cout << "**********************************************************" << '\n';
}

int main()
{
    const int PRECISION = 5;
    const int FIRST_MULTIPLIER = 37;
    const int SECOND_MULTIPLIER = 129;
    fs::path currentPath = fs::current_path();
    const string GRID_FILE = string(currentPath) + "/INF1015-TD1-H24-Fichiers/";



    q2(PRECISION);
    q4(FIRST_MULTIPLIER,SECOND_MULTIPLIER);
    q6(GRID_FILE);





    return 0;

}