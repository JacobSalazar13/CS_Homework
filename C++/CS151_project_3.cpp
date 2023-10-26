/******************************************************************************


*******************************************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

void getFile(char fileContent2[6][6]){
    ifstream inFS;
    string fileName;
    string row;

    cout << "Enter filename: ";
    cin >> fileName;

    inFS.open(fileName);
    if (!inFS.is_open()) {
      cout << "Could not open file numFile.txt." << endl;
    }
    getline(inFS, row);
    while (!inFS.fail()) {
        if (row.find("Q") != string::npos){
            cout << "try a file that doesnt use Q as a car name";
        }
        for (int b = 0; b < 6; b++){
            for (int c = 0; c < 6; c++){
                fileContent2[b][c] = row[c];
            }
        }
        getline(inFS, row);
    }
    inFS.close();
    }

void displayBoard(char file_content_2[6][6]){
    cout << "--------" << endl;
    for (int x = 0; x < 6; x++){
        cout << "|";
        for (int i = 0; i < 6; i++){
            cout << file_content_2[x][i];
        }
        cout << "|" << endl;
    }
    cout << "--------" << endl;
}

void makeMoves(){
    string move;
    cout << "Enter next move (or Q to quit): ";
    cin >> move;
    if (move == "Q"){
        exit(0);
    }
    // if (move.find("U") == "3" or move.find("u") == ){
    //     searchBoard("U");
    // }
    // if (move.find("D") != string::npos or move.find("d") != string::npos){
    //     searchBoard("D");
    // }   
    // if (move.find("L") != string::npos or move.find("l") != string::npos){
    //     searchBoard("L");
    // } 
    // if (move.find("R") != string::npos or move.find("r") != string::npos){
    //     searchBoard("");
    // }
    
    // for (double i = 0; i < file_content_3.size(); i++){
    //     if 
    // }
}



int main()
{
    const int numRows = 6;
    const int numCols = 6;
    char fileContent[numRows][numCols];
    getFile(fileContent, numRows, numCols);
    displayBoard(fileContent);
    // makeMoves(fileContent);

    return 0;
}