// very similar to almost all the basic BFS problems a
// and no one cannot use DFS in this case as DFS will traverse to all the connected oranges at a time, 
// instead we want to know the minimum amount of time, knowing the fact that it takes unit time to rot the connected node which is at a distance of 1 either left or right or up or down, 
// thus we use BFS ...  


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size(); 

        vector<vector<int>>vis(n, vector<int>(m, 0)); 

        queue<pair<pair<int,int>, int>> Q; 

        int cntFresh(0); 

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 2){
                    Q.push({{i, j}, 0}); 
                    vis[i][j] = 2; 
                }
                if(grid[i][j] == 1) cntFresh++; 
            }
        }


        int dr[] = {-1, 0, 1, 0}; 
        int dc[] = {0, 1, 0, -1}; 

        int cnt(0);
        int ans(0); 

        while(!Q.empty()){
            int r = Q.front().first.first; 
            int c = Q.front().first.second; 
            int t = Q.front().second; 
            Q.pop(); 

            ans = max(ans, t); 


            for(int i = 0; i<4; i++){
                int nr = r + dr[i];  
                int nc = c + dc[i]; 

                if(nr >= 0 and nr < n and nc >=0 and nc<m and grid[nr][nc] == 1 and vis[nr][nc] != 2){
                    Q.push({{nr, nc}, t+1}); 
                    vis[nr][nc] = 2; 
                    cnt++; 
                }
            }
        }

        if(cnt != cntFresh) return -1; 
        return ans;  

    }
};

