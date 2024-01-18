#include "Q2_suite_reel.cpp"
#include "Q4_multiplication_russe.cpp"


void q2(int precision){
    showLimitOfSequence(precision);


}


int main()
{
    const int PRECISION = 5;
    const int FIRST_MULTIPLIER = 37;
    const int SECOND_MULTIPLIER = 129;


    applyRussianMultiplication(FIRST_MULTIPLIER,SECOND_MULTIPLIER);
    q2(PRECISION);




    return 0;

}