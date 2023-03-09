// Super Similar to N-Queens problems.
// All we had to do extra was to keep a count of the number of possible answers and the rest is just the same 


class Solution {
public: 

    bool isSafe(int row, int col, vector<vector<int>>&board, int n){
        int dcol = col; 
        int drow = row; 

        while(col >= 0 and row >= 0){
            if(board[row][col] == 1) return 0; 
            row--; 
            col--; 
        }

        col = dcol; row = drow; 

        while(col >= 0){
            if(board[row][col] == 1) return 0;
            col--; 
        }

        col = dcol; row = drow; 

        while(row < n and col >= 0){
            if(board[row][col] == 1) return 0; 
            row++; 
            col--; 
        }
        return 1;
    }

    void solve(int col, int n, vector<vector<int>>&board, int &cunt){
        if(col == n){
            cunt++; 
            return ; 
        }

        for(int row = 0; row<n; row++){
            if(isSafe(row, col, board, n)){
                //cunt++; 
                board[row][col] = 1; 
                solve(col+1, n, board, cunt);
                board[row][col] = 0;  
            }
        }

    }

    int totalNQueens(int n) {
        int cunt(0); 
        vector<vector<int>>board(n, vector<int>(n, 0)); 
        solve(0, n, board, cunt); 
        return cunt; 
    }
};
