/*
https://leetcode.com/problems/word-search/
*/
class Solution {
public:  
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool dfs(vector<vector<char>>& board, int row, int col, string word, int index, vector<vector<bool>>& visited) {
        if(word.size()==index)
            return true;    

        visited[row][col] = true;
        
        for(pair<int, int> direction: directions) {
            int rowNext = row + direction.first;
            int colNext = col + direction.second;

            if(rowNext<0 || rowNext>=board.size())
                continue;
            if(colNext<0 || colNext>=board[0].size())
                continue;
            
            if(board[rowNext][colNext]==word[index] && !visited[rowNext][colNext]) {                
                if(dfs(board, rowNext, colNext, word, index+1, visited))
                    return true;                
            }
        }
        visited[row][col] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int index = 0;
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for(int row = 0; row<rows; row++) {
            for(int col = 0; col<cols; col++) {
                if(board[row][col]==word[index]) {
                    if(dfs(board, row, col, word, index+1, visited))
                        return true;
                }
            }
        }
        return false;
    }
};