// The simplest approach would be to generate all the subsequences and just find out the LCS, 
// but it will require exponential time

// Instead we will generate all subsequences using recursion and in the recursive logic we will figure out a way to solve this problem.
// The logic being if at both the indices the character is same we add one to the result and check for the rest while going one index back in both the strings
// And if that condition is not satisfied, then we'll take the max of both the remaining possibilities. 

// Keep an eye on the sharp edge case. We'll shift the indices further in order to resist it to become -1. 




// Recursive Approach (Memoization)


class Solution {
public:
    int f(int i, int j, string &text1, string &text2, vector<vector<int>>&dp){
        if(i == 0 or j == 0) return 0; 

        if(dp[i][j] != -1) return dp[i][j]; 
        if(text1[i-1] == text2[j-1]){
            return dp[i][j] = 1 + f(i-1, j-1, text1, text2, dp); 
        }
        return dp[i][j] = max(f(i-1, j, text1, text2, dp), f(i, j-1, text1, text2, dp)); 
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(); 
        int m = text2.length(); 
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1)); 
        return f(n, m, text1, text2, dp); 
    }
};


// Tabulation Approach 


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(); 
        int m = text2.size(); 
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0)); 

        for(int i = 0; i<=n; i++){ dp[i][0] = 0; }
        for(int j = 0; j<=m; j++){dp[0][j] = 0; }
        
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1]; 
                }
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]); 
            }
        }
        return dp[n][m]; 
    }
};


// Tabulation using 2D array instead of 2D vector (somehow faster lol)


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int dp[text1.size()+1][text2.size()+1];
        for(int i=0;i<=text1.size();i++)
        {
            for(int j=0;j<=text2.size();j++)
            {
                if(i==0 || j==0)
                    dp[i][j]=0;
                else
                {
                    if(text1[i-1]==text2[j-1])
                        dp[i][j]=1+dp[i-1][j-1];
                    else
                        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }
};


// Space Optimization Approach (two 1D arrays keeping the rows in track only)


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(); 
        int m = text2.size(); 
        vector<int>prev(m+1, 0), curr(m+1, 0); 

        for(int i = 0; i<=n; i++){ prev[0] = 0; }        
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(text1[i-1] == text2[j-1]){
                    curr[j] = 1 + prev[j-1]; 
                }
                else curr[j] = max(prev[j], curr[j-1]); 
            }
            prev = curr; 
        }
        return prev[m]; 
    }
};
