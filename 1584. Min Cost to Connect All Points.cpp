class Solution {
public:

    int optimalDistance(vector<int>&v1, vector<int>&v2){
        return abs(abs(v1[0]-v2[0]) + abs(v1[1] - v2[1])); 
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(); 
        vector<pair<int, int>> adj[n]; 

        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                adj[i].push_back({j, optimalDistance(points[i], points[j])}); 
                adj[j].push_back({i, optimalDistance(points[i], points[j])}); 
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
        vector<int> vis(n, 0); 

        pq.push({0, 0}); 
        int sum(0); 
        while(!pq.empty()){
            auto it = pq.top(); pq.pop(); 
            int node = it.second; 
            int wt = it.first; 

            if(vis[node]) continue; 
            vis[node] = 1; 

            sum += wt; 

            for(auto it : adj[node]){
                int adjNode = it.first; 
                int edgW = it.second; 
                
                if(!vis[adjNode]){
                    pq.push({edgW, adjNode}); 
                }
            }
        }
    return sum ; 
    }
};
