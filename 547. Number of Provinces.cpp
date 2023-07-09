class Solution {
private: 

    void dfs(int node, vector<int>adj[], vector<bool>&vis){
        vis[node] = 1; 

        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis); 
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(); 
        
        vector<int>adj[n]; 

        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(isConnected[i][j] == 1 and i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool>vis(n, 0); 
        int cunt(0); 
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                cunt++; 
                dfs(i, adj, vis); 
            }
        }
        return cunt; 
    }
};
