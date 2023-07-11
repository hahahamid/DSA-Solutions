class Solution {
  private: 
  
    bool dfs(int node, int parent, vector<int> adj[], vector<int> &vis){
        vis[node] = 1; 
        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfs(it, node, adj, vis)) return 1;
            }
            else if(it != parent) return 1; 
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
                if(dfs(i, -1, adj, vis)) return 1; 
            }
        }
        return 0; 
    }
};