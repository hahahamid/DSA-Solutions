//THESE PROBLEMS NEED TO BE RECONSIDERED !! WATCH STRIVER'S LECTURE AGAIN ASAP 


            // RECURSIVE APPROACH 

class Solution {
public:
    int f(int i , int j, vector<int>&cuts, vector<vector<int>>&dp){
        if(i>j) return 0; 
        
        if(dp[i][j] != -1) return dp[i][j]; 

        int mini = 1e9; 
        for(int idx = i; idx <= j; idx++){
            int cost = cuts[j+1] - cuts[i-1] 
            + f(i, idx-1, cuts, dp) + f(idx+1, j, cuts, dp); 

            mini = min(mini, cost); 
        }
        return dp[i][j] =  mini; 
    }
    int minCost(int n, vector<int>& cuts) {
        vector<vector<int>>dp(cuts.size()+1, vector<int>(cuts.size()+1, -1)); 
        cuts.push_back(n); 
        cuts.insert(cuts.begin(), 0); 
        sort(cuts.begin(), cuts.end()); 
        return f(1, cuts.size()-2, cuts, dp); 
    }
};


              // TABULATION APPROACH 


class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size(); 
        cuts.push_back(n); 
        cuts.insert(cuts.begin(), 0); 
        sort(cuts.begin(), cuts.end()); 
        
        vector<vector<int>>dp(m+3, vector<int>(m+3, 0)); 
        for(int i = m; i>=1; i--){
            for(int j = 1; j<=m; j++){
                if(i>j) continue; 
                int mini = 1e9; 
                for(int idx = i; idx<=j; idx++){
                    int cost = cuts[j+1] - cuts[i-1] + dp[i][idx-1] + dp[idx+1][j]; 
                    mini = min(cost, mini); 
                }
                dp[i][j] = mini; 
            }
        }
        return dp[1][m]; 
    }
};
