class Solution {
  private: 
  
    bool detectCycle(int src, vector<int> adj[], vector<int> &vis){
        vis[src] = 1; 
        queue<pair<int, int>>Q; 
        Q.push({src, -1}); 
        
        while(!Q.empty()){
            int node = Q.front().first; 
            int parent = Q.front().second; Q.pop(); 
            
            for(auto adjacentNode : adj[node]){
                if(!vis[adjacentNode]){
                    vis[adjacentNode] = 1; 
                    Q.push({adjacentNode, node}); 
                }
                else if(parent != adjacentNode){
                    return 1; 
                }
            }
        }
        return 0; 
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int>vis(V, 0); 
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                if(detectCycle(i, adj, vis)) return 1; 
            }
        }
        return 0; 
    }
};