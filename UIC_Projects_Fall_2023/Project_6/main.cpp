/** ---------------------------------------------
* This program provides a practical demonstration of key concepts in 
* C++ programming, focusing on classes, linked lists, nodes, and functions
* Sixth project Connect 4 with Backtracking.
* Class: CS 141, Fall 2023
* System: ZyBook Lab *
* @author Jacob Salazar
* @version November 13, 2023
* ---------------------------------------------- */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;
#include "linkedlist.h"


//function to display the initial instructions to the game
void instructions(){
    cout << "This is the Game Connect 4. "<< endl;
    cout << "Each player should place an X or an O in the space by entering the column you want to place the piece." << endl;
    cout << "The piece will fall until it reaches the bottom or the current pieces in the board." << endl;
    cout << "When X or O gets 4 in a row (either horizontally, vertically, or diagonally, then that person wins." << endl;
    cout << "The user can enter Q (or q) to end the game early." << endl;
}

//function to display the board when passed an array of size 42
void display_board(char board[42]){
    cout << "0 1 2 3 4 5 6" << endl;
    for (int i= 0; i < 42; i++){
        cout << board[i] << " ";
        if ((i + 1) % 7 == 0 ){
            cout << endl;
        }
    }
}
//This function uses a linkedlist object by reference and iterates through the list by grabbing the beginning indexes from the list
void print_moves(linkedlist& movelist){
    bool loop = false;
    int index = 0;
    int counter = 0;
    char user;
    char board_temp[42] = {'-', '-', '-', '-', '-', '-', '-', 
                      '-', '-', '-', '-', '-', '-', '-', 
                      '-', '-', '-', '-', '-', '-', '-',
                      '-', '-', '-', '-', '-', '-', '-', 
                      '-', '-', '-', '-', '-', '-', '-', 
                      '-', '-', '-', '-', '-', '-', '-' };
    //start while loop to iterate through linkedlist     
    while (loop == false){
        //grab first index value in the game
        index = movelist.get_first_index();
        //if the index returned from the linkedlist get index function then stop loop we are at the end of the list
        if (index == -1){
            loop = true;
        }
        //have a counter to keep track of which user is playing even is X odd is O
        if (counter % 2 == 0){
            user = 'X';
        }
        else{
            user = 'O';
        }
        //make move on the board as if it was the start of the game
        board_temp[index] = user;
        //print board
        display_board(board_temp);
        //delete the beginning node in the linkedlist
        movelist.delete_first_index();
        //increase counter
        counter++;
    }
}

//function that gets user input for the column they would like to select
int choose_move(char piece){
    string user;
    //take in the user input for column as string to be able to test if it is the letter q or Q
    string column;
    int col;
    cout << "It is " << piece << "'s " << "turn." << endl;
    cout << "Enter a column to place your piece. ";
    cin >> column;

    //check for if the user would like to quit or not
    if (column == "q" || column == "Q"){
        cout << "Ending Game" << endl;
        exit(1);
    }

    //check for if the user would like to undo a move
    if (column == "u" || column == "U"){
        return 100;
    }
    //check for if the user would like to print all previous moves
    if (column == "p" || column == "P"){
        return 200;
    }
    //if it is string 0-6 then turn it to int value
    else if (column == "0" || column == "1" || column == "2" || column == "3" || column == "4" || column == "5" || column == "6"){
        col = stoi(column);
        return col;
    }
    //anything else we are going to set as an out of bounds value 8
    else{
        col = 8;
        return col;
    }

}


//edit board variable to input the user move on the board
char make_move(int column, char board[42], char user, linkedlist& movelist){
    int index;
    //if choose move function returned 100 then undo move
    if (column == 100){
        //get the last index of linkedlist
        index = movelist.get_index();
        //delete the node at the end
        movelist.delete_last_from_list();
        //change the board index returned from get index and set it to initial value
        board[index] = '-';
        return 'U';
    }
    //if choose move function returned 200 then print moves
    else if(column == 200){
        print_moves(movelist);
    }
    else if (column < 0 || column >= 7){
        return 'E';
    }
    //iterate through rows starting at the bottom
    //need to check bottom to top and we need to grab the associated index based on the column input
    else{
        for (int i = 5; i >= 0; --i){
            index = i * 7 + column;
            if (board[index] == '-'){
                board[index] = user;
                //keep track of the indexes of moves
                movelist.append_to_list(index);
                return 'S';
            }
        }
    }
    return 'F';
}

//function to scan board and check if there was a winning move
bool check_win(char board[42], char user){
    //check for vertical cases
   for (int y = 0; y < 6; y++){
        for (int x = 0; x <= 6; x++){
            int position = 0;
            position = y * 7 + x;
            if(board[position] == user && board[position + 7] == user && board[position + 14] == user && board[position + 21] == user){
                return true;
            }
        }
    }
    //check for horizontal wins
    for (int y = 0; y < 6; y++){
        for (int x = 0; x < 4; x++){
            int position = 0;
            position = y * 7 + x;
            if(board[position] == user && board[position + 1] == user && board[position + 2] == user && board[position + 3] == user){
                return true;
            }
        }
    }

    //check for diagonal top left moving diagonal down right
    for (int y = 0; y < 3; y++){
        for (int x = 0; x < 4; x++){
            int position = 0;
            position = y * 7 + x;
            if(board[position] == user && board[position + 8] == user && board[position + 16] == user && board[position + 24] == user){
                return true;
            }
        }
    }

    //check for diagonal top right moving diagonal down left
    for (int y = 0; y < 3; y++){
        for (int x = 6; x > 2; --x){
            int position = 0;
            position = y * 7 + x;
            if(board[position] == user && board[position + 6] == user && board[position + 12] == user && board[position + 18] == user){
                return true;
            }
        }
    }

    //check for diagonal bottom left moving diagonal up right
    for (int y = 5; y > 2; --y){
        for (int x = 0; x < 4; x++){
            int position = 0;
            position = y * 7 + x;
            if(board[position] == user && board[position + 6] == user && board[position + 12] == user && board[position + 18] == user){
                return true;
            }
        }
    }

    //check for diagonal bottom right moving diagonal up left
    for (int y = 5; y > 2; --y){
        for (int x = 6; x > 2; --x){
            int position = 0;
            position = y * 7 + x;
            if(board[position] == user && board[position + 6] == user && board[position + 12] == user && board[position + 18] == user){
                return true;
            }
        }
    }


    //check if the board is full
    bool full = true;

    for (int y = 0; y < 6; y++){
        for (int x = 0; x <= 6; x++){
            int position = 0;
            position = y * 7 + x;
            if (board[position] == '-'){
                full = false;
                break;
            }
        }
    }

    //if full is false then return false
    if (full == false){
        return false;
    }

    //if full is continues to be true then state it is a draw!
    else if (full == true){
        cout << endl << "Board is Full, It's a Draw!!!" << endl;
        exit(1);
    }

    return false;
}


//driver function
int main(){
    int counter = 0;
    int column;
    char user;
    char handle;
    bool win = false;
    char board[42] = {'-', '-', '-', '-', '-', '-', '-', 
                      '-', '-', '-', '-', '-', '-', '-', 
                      '-', '-', '-', '-', '-', '-', '-',
                      '-', '-', '-', '-', '-', '-', '-', 
                      '-', '-', '-', '-', '-', '-', '-', 
                      '-', '-', '-', '-', '-', '-', '-' };

    //display the the instructions and empty board to start
    instructions();
    display_board(board);
    cout << "Let's get started!!!" << endl;
    linkedlist movelist;
    //while loop that continues to go until win is set to true or when there is a winner detected after scanning board
    while(win == false){

        //we would like to display the board after every move except for when the game just starts
        if (counter != 0){
            display_board(board);
        }

        //have a counter to keep track of which user is playing even is X odd is O
        if (counter % 2 == 0){
            user = 'X';
        }
        else{
            user = 'O';
        }

        //get user input for the move
        column = choose_move(user);

        //edit the board and get a response back
        handle = make_move(column, board, user, movelist);

        //if the response is E there was an invalid column
        if (handle == 'E'){
            cout << endl << "Please enter a valid column" << endl;
        }

        //if the response is S then move was success
        else if (handle == 'S'){
            win = check_win(board, user);
            counter++;
        }
        //handle if the user wants to undo a move
        else if (handle == 'U'){
            if (counter > 0){
                //if counter is greater than 0 then decrease counter
                counter--;
            }
            else{
                //if counter is anything else then set it to 0 and display the board
                counter = 0;
                display_board(board);
            }
        }
        //if the the response was anything else then it is error code column is full
        else {
            cout << "column chosen is already full" << endl;
        }
    }
    //display the board after win is detected and then state which user won
    display_board(board);
    cout << "Game is Over, Player " << user << " got 4 in a row!!!!";
    return 0;
}
