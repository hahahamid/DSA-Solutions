class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long, long long>> adj[n]; 

        for(auto it : roads){
            adj[it[0]].push_back({it[1], it[2]}); 
            adj[it[1]].push_back({it[0], it[2]});
        }   

        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq; 
        pq.push({0, 0}); 

        vector<long long>dist(n, LONG_MAX); 
        vector<long long>ways(n, 0); 
        dist[0] = 0; 
        ways[0] = 1; 

        int mod = 1e9 + 7; 

        while(!pq.empty()){
            long long distance = pq.top().first; 
            long long node = pq.top().second; 
            pq.pop(); 

            for(auto it : adj[node]){
                long long adjNode = it.first; 
                long long edgeWeight = it.second; 

                if(distance + edgeWeight < dist[adjNode]){
                    dist[adjNode] = distance + edgeWeight; 
                    pq.push({dist[adjNode], adjNode}); 
                    ways[adjNode] = ways[node] % mod; 
                }
                else if(distance + edgeWeight == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod; 
                }
            }
        }

        return ways[n-1] % mod; 
    }
};
