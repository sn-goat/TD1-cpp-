#include <iostream>
using namespace std;


void limitOfSequence(int precision);
double numInSequence(double index);
double errorLimitSequence(double limitNum, int Numsequence);

double numInSequence(int index){

    if(index == 0){
        return sqrt(2 + (index + 1));
    }
    return sqrt(2 + numInSequence(index - 1));
    
}
double errorLimitSequence(double numBefore, double numAfter){
    return numAfter - numBefore;
}
void limitOFSequence(int precision){
    int index = 0;
    while(true){
        cout << fixed << setprecision(precision);
        double numBefore = numInSequence(index);
        cout << numBefore  << " index = " << index << '\n';
        double numAfter = numInSequence(index + 1);
        cout << numAfter << " index = " << index + 1 << '\n';
        double error = errorLimitSequence(numBefore, numAfter);
        cout << "Error: " << numAfter << " - " << numBefore << " = " << error <<'\n';
        if(error  < pow(10,-precision)){
            break;
        }
        else{
            index++;
        }

    }
}
