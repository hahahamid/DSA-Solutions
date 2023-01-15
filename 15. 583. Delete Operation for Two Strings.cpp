// CAN OBVIOSULY BE DONE USING THE RECURSIVE APPROACH AS WELL BUT OKAY ;)


// TABULATION APPROACH 


class Solution {
public:
    int minDistance(string s, string t) {
        int n = s.size();
	    int m = t.size();
	    
	    vector<vector<int>>dp(n+1, vector<int>(m+1, 0)); 
	    for(int i = 1; i<=n; i++){
	        for(int j = 1; j<=m; j++){
	            if(s[i-1]==t[j-1]){
	                dp[i][j] = 1 + dp[i-1][j-1]; 
	            }
	            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]); 
	        }
	    }
	    return n+m-2*dp[n][m]; 
    }
};



// SPACE OPTIMIZED USING TWO 1D ARRAYS 


class Solution {
public:
    int minDistance(string s, string t) {
        int n = s.size();
	    int m = t.size();
	    
	    vector<int>prev(m+1, 0), curr(m+1, 0); 
	    for(int i = 1; i<=n; i++){
	        for(int j = 1; j<=m; j++){
	            if(s[i-1]==t[j-1]){
	                curr[j] = 1 + prev[j-1]; 
	            }
	            else curr[j] = max(curr[j-1], prev[j]); 
	        }
            prev = curr;
	    }
	    return n+m-2*prev[m]; 
    }
};
