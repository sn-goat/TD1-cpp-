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


int computeNumberOfRows(int firstNum){
    int positiveNumber = abs(firstNum);
    int nRows = 1;

    do{
        positiveNumber /= 2;
        nRows++;
    }while(positiveNumber > 1);
    return nRows;
}

void createRussianMultiplicationTable(int table[][NUMBER_OF_COLUMNS], int firstNum, int secondNum, int nRow){
    for(int i = 1; i < nRow; i++){
        for(int j = 0; j < NUMBER_OF_COLUMNS; j++){
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

void showTable(int table[][NUMBER_OF_COLUMNS], int nRow){
    cout << "The table: " << '\n';
    for(int i=0 ; i< nRow ; i++) {
        for (int j = 0; j < NUMBER_OF_COLUMNS; j++) {
            cout << table[i][j] << '\t';
            bool isAtEndOfTable = j == 1;
            if (isAtEndOfTable) {
                cout << '\n';
            }

        }
    }
    cout << "__________" << '\n';
}
void removeValueNearEvenValue(int table[][NUMBER_OF_COLUMNS], int nRow){
    for(int i=0 ; i< nRow ; i++) {
        int replacement = abs(table[i][0]);
        bool isEven = replacement % 2;
        if(!isEven){
            table[i][1] = 0;
        }
    }

}
int  sumOfSecondRow(int table[][NUMBER_OF_COLUMNS], int nRow) {
    int totalSum = 0;
    for (int i = 0; i < nRow; i++) {
        totalSum += table[i][1];
    }
    return totalSum;
}
void changeSign(int firstNum, int secondNum, int& number){
    bool isPositiveAnswer = ((firstNum >= 0) && (secondNum >= 0)) || ((firstNum <= 0) && (secondNum <= 0));
    bool isNegativeNumber = number < 0;
    bool isChangingSign = (isPositiveAnswer && isNegativeNumber) || (!isPositiveAnswer && !isNegativeNumber);

    if(isChangingSign){
        number *= -1;
    }
}
void applyRussianMultiplication(int firstNum, int secondNum){
    int numberOfRows = computeNumberOfRows(firstNum);
    cout << "_____RUSSIAN MULTIPLICATION_____" << '\n';
    int table[numberOfRows][NUMBER_OF_COLUMNS];
    table[0][0] = firstNum;
    table[0][1] = secondNum;

    createRussianMultiplicationTable(table, firstNum, secondNum, numberOfRows);
    showTable(table, numberOfRows);
    removeValueNearEvenValue(table, numberOfRows);
    showTable(table, numberOfRows);

    int sumOfSecondColumn = sumOfSecondRow(table, numberOfRows);
    changeSign(firstNum, secondNum, sumOfSecondColumn);



    cout << "The sum of the second colum = " << sumOfSecondColumn << '\n';
    cout << firstNum << " x " << secondNum << " = " << firstNum * secondNum << '\n';
    cout << "_______________________________" << '\n';

}

bool verifyRussianMultiplication(int firstNum, int secondNum){
    int numberOfRows = computeNumberOfRows(firstNum);
    int russianMultiplicationNumbers[numberOfRows][NUMBER_OF_COLUMNS];

    russianMultiplicationNumbers[0][0] = firstNum;
    russianMultiplicationNumbers[0][1] = secondNum;

    createRussianMultiplicationTable(russianMultiplicationNumbers, firstNum, secondNum, numberOfRows);
    removeValueNearEvenValue(russianMultiplicationNumbers, numberOfRows);

    int sumOfSecondColumn = sumOfSecondRow(russianMultiplicationNumbers, numberOfRows);
    changeSign(firstNum, secondNum, sumOfSecondColumn);
    bool asserEqual = sumOfSecondColumn == (firstNum * secondNum);

    return asserEqual;
}

void createRussianMultiplicationTableOfTests(RussianMultiplicationTest table[]){
    table[0] = {0, 0};
    table[1] = {37, 129};
    table[2] = {103, -207};
    table[3] = {-47, 300};
    table[4] = {-86, -444};
}

void executeRussianMultiplicationTests(){
    const int NUMBER_OF_TESTS = 5;

    RussianMultiplicationTest tableOfTest[NUMBER_OF_TESTS];
    createRussianMultiplicationTableOfTests(tableOfTest);

    int nSuccessfullTests = 0;
    for(const auto& test : tableOfTest){
        bool isSuccessfullTest = verifyRussianMultiplication(test.firstNumber, test.secondNumber);
        if (isSuccessfullTest){
            nSuccessfullTests++;
        }
    }
    cout << "Ran " << NUMBER_OF_TESTS << " test" << '\n';
    cout << nSuccessfullTests << "/" << NUMBER_OF_TESTS << " passed." << '\n';
}