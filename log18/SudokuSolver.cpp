#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
bool isValid(vector<vector<char>> &board, int row, int col, char c) {
    for (int i=0;i<9;i++){
        if(board[i][col]==c)
            return false;
    }
    for(int j=0;j<9;j++){
        if(board[row][j]==c)
            return false;
    }
    int boxRowStart=3*(row/3);
    int boxColStart=3*(col/3);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[boxRowStart+i][boxColStart+j]==c){
                return false;
            }
        }
    }
    return true;
}
bool solveSudoku(vector<vector<char>> &board) {
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]=='.'){
                for(char c='1';c<='9';c++){
                    if(isValid(board,i,j,c)){
                        board[i][j]=c;
                        if(solveSudoku(board)){
                            return true;
                        }
                        board[i][j]='.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}
};
int main() {
    vector<vector<char>> board {
        {'9', '5', '7', '.', '1', '3', '.', '8', '4'},
        {'4', '8', '3', '.', '5', '7', '1', '.', '6'},
        {'.', '1', '2', '.', '4', '9', '5', '3', '7'},
        {'1', '7', '.', '3', '.', '4', '9', '.', '2'},
        {'5', '.', '4', '9', '7', '.', '3', '6', '.'},
        {'3', '.', '9', '5', '.', '8', '7', '.', '1'},
        {'8', '4', '5', '7', '9', '.', '6', '1', '3'},
        {'.', '9', '1', '.', '3', '6', '.', '7', '5'},
        {'7', '.', '6', '1', '8', '5', '4', '.', '9'}
    };
    Solution sol;
    sol.solveSudoku(board);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++)
            cout<<board[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}
