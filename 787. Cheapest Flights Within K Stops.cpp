class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n]; 

        for(auto it : flights){
            adj[it[0]].push_back({it[1], it[2]}); 
        }

        queue<pair<int, pair<int, int>>> Q; 
        Q.push({0, {src, 0}}); 

        vector<int>dist(n, 1e9); 
        dist[src] = 0; 

        while(!Q.empty()){
            auto it = Q.front(); Q.pop(); 

            int stops = it.first; 
            int node = it.second.first; 
            int cost = it.second.second; 

            if(stops > k) continue; 
            for(auto it : adj[node]){
                int adjNode = it.first; 
                int travelCost = it.second; 

                if(cost + travelCost < dist[adjNode] and stops <= k){
                    dist[adjNode] = cost + travelCost; 
                    Q.push({stops+1, {adjNode, dist[adjNode]}}); 
                }
            }
        }
        if(dist[dst] == 1e9) return -1; 
        return dist[dst]; 
    }
};
