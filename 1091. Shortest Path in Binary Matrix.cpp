class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();     
        if(grid[0][0] == 1) return -1;
        if(n == 1) return 1; 

        queue<pair<int, pair<int, int>>> Q; 

        // we use queue instead of priority queue in application of dijkstra
        // only when the change in the distance/quantity is monotonic.
        // as when the change is monotonic, it'll surely give me all the possibilities 
        // in a sorted ascending order .

        vector<vector<int>> dist(n, vector<int> (n, 1e9)); 
        dist[0][0] = 0; 

        Q.push({1, {0, 0}}); // {distance, {row, col}} 

        while(!Q.empty()){
            auto it = Q.front(); Q.pop(); 
            int distance = it.first; 
            int r = it.second.first; 
            int c = it.second.second; 

            for(int i = -1; i<=1; i++){
                for(int j = -1; j<=1; j++){
                    int nr = r + i; 
                    int nc = c + j; 

                    if(nr >= 0 and nr < n and nc >= 0 and nc < n and grid[nr][nc] == 0 and 
                    distance + 1 < dist[nr][nc]){
                        dist[nr][nc] = distance + 1; 
                        if(nr == n-1 and nc == n-1) return dist[nr][nc] ;
                        Q.push({dist[nr][nc], {nr, nc}}); 
                    }
                }
            }
        }

        return -1; 

    }
};
