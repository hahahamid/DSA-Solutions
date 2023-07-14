// bfs 


class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();   
        int m = grid[0].size(); 

        vector<vector<int>>vis(n, vector<int>(m, 0)); 
        queue<pair<int, int>>Q; 

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(i == 0 or j == 0 or i == n-1 or j == m-1){
                    if(grid[i][j] == 1){
                        Q.push({i, j});
                        vis[i][j] = 1; 
                    }
                }
            }
        }

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};  


        while(!Q.empty()){
            int r = Q.front().first; 
            int c = Q.front().second;
            Q.pop(); 

            for(int i = 0; i<4; i++){
                int nr = r + dr[i]; 
                int nc = c + dc[i]; 

                if(nr < n and nr >= 0 and nc < m and nc >= 0 
                and grid[nr][nc] == 1 and !vis[nr][nc]){
                    Q.push({nr, nc}); 
                    vis[nr][nc] = 1; 
                }
            }
        }

        int cunt(0); 
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1 and !vis[i][j]){
                    cunt++; 
                }
            }
        }
        return cunt; 
    }
};




// dfs 

class Solution {
public:
    void dfs(vector<vector<int>>& grid,int i,int j,int m,int n){
        if(i<0 || i >=m || j<0 || j>=n || grid[i][j] == 0 || grid[i][j] == 2) return;
        grid[i][j] = 2;
        int ai[] = {0,1,0,-1};
        int aj[] = {1,0,-1,0};

        for(int k=0;k<4;k++){
            dfs(grid,i+ai[k],j+aj[k],m,n);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for(int i=0;i<m;i++){
            dfs(grid,i,0,m,n);
            dfs(grid,i,n-1,m,n);
        }
        for(int i=0;i<n;i++){
            dfs(grid,0,i,m,n);
            dfs(grid,m-1,i,m,n);
        }

        int count = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) count++;
            }
        }

        return count;
    }
};