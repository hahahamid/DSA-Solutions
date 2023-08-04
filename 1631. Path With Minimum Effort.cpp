class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(); 
        int m = heights[0].size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>>diff(n, vector<int>(m, 1e9)) ; 

        diff[0][0] = 0; 
        pq.push({0, {0, 0}}); 


        int dr[] = {-1, 0, 1, 0}; 
        int dc[] = {0, 1, 0, -1}; 

        while(!pq.empty()){
            auto it = pq.top(); pq.pop(); 

            int difference = it.first; 
            int r = it.second.first; 
            int c = it.second.second; 

            if(r == n-1 and c == m-1) return difference; 

            for(int i = 0; i<4; i++){
                int nr = r + dr[i]; 
                int nc = c + dc[i]; 

                if(nr >= 0 and nr < n and nc >= 0 and nc < m){
                    int newEffort = max(abs(heights[r][c] - heights[nr][nc]), difference); 

                    if(newEffort < diff[nr][nc]){
                        diff[nr][nc] = newEffort; 

                        pq.push({newEffort, {nr, nc}}); 
                    }
                }
            }
        }

        return 0; 
    }
};
