#include<iostream>
#include<vector>
using namespace std;

class AI {
    vector<int> board;
    public:
    AI(vector<int> board) {
        this->board = board;
    }

    int getMove() {
        // AI logic
        int bestMove = -1;
        int bestScore = -1000;
        for(int i = 0; i < board.size(); i++) {
            if(board[i] == 0) {
                board[i] = 1;
                int score = minimax(board, 0, false);
                board[i] = 0;

                if(score > bestScore) {
                    bestScore = score;
                    bestMove = i;
                }
            }
        }
        return bestMove;
    }

    int minimax(vector<int> board, int depth, bool isMaximizing) {
        int score = evaluate(board);

        if(score == 10) {
            return score - depth;
        }

        if(score == -10) {
            return score + depth;
        }

        if(isMovesLeft(board) == false) {
            return 0;
        }

        if(isMaximizing) {
            int bestScore = -1000;
            for(int i = 0; i < board.size(); i++) {
                if(board[i] == 0) {
                    board[i] = 1;
                    bestScore = max(bestScore, minimax(board, depth + 1, !isMaximizing));
                    board[i] = 0;
                }
            }
            return bestScore;
        }
        else {
            int bestScore = 1000;
            for(int i = 0; i < board.size(); i++) {
                if(board[i] == 0) {
                    board[i] = -1;
                    bestScore = min(bestScore, minimax(board, depth + 1, !isMaximizing));
                    board[i] = 0;
                }
            }
            return bestScore;
        }
    }

    int evaluate(vector<int> board) {
        // rows
        for(int i = 0; i < 3; i++) {
            if(board[i * 3] + board[i * 3 + 1] + board[i * 3 + 2] == 3) {
                return 10;
            }

            if(board[i * 3] + board[i * 3 + 1] + board[i * 3 + 2] == -3) {
                return -10;
            }
        }

        // columns
        for(int i = 0; i < 3; i++) {
            if(board[i] + board[i + 3] + board[i + 6] == 3) {
                return 10;
            }

            if(board[i] + board[i + 3] + board[i + 6] == -3) {
                return -10;
            }
        }

        // diagonals
        if(board[0] + board[4] + board[8] == 3 || board[2] + board[4] + board[6] == 3) {
            return 10;
        }

        if(board[0] + board[4] + board[8] == -3 || board[2] + board[4] + board[6] == -3) {
            return -10;
        }

        return 0;
    }

    bool isMovesLeft(vector<int> board) {
        for(int i = 0; i < board.size(); i++) {
            if(board[i] == 0) {
                return true;
            }
        }
        return false;    
    }
};

int main() {
    vector<int> board = {0, -1, 0, -1, 0, 0, 1, 0, 1};
    AI ai(board);
    int move = ai.getMove();
    cout<<"Best Move is " << move <<endl;
    return 0;
}