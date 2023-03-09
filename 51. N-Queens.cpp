
// Basic Backtracking approach 
// All you have to take care of is to check if the block you are placing the Queen is safe or not 
// which means one has to take care of the fact that no Queens attack each other 



class Solution {
public:


    bool isSafe(int row, int col, vector<string>&board, int n){
        int dcol = col; 
        int drow = row;

        while(col >= 0 and row >= 0){
            if(board[row][col] == 'Q') return 0; 
            row--; 
            col--;
        }

        row = drow; col = dcol; 

        while(col >= 0){
            if(board[row][col] == 'Q') return 0 ; 
            col--; 
        }

        col = dcol; row = drow; 

        while(row < n and col >= 0){
            if(board[row][col] == 'Q') return 0; 
            row++; 
            col--; 
        }
        return 1; 
    }

    void solve(int col, int n, vector<string>&board, vector<vector<string>>&ans){
        if(col == n){
            ans.push_back(board); 
            return; 
        }

        for(int row = 0; row<n; row++){
            if(isSafe(row, col, board, n)){
                board[row][col] = 'Q'; 
                solve(col+1, n, board, ans); 
                board[row][col] = '.';    // Tracking Back 
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans; 
        vector<string>board(n);

        string s(n, '.');           // in case of vvi of int one can choose 2D arrays instead 

        for(int i = 0; i<n; i++){
            board[i] = s; 
        }

        solve(0, n, board, ans); 
        return ans;  
    }
};
