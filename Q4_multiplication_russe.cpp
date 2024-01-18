#include <istream>

const int NUMBER_OF_COLUMN = 2;

int computeNumberOfRow(int firstNum);
void createTable(int table[][NUMBER_OF_COLUMN], int firstNum, int secondNum, int nRow);
void showTable(int table[][NUMBER_OF_COLUMN], int nRow);
void removeValueNearEvenValue(int table[][NUMBER_OF_COLUMN], int nRow);
int  addingValueNearOddValue(int table[][NUMBER_OF_COLUMN], int nRow);
void applyRussianMultiplication(int firstNum, int secondNum);


int computeNumberOfRow(int firstNum){
    int nRow = 1;
    do{
        firstNum /= 2;
        nRow++;
    }while(firstNum > 1);
    return nRow;
}

void createTable(int table[][NUMBER_OF_COLUMN], int firstNum, int secondNum, int nRow){
    for(int i = 1; i < nRow; i++){
        for(int j = 0; j < NUMBER_OF_COLUMN; j++){
            if(j == 0){
                firstNum /= 2;
                table[i][j] = firstNum;
            }
            else if(j==1){
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
        int replacement = table[i][0];
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
    cout << "The sum of the second colum = " << sumOfSecondColumn << '\n';
    cout << firstNum << " x " << secondNum << " = " << firstNum * secondNum << '\n';
    cout << "_______________________________" << '\n';

}