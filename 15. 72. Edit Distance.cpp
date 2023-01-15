// RECURSIVE APPROACH (MEMO)


class Solution {
public:

    int f(int i, int j, string &s, string &t, vector<vector<int>>&dp){
        if(j == 0) return i; 
        if(i == 0) return j; 

        if(dp[i][j] != -1) return dp[i][j]; 

        if(s[i-1] == t[j-1]){
            return dp[i][j] = f(i-1, j-1, s, t, dp); 
        }
        return dp[i][j] = 1 + min(f(i-1, j-1,s,t,dp), min(f(i-1,j,s,t,dp), f(i, j-1, s, t, dp))); 
    }

    int minDistance(string s, string t) {
        int n = s.size(); 
        int m = t.size(); 
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1)); 
        return f(n, m, s, t, dp); 
    }
};



// TABULATION APPROACH 


class Solution {
public:
    int minDistance(string s, string t) {
        int n = s.size(); 
        int m = t.size(); 
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0)); 
        
        for(int j = 0; j<=n; j++){
            dp[j][0] = j; 
        }
        for(int i = 0; i<=m; i++){
            dp[0][i] = i; 
        }

        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1]; 
                }
                else{
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])); 
                }
            }
        }
        return dp[n][m]; 
    }
};




// SPACE OPTIMIZED USING TWO 1D ARRAYS 




class Solution {
public:
    int minDistance(string s, string t) {
        int n = s.size(); 
        int m = t.size(); 
        vector<int>prev(m+1, 0), curr(m+1, 0); 

        for(int j = 0; j<=m; j++){
            prev[j] = j; 
        }

        for(int i = 1; i<=n; i++){
            curr[0] = i; 
            for(int j = 1; j<=m; j++){
                if(s[i-1] == t[j-1]){
                    curr[j] = prev[j-1]; 
                }
                else{
                    curr[j] = 1 + min(prev[j-1], min(prev[j], curr[j-1])); 
                }
            }
            prev = curr; 
        }
        return prev[m]; 
    }
};
