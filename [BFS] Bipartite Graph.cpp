class Solution {
public:

    bool check(int start, int n, vector<vector<int>>& graph, vector<int>&color){
        color[start] = 0; 
        queue<int>Q; 
        Q.push(start); 

        while(!Q.empty()){
            int node = Q.front(); Q.pop(); 

            for(auto it : graph[node]){
                if(color[it] == -1){
                    color[it] = !color[node]; 
                    Q.push(it);   
                }
                else if(color[it] == color[node]) return 0; 
            }
        }
        return 1; 
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n, -1); 
        for(int i = 0; i<n; i++){
            if(color[i] == -1){
                if (check(i, n, graph, color) == false)  return 0; 
            }
        }
        return 1; 
    }
};