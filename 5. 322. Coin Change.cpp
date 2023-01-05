// Basic DP on subsets/subsquence approach 
// Make use of pick and notPick technique 

// Learn one row space optimization and add the code sooner or later. 


//  Using Ternany Operator can actually make your code slow, avoid using the same. Use the basic if else statement. 



// Recursion + Memoization 

int f(int idx, int tar, vector<int> &nums, vector<vector<int>>&dp){
    if(idx == 0){
        if(tar%nums[0] == 0){
            return tar/nums[0]; 
        }
        else return 1e9; 
    }
    
    if(dp[idx][tar] != -1) return dp[idx][tar]; 
    
    int nottake = 0 + f(idx-1, tar, nums, dp); 
    int take = 1e9; 
    if(nums[idx] <= tar) take = 1 + f(idx, tar - nums[idx], nums, dp); 
    
    return dp[idx][tar] = min(take, nottake); 
    
    
}

int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    int n = num.size(); 
    vector<vector<int>>dp(n, vector<int>(x+1, -1)); 
    int ans = f(n-1, x, num, dp); 
    
    return (ans>=1e9) ? -1 : ans; 
}





// Tabulation 

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(), vector<int>(amount+1, 0)); 

        for(int i = 0; i<=amount; i++){
            if(i%coins[0] == 0) {
                dp[0][i] = i/coins[0]; 
            }
            else dp[0][i] = 1e9; 
        }

        for(int i = 1; i<coins.size(); i++){
            for(int j = 0; j<=amount; j++){
                int notTake = 0 + dp[i-1][j]; 
                int take = 1e9; 
                if(coins[i] <= j) take = 1+dp[i][j-coins[i]]; 

                dp[i][j] = min(take, notTake); 
            }
        }
        int ans = dp[coins.size()-1][amount];

        if(ans >= 1e9) return -1; 
        else return ans;  
    }
};






// Two Rows Space Optimization 

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>prev(amount+1, 0), curr(amount+1, 0); 

        for(int i = 0; i<=amount; i++){
            if(i%coins[0] == 0) {
                prev[i] = i/coins[0]; 
            }
            else prev[i] = 1e9; 
        }

        for(int i = 1; i<coins.size(); i++){
            for(int j = 0; j<=amount; j++){
                int notTake = 0 + prev[j]; 
                int take = 1e9; 
                if(coins[i] <= j) take = 1+ curr[j-coins[i]]; 

                curr[j] = min(take, notTake); 
            }
            prev = curr; 
        }
        int ans = prev[amount];

        if(ans >= 1e9) return -1; 
        else return ans;  
    }
};



// One row Space Optimization 
