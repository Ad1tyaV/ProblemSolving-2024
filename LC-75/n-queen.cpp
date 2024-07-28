class Solution {
public:
    vector<vector<string>> solvedBoard;    
    bool validity(vector<string>& board, int row, int col, int n) {
        int count = 0;
        // Check Vertically
        for(int i=0; i<n; i++) {
            if(board[row][i]=='Q') {
                count++;
                if(count>1)
                    return false;
            }
        }

        count = 0;

        // Check Horizontally
        for(int i=0; i<n; i++) {
            if(board[i][col]=='Q') {
                count++;
                if(count>1)
                    return false;
            }
        }

        int x = row-1;
        int y = col-1;
        // Check Diagonally up-left
        while(x>=0 && y>=0) {
            if(board[x][y] == 'Q')
                return false;
            x--;
            y--;
        }

        x = row+1;
        y = col+1;

        // Check Diagonally down-right
        while(x<n && y<n) {
            if(board[x][y] == 'Q')
                return false;
            x++;
            y++;
        }

        x = row+1;
        y = col-1;

        // Check Diagonally down-left
        while(x<n && y>=0) {
            if(board[x][y]=='Q')
                return false;
            x++;
            y--;
        }

        x = row-1;
        y = col+1;

        // Check Diagonally up-right
        while(x>=0 && y<n) {
            if(board[x][y]=='Q')
                return false;
            x--;
            y++;
        }

        return true;
    }
    
    void recurse(vector<string>& board, int row, int n) {        
        if(row==n) {
            solvedBoard.push_back(board);
            return;
        }
        for(int i=0; i<n; i++) {
            board[row][i] = 'Q';
            if(!validity(board, row, i, n)) {
                board[row][i] = '.';
                continue;
            }
            recurse(board, row+1, n);
            board[row][i] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        if(n==2)    return {};
        if(n==1) return {{"Q"}};

        vector<string> board(n, string(n, '.'));
        
        recurse(board, 0, n);

        return solvedBoard;
    }
};