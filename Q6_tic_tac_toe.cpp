#include <fstream>


void makeTable(char table[], const string& fileName);
void determineWinner(const string& fileName);

void makeTable(char table[],const string& fileName){
    int size = 0;
    string line;
    ifstream fileInput(fileName);
    while(getline(fileInput, line)){
        for( char elem : line){
            if((elem == 'o') || (elem == 'x')){
                table[size] = char(elem);
                size++;

            }
        }
    }
}
void determineWinner(const string& fileName){
    char table[9];
    makeTable(table, fileName);

    for(char elem: table){
        cout << elem << " ";
    }
}

