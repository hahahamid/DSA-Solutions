class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {

        vector<int>adj[n]; 
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]); 
        }

        vector<int>indegree(n, 0); 

        for(int i = 0 ; i<n; i++){
            for(auto it : adj[i]){
                indegree[it]++; 
            }
        }

        queue<int>Q; 
        for(int i = 0; i<n; i++){
            if(indegree[i] == 0) Q.push(i);
        }
        
        vector<int>ans; 

        while(!Q.empty()){
            int node = Q.front(); Q.pop(); 

            ans.push_back(node); 

            for(auto it : adj[node]){
                indegree[it]--; 

                if(indegree[it] == 0) Q.push(it); 
            }
        }

        if(ans.size() == n) return ans; 
        return {};
    }
};
