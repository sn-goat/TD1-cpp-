#include "Q2_suite_reel.h"

double computeNumberInSequence(int index){

    if(index == 0){
        return sqrt(2 + (index + 1));
    }
    return sqrt(2 + computeNumberInSequence(index - 1));
    
}
double computeError(double numberBefore, double numberAfter){
    return numberAfter - numberBefore;
}
void showLimitOfSequence(int precision){
    int index = 0;
    double almostZero = pow(10,-precision);
    while(true){
        cout << fixed << setprecision(precision);
        double numberBefore = computeNumberInSequence(index);
        cout << numberBefore << " index = " << index << '\n';
        double numberAfter = computeNumberInSequence(index + 1);
        cout << numberAfter << " index = " << index + 1 << '\n';
        double error = computeError(numberBefore, numberAfter);
        cout << "Error: " << numberAfter << " - " << numberBefore << " = " << error << '\n';
        bool isAtTheLimitOfSequence = error  < almostZero;
        if(isAtTheLimitOfSequence){
            cout << "The limit of the sequence is " << numberBefore << '\n';
            break;
        }
        else{
            index++;
        }

    }
}
