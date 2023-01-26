// TYPICAL PARTITION DP PROBLEM BUT ONE HAS TO TAKE CARE OF THE FUNCTION CALLS IN RECURSIVE APPROACH AND THE RANGE OF "FOR LOOPS" IN THE TABULATION APPROACH 


          // RECURSIVE APPROACH


class Solution {
public:
    int f(int i, int j, vector<int>&nums, vector<vector<int>>&dp){
        if(i>j) return 0;   

        if(dp[i][j] != -1) return dp[i][j]; 

        int ans = -1e9; 
        for(int k = i; k<=j; k++){
            int coins = nums[j+1] * nums[i-1] * nums[k] + f(i, k-1, nums, dp) + f(k+1, j, nums, dp); 
            ans = max(ans, coins);  
        }
        return dp[i][j] = ans; 
    }
    
    int maxCoins(vector<int>& nums) {
        nums.push_back(1); 
        nums.insert(nums.begin(), 1); 
        int n = nums.size(); 
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1)); 
        
        return f(1, n-2, nums, dp); 
    }
};


          // TABULATION APPROACH 


class Solution {
public:    
    int maxCoins(vector<int>& arr) {
        int n = arr.size(); 
        arr.push_back(1); 
        arr.insert(arr.begin(), 1); 
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0)); 
        
        for(int i = n; i>=1; i--){
            for(int j = 1; j<=n; j++){
                if(i>j) continue; 
                int maxi = -1e9; 
    
                for(int idx = i; idx<=j; idx++){
                int cost = arr[i-1] * arr[idx] * arr[j+1] + dp[i][idx-1] + dp[idx+1][j]; 
        
                maxi = max(maxi, cost); 
                }
                dp[i][j] = maxi ;
            }
        }
        return dp[1][n]; 
    }
};
