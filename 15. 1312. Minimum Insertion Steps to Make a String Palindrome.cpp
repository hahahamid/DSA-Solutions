// RECURSIVE APPROACH (MEMOIZED)

class Solution {
public:

    int f(int i, int j, string &s, string &t, vector<vector<int>>&dp){
        if(i == 0 or j == 0) return 0; 

        if(dp[i][j] != -1) return dp[i][j]; 

        if(s[i-1] == t[j-1]){
            return dp[i][j] = 1 + f(i-1, j-1, s, t, dp);  
        }
        return dp[i][j] = max(f(i-1, j, s, t, dp), f(i, j-1, s, t, dp)); 
    }

    int minInsertions(string s) {
        int n  = s.size(); 
        string t = s; 
        reverse(t.begin(), t.end()); 
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return n - f(n, n, s, t, dp);
    }
};



// TABULATION APPROACH 


class Solution {
public:
    int minInsertions(string s) {
        int n = s.size(); 
        string t = s; 
        reverse(t.begin(), t.end()); 

        vector<vector<int>>dp(n+1, vector<int>(n+1, 0)); 

        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1]; 
                }
                else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
        return n - dp[n][n]; 
    }
};



// SPACE OPTIMIZED USING TWO 1D ARRAYS 


class Solution {
public:
    int minInsertions(string s) {
        int n = s.size(); 
        string t = s; 
        reverse(t.begin(), t.end()); 

        vector<int>prev(n+1, 0), curr(n+1, 0); 

        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                if(s[i-1] == t[j-1]){
                    curr[j] = 1 + prev[j-1]; 
                }
                else curr[j] = max(curr[j-1], prev[j]);
            }
            prev = curr; 
        }
        return n - prev[n]; 
    }
};
