#include <fstream>


void makeTable(char table[], const string& fileName);
void findWinningPLayer(char table[], const string& fileName, char player1);
void outcomeOfTicTacToeGame(string fileName);

void makeTable(char table[],const string& fileName){
    int size = 0;
    string line;
    ifstream fileInput(fileName);
    while(getline(fileInput, line)){
        for( char elem : line){
            if(((elem == 'o') || (elem == 'x'))){
                table[size] = elem;
                size++;

            }
        }
    }
}
void findWinningPLayer(char table[], const string& fileName, char player1){
    makeTable(table, fileName);

    if((table[0] == table[1]) && (table[1] == table[2])){
        table[0] == player1 ? cout << "Joueur 1 gagne\n" : cout << "Joueur 2 gagne\n";
    }
    else if((table[3] == table[4]) && (table[4] == table[5])){
        table[3] == player1 ?  cout << "Joueur 1 gagne\n" : cout << "Joueur 2 gagne\n";
    }
    else if((table[6] == table[7]) && (table[7] == table[8])){
        table[6] == player1 ?  cout << "Joueur 1 gagne\n" : cout << "Joueur 2 gagne\n";
    }
    else if((table[0] == table[3]) && (table[3] == table[6])){
        table[0] == player1 ?  cout << "Joueur 1 gagne\n" : cout << "Joueur 2 gagne\n";
    }
    else if((table[1] == table[4]) && (table[4] == table[7])){
        table[1] == player1 ?  cout << "Joueur 1 gagne\n" : cout << "Joueur 2 gagne\n";
    }
    else if((table[2] == table[5]) && (table[5] == table[8])){
        table[2] == player1 ?  cout << "Joueur 1 gagne\n" : cout << "Joueur 2 gagne\n";
    }
    else if((table[0] == table[4]) && (table[4] == table[8])){
        table[0] == player1 ?  cout << "Joueur 1 gagne\n" : cout << "Joueur 2 gagne\n";
    }
    else if((table[2] == table[4]) && (table[4] == table[6])){
        table[2] == player1 ?  cout << "Joueur 1 gagne\n" : cout << "Joueur 2 gagne\n";
    }
    else{
         cout << "Egalite" << '\n';
    }

}

void outcomeOfTicTacToeGame(string fileName){
    const char PLAYER_ONE = 'x';

    string tempFile;

    cout << "Enter the name of the file: ";
    getline(cin, tempFile);

    fileName+= tempFile;

    char tableOfTicTacToeGame[9];

    makeTable(tableOfTicTacToeGame, fileName);
    findWinningPLayer(tableOfTicTacToeGame,fileName, PLAYER_ONE);

}


