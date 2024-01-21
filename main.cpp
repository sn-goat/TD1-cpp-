#include "Q2_suite_reel.cpp"
#include "Q4_multiplication_russe.cpp"


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


    q2(PRECISION);
    q4(FIRST_MULTIPLIER,SECOND_MULTIPLIER);




    return 0;

}