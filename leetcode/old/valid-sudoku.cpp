/*
Valid Sudoku:

Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules. http://sudoku.com.au/TheRules.aspx

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> map(9, 0);
        for(int i=0; i<9; ++i){
            for(int j=0; j<9; ++j){
                if(board[i][j] != '.')
                    map[board[i][j] - '1']++;
            }
            if(initAndCheckValid(map) == false)
                return false;
        }
        for(int i=0; i<9; ++i){
            for(int j=0; j<9; ++j){
                if(board[j][i] != '.')
                    map[board[j][i] - '1']++;
            }
            if(initAndCheckValid(map) == false)
                return false;
        }
        for(int i=0; i<9; i+=3){
            for(int j=0; j<9; j+=3){
                for(int k=0; k<3; ++k){
                    for(int l=0; l<3; ++l){
                        if(board[i+k][j+l] != '.')
                            map[board[i+k][j+l] - '1']++;
                    }
                }
                if(initAndCheckValid(map) == false)
                    return false;
            }
        }
        return true;
    }
    
    bool initAndCheckValid(vector<int> &map){
        for(int i=0; i<9; ++i){
            if(map[i] > 1)
                return false;
            map[i] = 0;
        }
        return true;
    }
};
