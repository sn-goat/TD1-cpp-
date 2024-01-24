#include <iostream>
using namespace std;

struct RussianMultiplicationTest{
    int firstNumber;
    int secondNumber;
};

const int NUMBER_OF_COLUMNS = 2;

int computeNumberOfRows(int firstNum);
void createRussianMultiplicationTable(int table[][NUMBER_OF_COLUMNS], int firstNum, int secondNum, int nRow);
void showTable(int table[][NUMBER_OF_COLUMNS], int nRow);
void removeValueNearEvenValue(int table[][NUMBER_OF_COLUMNS], int nRow);
int  sumOfSecondRow(int table[][NUMBER_OF_COLUMNS], int nRow);
void changeSign(int firstNum, int secondNum, int& number);
void applyRussianMultiplication(int firstNum, int secondNum);
bool verifyRussianMultiplication(int firstNum, int secondNum);
void createRussianMultiplicationTableOfTests(RussianMultiplicationTest table[]);
void executeRussianMultiplicationTests();
