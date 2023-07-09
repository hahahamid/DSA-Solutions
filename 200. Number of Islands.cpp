class Solution {

private: 

    void bfs(int row, int col, vector<vector<int>>&vis, vector<vector<char>>& grid){
        vis[row][col] = 1; 
        queue<pair<int, int>> Q; 
        Q.push({row, col}); 

        int n = grid.size(); 
        int m = grid[0].size(); 


        // if only horizontally and vertically adjacent blocks are to be considered,
        // then we will use this method 
      
        int dr[] = {-1, 0, 1, 0}; 
        int dc[] = {0, 1, 0, -1}; 

        while(!Q.empty()){
            int row = Q.front().first;  
            int col = Q.front().second;
            Q.pop();
          
            // and traverse like this in case of 4 directions are allowed  
            for(int i = 0; i<4; i++){
                    int nrow = row + dr[i]; 
                    int ncol = col + dc[i]; 

                    if(nrow >= 0 and nrow < n and ncol >=0 and ncol < m and grid[nrow][ncol] == '1' and !vis[nrow][ncol]){
                        vis[nrow][ncol] = 1; 
                        Q.push({nrow, ncol}); 
                        }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size();


        vector<vector<int>>vis(n, vector<int>(m, 0));
        int cnt(0);  
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!vis[i][j] and grid[i][j] == '1'){
                    cnt++; 
                    bfs(i, j, vis, grid); 
                }
            }
        } 
        return cnt; 
    }
};





// In case of alll horizontally or vertically or diagonally i.e., in all 8 directions are allowed 



private: 

    void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid){
        vis[row][col] = 1; 
        
        queue<pair<int, int>>Q; 
        Q.push({row, col}); 
        
        int n = grid.size(); 
        int m = grid[0].size(); 
        
        while(!Q.empty()){
            int row = Q.front().first; 
            int col = Q.front().second;
            Q.pop(); 


          // this will traverse 9 times (8 times to be precise, as in case of (0, 0), it will already be visited) 
          // this technique takes care of all the 8 directions 
            for(int delrow = -1; delrow <=1; delrow++){
            for(int delcol = -1; delcol <=1; delcol++){
                int nrow = row + delrow; 
                int ncol = col + delcol; 
                
                if(nrow >= 0 and ncol >=0 and nrow < n and ncol <m and grid[nrow][ncol] == '1' and !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1; 
                    Q.push({nrow, ncol}); 
                    }
                }
            }
            
        }
        
        
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size(); 
        int m = grid[0].size(); 
        
        vector<vector<int>> vis(n, vector<int>(m, 0)); 
        int cnt(0); 
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!vis[i][j] and grid[i][j] == '1'){
                    cnt++;
                    bfs(i, j, vis, grid); 
                }
            }
        }
        return cnt; 
    }
};

