#include "Q6_tic_tac_toe.h"

void makeTableOfTicTacToeGame(char table[],const string& fileName){
    int nSize = 0;
    string line;
    ifstream fileInput(fileName);
    while(getline(fileInput, line)){
        for(char elem : line){
            bool isOorX = (elem == 'o') || (elem == 'x');
            if(isOorX){
                table[nSize] = elem;
                nSize++;

            }
        }
    }
}
void findWinningPLayer(const char table[], char player1){

    if((table[0] == table[1]) && (table[1] == table[2])){
        table[0] == player1 ? cout << "Player 1 won.\n" : cout << "Player 2 won.\n";
    }
    else if((table[3] == table[4]) && (table[4] == table[5])){
        table[3] == player1 ?  cout << "Player 1 won.\n" : cout << "Player 2 won.\n";
    }
    else if((table[6] == table[7]) && (table[7] == table[8])){
        table[6] == player1 ?  cout << "Player 1 won.\n" : cout << "Player 2 won.\n";
    }
    else if((table[0] == table[3]) && (table[3] == table[6])){
        table[0] == player1 ?  cout << "Player 1 won.\n" : cout << "Player 2 won.\n";
    }
    else if((table[1] == table[4]) && (table[4] == table[7])){
        table[1] == player1 ?  cout << "Player 1 won.\n" : cout << "Player 2 won.\n";
    }
    else if((table[2] == table[5]) && (table[5] == table[8])){
        table[2] == player1 ?  cout << "Player 1 won.\n" : cout << "Player 2 won.\n";
    }
    else if((table[0] == table[4]) && (table[4] == table[8])){
        table[0] == player1 ?  cout << "Player 1 won.\n" : cout << "Player 2 won.\n";
    }
    else if((table[2] == table[4]) && (table[4] == table[6])){
        table[2] == player1 ?  cout << "Player 1 won.\n" : cout << "Player 2 won.\n";
    }
    else{
         cout << "Tie" << '\n';
    }

}

void outcomeOfTicTacToeGame(string fileName){
    const char PLAYER_ONE = 'x';

    string tempFile;

    cout << "Enter the name of the file: ";
    getline(cin, tempFile);

    fileName+= tempFile;

    char tableOfTicTacToeGame[9];

    makeTableOfTicTacToeGame(tableOfTicTacToeGame, fileName);
    findWinningPLayer(tableOfTicTacToeGame, PLAYER_ONE);

}


