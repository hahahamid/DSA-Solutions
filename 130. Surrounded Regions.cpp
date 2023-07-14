class Solution {
private: 
void dfs(int r, int c, vector<vector<int>>& vis, vector<vector<char>>& board){
    vis[r][c] = 1; 

    int dr[] = {-1, 0, 1, 0}; 
    int dc[] = {0, 1, 0, -1}; 

    int n = board.size(); 
    int m = board[0].size();


    for(int i = 0; i<4; i++){
        int nr = r + dr[i]; 
        int nc = c + dc[i]; 

        if(nr < n and nr >= 0 and nc < m and nc >= 0 and !vis[nr][nc] and board[nr][nc] == 'O'){
            dfs(nr, nc, vis, board); 
        }
    }    
}    
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(); 
        int m = board[0].size();

        vector<vector<int>>vis(n, vector<int>(m, 0)); 

        for(int i = 0; i<n; i++){
            if(!vis[i][0] and board[i][0] == 'O'){
                dfs(i, 0, vis, board); 
            }

            if(!vis[i][m-1] and board[i][m-1] == 'O'){
                dfs(i, m-1, vis, board); 
            }
        } 

        for(int j = 0; j<m; j++){
            if(!vis[0][j] and board[0][j] == 'O'){
                dfs(0, j, vis, board); 
            }
            
            if(!vis[n-1][j] and board[n-1][j] == 'O'){
                dfs(n-1, j, vis, board); 
            }
        }


        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!vis[i][j] and board[i][j] == 'O'){
                    board[i][j] = 'X'; 
                }
            }
        }

    }
};