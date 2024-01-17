#include <istream>

const int FIRST_MULTIPLIER = 37;
const int SECOND_MULTIPLIER = 129;
const int NUMBER_OF_COLUMN = 2;

void russianMultiplication(int firstNum, int secondNum);
int nbOfRow(int firstNum);
void creatTable(int table[]);
void showTable(int table[]);
void removeValueNearEvenValue(int table[]);
void addingValueNearOddValue(int table[]);


int nbOfRow(int firstNum){
    int size = 1;
    do{
        firstNum /= 2;
        size++;
    }while(firstNum > 1);
    return size;
}
 const int NUMBER_OF_ROW = nbOfRow(FIRST_MULTIPLIER);

void russianMultiplication(int firstNum, int secondNum){
    int table[NUMBER_OF_ROW][NUMBER_OF_COLUMN];
    table[0][0] = firstNum;
    table[0][1] = secondNum;
//    Put this in a function:
    for(int i = 1; i < (NUMBER_OF_ROW); i++){
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
//  function that replace value near even numbers with NOT INCLUDED
//  function that add value near odd numbers
//  function that show that the two results are equals
//  Put this in a function:
    cout<<"Table is: " << '\n';
    for(int i=0 ; i< NUMBER_OF_ROW; i++) {
        for (int j = 0; j < NUMBER_OF_COLUMN; j++) {
            cout << table[i][j] << '\t';
            if (j == 1) {
                cout << '\n';
            }
        }
    }

}