#include <iomanip>
#include <iostream>
#include <vector>

struct RussianMultiplicationTest{
    int firstNumber;
    int secondNumber;
};

const int NUMBER_OF_COLUMN = 2;

int computeNumberOfRow(int firstNum);
void createTable(int table[][NUMBER_OF_COLUMN], int firstNum, int secondNum, int nRow);
void showTable(int table[][NUMBER_OF_COLUMN], int nRow);
void removeValueNearEvenValue(int table[][NUMBER_OF_COLUMN], int nRow);
int  addingValueNearOddValue(int table[][NUMBER_OF_COLUMN], int nRow);
void changeSign(int firstNum, int secondNum, int* number);
void applyRussianMultiplication(int firstNum, int secondNum);
bool verifyRussianMultiplication(int firstNum, int secondNum);
void executeRussianMultiplicationTest();


int computeNumberOfRow(int firstNum){
    int positiveNumber = abs(firstNum);
    int nRow = 1;
    do{
        positiveNumber /= 2;
        nRow++;
    }while(positiveNumber > 1);
    return nRow;
}

void createTable(int table[][NUMBER_OF_COLUMN], int firstNum, int secondNum, int nRow){
    for(int i = 1; i < nRow; i++){
        for(int j = 0; j < NUMBER_OF_COLUMN; j++){
            bool isInFirstColumn = j == 0;
            bool isInSecondColumn = j == 1;
            if(isInFirstColumn){
                firstNum /= 2;
                table[i][j] = firstNum;
            }
            else if(isInSecondColumn){
                secondNum *=2;
                table[i][j] = secondNum;
            }
        }
    }
}

void showTable(int table[][NUMBER_OF_COLUMN], int nRow){
    cout << "The table: " << '\n';
    for(int i=0 ; i< nRow ; i++) {
        for (int j = 0; j < NUMBER_OF_COLUMN; j++) {
            cout << table[i][j] << '\t';
            bool isAtEndOfTable = j == 1;
            if (isAtEndOfTable) {
                cout << '\n';
            }

        }
    }
    cout << "__________" << '\n';
}
void removeValueNearEvenValue(int table[][NUMBER_OF_COLUMN], int nRow){
    for(int i=0 ; i< nRow ; i++) {
        int replacement = abs(table[i][0]);
        bool isEven = replacement % 2;
        if(!isEven){
            table[i][1] = 0;
        }
    }

}
int  addingValueNearOddValue(int table[][NUMBER_OF_COLUMN], int nRow) {
    int totalAddition = 0;
    for (int i = 0; i < nRow; i++) {
        totalAddition += table[i][1];
    }
    return totalAddition;
}
void changeSign(int firstNum, int secondNum, int* number){
    const bool isPositiveAnswer = ((firstNum >= 0) && (secondNum >= 0)) || ((firstNum <= 0) && (secondNum <= 0));
    const bool isNegativeNumber = *number < 0;
    const bool isChangingSign = (isPositiveAnswer && isNegativeNumber) || (!isPositiveAnswer && !isNegativeNumber);
    if(isChangingSign){
        *number *= -1;
    }
}
void applyRussianMultiplication(int firstNum, int secondNum){
    const int NUMBER_OF_ROW = computeNumberOfRow(firstNum);
    cout << "_____RUSSIAN MULTIPLICATION_____" << '\n';
    int table[NUMBER_OF_ROW][NUMBER_OF_COLUMN];
    table[0][0] = firstNum;
    table[0][1] = secondNum;

    createTable(table, firstNum, secondNum, NUMBER_OF_ROW);
    showTable(table, NUMBER_OF_ROW);
    removeValueNearEvenValue(table, NUMBER_OF_ROW);
    showTable(table, NUMBER_OF_ROW);

    int sumOfSecondColumn = addingValueNearOddValue(table, NUMBER_OF_ROW);
    changeSign(firstNum, secondNum, &sumOfSecondColumn);



    cout << "The sum of the second colum = " << sumOfSecondColumn << '\n';
    cout << firstNum << " x " << secondNum << " = " << firstNum * secondNum << '\n';
    cout << "_______________________________" << '\n';

}

bool verifyRussianMultiplication(int firstNum, int secondNum){
    const int NUMBER_OF_ROW = computeNumberOfRow(firstNum);
    int table[NUMBER_OF_ROW][NUMBER_OF_COLUMN];
    table[0][0] = firstNum;
    table[0][1] = secondNum;

    createTable(table, firstNum, secondNum, NUMBER_OF_ROW);
    removeValueNearEvenValue(table, NUMBER_OF_ROW);

    int sumOfSecondColumn = addingValueNearOddValue(table, NUMBER_OF_ROW);
    changeSign(firstNum, secondNum, &sumOfSecondColumn);
    bool asserEqual = sumOfSecondColumn == (firstNum * secondNum);

    return asserEqual;
}

void executeRussianMultiplicationTest(){
    vector<RussianMultiplicationTest> structListOfTest;

    RussianMultiplicationTest test1 = {0, 0};
    RussianMultiplicationTest test2 = {37, 129};
    RussianMultiplicationTest test3 = {103, -207};
    RussianMultiplicationTest test4 = {-47, 300};
    RussianMultiplicationTest test5 = {-86, -444};

    structListOfTest.push_back(test1);structListOfTest.push_back(test2);
    structListOfTest.push_back(test3);structListOfTest.push_back(test4);
    structListOfTest.push_back(test5);

    int successfullTest = 0;
    for(const auto& test : structListOfTest){
        bool isTestSuccessfull = verifyRussianMultiplication(test.firstNumber, test.secondNumber);
        if (isTestSuccessfull){
            successfullTest++;
        }
    }
    cout << "Ran 5 test" << '\n';
    cout << successfullTest << "/5" << " passed." << '\n';
}