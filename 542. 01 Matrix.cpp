class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(); 
        int m = mat[0].size(); 

        vector<vector<int>>vis(n, vector<int>(m, 0)); 
        vector<vector<int>>ans(n, vector<int>(m, 0));


        queue<pair<pair<int, int>, int>> Q;  

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j] == 0){
                    Q.push({{i, j}, 0}); 
                    vis[i][j] = 1; 
                }
            }
        }


        while(!Q.empty()){
            int r = Q.front().first.first; 
            int c = Q.front().first.second; 
            int steps = Q.front().second;
            Q.pop(); 
            ans[r][c] = steps; 

            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1}; 

            for(int i = 0; i<4; i++){
                int nr = r + dr[i]; 
                int nc = c + dc[i]; 

                if(nr < n and nr >= 0 and nc < m and nc >= 0 and vis[nr][nc] != 1){
                    Q.push({{nr, nc}, steps+1}); 
                    vis[nr][nc] = 1; 
                }
            }

        }
        return ans; 
    }
};