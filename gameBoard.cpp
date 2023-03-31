#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

// Define the game board
const int board_size = 3;
char board[board_size][board_size] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

// Player moves first, so AI is 'O'
char ai = 'O';

// Function to draw the game board
void drawBoard() {
    cout<<" "<< board[0][0]<<" | "<< board[0][1]<<" | "<< board[0][2]<<endl;
    cout<<"-----------"<<endl;
    cout<<" "<< board[1][0]<<" | "<< board[1][1]<<" | "<< board[1][2]<<endl;
    cout<<"-----------"<<endl;
    cout<<" "<< board[2][0]<<" | "<< board[2][1]<<" | "<< board[2][2]<<endl;
}

// Function to make AI move
bool AIMove() {
    // Generate random number
    srand(time(NULL));
    int ai_row = rand() % board_size;
    int ai_col = rand() % board_size;

    // Check id spot is empty
    if(board[ai_row][ai_col] != 'O' && board[ai_row][ai_col] != 'X') {
        board[ai_row][ai_col] = ai;
        return true;
    }
    else {
        return false;
    }
}

int main() {
    drawBoard();
    bool ai_move = false;
    while(!ai_move) {
        ai_move = AIMove();
    }
    cout<<"\n"<<endl;
    drawBoard();
    return 0;
    
}