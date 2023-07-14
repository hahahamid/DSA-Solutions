class Solution {
private: 
    bool check(int node, int col, vector<vector<int>>&graph, vector<int>&color){
        color[node] = col; 

        for(auto it : graph[node]){
            if(color[it] == -1){
                if(check(it, !col, graph, color) == false) return 0 ; 
            }
            else if(color[it] == color[node]) return 0; 
        }
        return 1; 
    }    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size(); 
        vector<int>color(n, -1);

        for(int i = 0; i<n; i++){
            if(color[i] == -1){
                if(check(i, 0, graph, color) == false) return 0; 
            }
        }
        return 1; 
    }
};